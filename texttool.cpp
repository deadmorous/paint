#include "texttool.h"
#include "canvas.h"

#include <QAction>
#include <QIcon>
#include <QMouseEvent>
#include <QPainter>

DECL_PAINT_TOOL_REGISTRATOR(TextTool)

TextTool::TextTool(QObject *parent) : PaintTool(parent)
{
    m_toolAction = new QAction(QIcon(":/pix/text.png"), tr("Text"), this);
    m_toolSetupWidget = 0;
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
    case QEvent::MouseMove:
    {
        auto mouseEvent = static_cast<QMouseEvent *>(event);
        CanvasPixmap pix(canvas());
        QPainter p(pix);
        QPen pen(Qt::black, 18);
        pen.setCapStyle(Qt::RoundCap);
        p.setPen(pen);
        p.setRenderHint(QPainter::Antialiasing);
        p.drawLine(m_lastPos, mouseEvent->pos());
        m_lastPos = mouseEvent->pos();
        break;
    }
    }
    return false;
}
