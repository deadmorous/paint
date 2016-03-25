#include "brushtool.h"
#include "canvas.h"
#include "brushtoolsetup.h"

#include <QAction>
#include <QIcon>
#include <QMouseEvent>
#include <QPainter>

DECL_PAINT_TOOL_REGISTRATOR(BrushTool)

BrushTool::BrushTool(QObject *parent) : PaintTool(parent)
{
    m_toolAction = new QAction(QIcon(":/pix/brush.png"), tr("Brush"), this);
    m_toolSetupWidget = new BrushToolSetup;
}

QAction *BrushTool::toolAction() {
    return m_toolAction;
}

QWidget *BrushTool::toolSetupWidget() {
    return m_toolSetupWidget;
}

bool BrushTool::eventFilter(QObject* watched, QEvent *event)
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
        QPen pen(m_toolSetupWidget->brushColor(),
                 m_toolSetupWidget->brushDiameter());
        pen.setCapStyle(Qt::RoundCap);
        p.setPen(pen);
        p.setRenderHint(QPainter::Antialiasing);
        p.drawLine(m_lastPos, mouseEvent->pos());
        m_lastPos = mouseEvent->pos();
        break;
    }
    default:
        break;
    }
    return false;
}
