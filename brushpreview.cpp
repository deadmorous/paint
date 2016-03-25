#include "brushpreview.h"
#include <QPainter>

BrushPreview::BrushPreview(QWidget *parent) :
    QWidget(parent),
    m_brushDiameter(0)
{
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setMinimumSize(22, 22);
}

void BrushPreview::setBrushDiameter(int brushDiameter)
{
    setBrushDiameter(static_cast<double>(brushDiameter));
}

void BrushPreview::setBrushDiameter(double brushDiameter)
{
    m_brushDiameter = brushDiameter;
    update();
}

void BrushPreview::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.setRenderHint(QPainter::Antialiasing);
    double r = 0.5*m_brushDiameter;
    p.drawEllipse(QPointF(rect().center()), r, r );
}
