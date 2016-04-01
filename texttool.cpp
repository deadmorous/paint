#include "texttool.h"
#include "canvas.h"
#include "texttoolsetup.h"
#include "scopedinc.h"

#include <QAction>
#include <QIcon>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainter>
#include <QCoreApplication>

DECL_PAINT_TOOL_REGISTRATOR(TextTool)

TextTool::TextTool(QObject *parent) : PaintTool(parent),
    m_efCounter(0)
{
    m_toolAction = new QAction(QIcon(":/pix/text.png"), tr("Text"), this);
    m_toolSetupWidget = new TextToolSetup;
}

QAction *TextTool::toolAction() {
    return m_toolAction;
}

QWidget *TextTool::toolSetupWidget() {
    return m_toolSetupWidget;
}

bool TextTool::eventFilter(QObject* watched, QEvent *event)
{
    if (m_efCounter > 0)
        return false;
    ScopedInc scinc(m_efCounter);
    if (watched != canvas())
        return false;
    switch (event->type())
    {
    case QEvent::MouseButtonPress:
    {
        auto mouseEvent = static_cast<QMouseEvent *>(event);
        m_lastPos = mouseEvent->pos();
        break;
    }
    case QEvent::KeyPress:
    {
        auto keyEvent = static_cast<QKeyEvent*>(event);
        CanvasPixmap pix(canvas());
        QPainter p(pix);
        p.setPen(m_toolSetupWidget->textColor());
        p.setFont(m_toolSetupWidget->textFont());
        p.drawText(m_lastPos, keyEvent->text());
        const int Large = 1000;
        m_lastPos.rx() +=
                p.boundingRect(QRect(0,0,Large, Large),
                               keyEvent->text()).width();
        break;
    }
    case QEvent::Paint:
    {
        qApp->notify(canvas(), event);
        QPainter p(canvas());
        p.fillRect(10, 10, 20, 30, Qt::green);
        return true;
    }
    default:
        break;
    }
    return false;
}
