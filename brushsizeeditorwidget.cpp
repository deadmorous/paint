#include "brushsizeeditorwidget.h"

#include "brushpreviewwidget.h"
#include <QHBoxLayout>
#include <QSlider>

BrushSizeEditorWidget::BrushSizeEditorWidget(QWidget *parent) :
    QWidget(parent),
    m_brushDiameter(3)
{
    auto layout = new QHBoxLayout(this);
    layout->setMargin(0);
    layout->addWidget(m_brushPreview = new BrushPreviewWidget);
    m_brushPreview->setBrushDiameter(m_brushDiameter);
    auto slider = new QSlider(Qt::Horizontal);
    slider->setMinimum(0);
    slider->setMaximum(100);
    slider->setMaximumWidth(200);
    slider->setSliderPosition(static_cast<int>(100*(m_brushDiameter-1) / (20-1)));
    layout->addWidget(slider);
    layout->addStretch();
    connect(slider, SIGNAL(sliderMoved(int)), SLOT(sliderMoved(int)));
}

double BrushSizeEditorWidget::brushDiameter() const
{
    return m_brushDiameter;
}

void BrushSizeEditorWidget::sliderMoved(int position)
{
    const double BrushMinDiameter = 1;
    const double BrushMaxDiameter = 20;
    double t = 0.01*position;
    m_brushDiameter = BrushMinDiameter*(1-t) + BrushMaxDiameter*t;
    m_brushPreview->setBrushDiameter(m_brushDiameter);
    emit brushDiameterChanged(m_brushDiameter);
}
