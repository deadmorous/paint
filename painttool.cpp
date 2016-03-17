#include "painttool.h"
#include "canvas.h"

PaintTool::PaintTool(QObject *parent) :
    QObject(parent),
    m_canvas(nullptr),
    m_active(false)
{
}

Canvas *PaintTool::canvas() const {
    return m_canvas;
}

bool PaintTool::isActive() const {
    return m_active;
}

void PaintTool::setCanvas(Canvas *canvas) {
    if (m_canvas && m_active)
        m_canvas->removeEventFilter(this);
    m_canvas = canvas;
    if (m_canvas && m_active)
        m_canvas->installEventFilter(this);
}

void PaintTool::setActive(bool active)
{
    if (m_active == active)
        return;
    m_active = active;
    Q_ASSERT(m_canvas);
    QWidget *setupWidget = toolSetupWidget();
    if (active) {
        m_canvas->installEventFilter(this);
        if (setupWidget)
            setupWidget->show();
    }
    else {
        m_canvas->removeEventFilter(this);
        if (setupWidget)
            setupWidget->hide();
    }
}
