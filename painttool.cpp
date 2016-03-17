#include "painttool.h"
#include "canvas.h"

PaintTool::PaintTool(QObject *parent) :
    QObject(parent),
    m_canvas(nullptr)
{
}

void PaintTool::activate(Canvas *canvas)
{
    Q_ASSERT(!m_canvas);
    canvas->installEventFilter(this);
    m_canvas = canvas;
    QWidget *setupWidget = toolSetupWidget();
    if (setupWidget)
        setupWidget->show();
}

void PaintTool::deactivate()
{
    Q_ASSERT(m_canvas);
    m_canvas->removeEventFilter(this);
    m_canvas = nullptr;
    QWidget *setupWidget = toolSetupWidget();
    if (setupWidget)
        setupWidget->hide();
}

Canvas *PaintTool::canvas()
{
    return m_canvas;
}
