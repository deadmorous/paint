#include "brushtool.h"
#include "canvas.h"
#include "brushtoolsetupwidget.h"

#include <QAction>
#include <QIcon>
#include <QMouseEvent>
#include <QPainter>

DECL_PAINT_TOOL_REGISTRATOR(BrushTool)

BrushTool::BrushTool(QObject *parent) :
    PaintTool(parent)
{
    m_toolAction = new QAction(QIcon(":/pix/brush.png"), tr("Brush"), this);
    m_toolSetupWidget = new BrushToolSetupWidget;
    m_toolSetupWidget->hide();
}

QAction *BrushTool::toolAction()
{
    return m_toolAction;
}

QWidget *BrushTool::toolSetupWidget()
{
    return m_toolSetupWidget;
}

bool BrushTool::eventFilter(QObject *watched, QEvent *event)
{
    if (watched != canvas())
        return false;
    switch(event->type()) {
    case QEvent::MouseButtonPress: {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        m_lastPos = mouseEvent->pos();
        break;
    }
    case QEvent::MouseMove: {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        CanvasPixmap cpix(canvas());
        QPainter p(cpix);
        QPen pen(m_toolSetupWidget->brushColor(), 18);
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
