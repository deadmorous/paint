#include "brushpreviewwidget.h"

#include <QPainter>

BrushPreviewWidget::BrushPreviewWidget(QWidget *parent) :
    QWidget(parent),
    m_brushDiameter(0)
{
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setMinimumSize(22, 22);
}

void BrushPreviewWidget::setBrushDiameter(double brushDiameter)
{
    m_brushDiameter = brushDiameter;
    update();
}

void BrushPreviewWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    // p.fillRect(rect(), Qt::white);
    if (m_brushDiameter <= 0)
        return;
    p.setRenderHint(QPainter::Antialiasing);
    p.setBrush(Qt::black);
    p.setPen(Qt::NoPen);
    double r = 0.5*m_brushDiameter;
    p.drawEllipse(QPointF(rect().center()), r, r);
}
