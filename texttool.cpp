#include "texttool.h"
#include "canvas.h"
#include "texttoolsetup.h"

#include <QAction>
#include <QIcon>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainter>

DECL_PAINT_TOOL_REGISTRATOR(TextTool)

TextTool::TextTool(QObject *parent) : PaintTool(parent)
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
        p.drawText(m_lastPos, keyEvent->text());
        const int Large = 1000;
        m_lastPos.rx() +=
                p.boundingRect(QRect(0,0,Large, Large),
                               keyEvent->text()).width();
        break;
    }
    default:
        break;
    }
    return false;
}
