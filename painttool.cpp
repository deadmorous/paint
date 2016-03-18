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

void PaintTool::setCanvas(Canvas* canvas)
{
    if (canvas == m_canvas)
        return;
    bool wasActive = m_active;
    setActive(false);
    m_canvas = canvas;
    if (wasActive)
        setActive(true);
}

void PaintTool::setActive(bool active)
{
    if (active == m_active)
        return;
    m_active = active;
    QWidget *setupWidget = toolSetupWidget();
    if (setupWidget)
        setupWidget->setVisible(active);
    if (m_canvas)
    {
        if (active)
            m_canvas->installEventFilter(this);
        else
            m_canvas->removeEventFilter(this);
    }
}
