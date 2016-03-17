#include "texttool.h"
#include "canvas.h"

#include <QAction>
#include <QIcon>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainter>

DECL_PAINT_TOOL_REGISTRATOR(TextTool)

TextTool::TextTool(QObject *parent) :
    PaintTool(parent),
    m_hasLastPos(false)
{
    m_toolAction = new QAction(QIcon(":/pix/text.png"), tr("Brush"), this);
    m_toolSetupWidget = nullptr;
}

QAction *TextTool::toolAction()
{
    return m_toolAction;
}

QWidget *TextTool::toolSetupWidget()
{
    return m_toolSetupWidget;
}

void TextTool::onActivate() {
    m_hasLastPos = false;
}

bool TextTool::eventFilter(QObject *watched, QEvent *event)
{
    if (watched != canvas())
        return false;
    switch(event->type()) {
    case QEvent::MouseButtonPress: {
        auto mouseEvent = static_cast<QMouseEvent*>(event);
        m_lastPos = mouseEvent->pos();
        m_hasLastPos = true;
        break;
    }
    case QEvent::KeyPress: {
        if (!m_hasLastPos)
            break;
        auto keyEvent = static_cast<QKeyEvent*>(event);
        CanvasPixmap cpix(canvas());
        QPainter p(cpix);
        QString text = keyEvent->text();
        p.drawText(m_lastPos, text);
        int BigSize = 1000;
        m_lastPos.rx() += p.boundingRect(QRectF(0, 0, BigSize, BigSize), text).width();
        break;
    }
    }
    return false;
}
