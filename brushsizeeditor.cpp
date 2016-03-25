#include "brushsizeeditor.h"
#include "brushpreview.h"
#include <QSlider>
#include <QHBoxLayout>

BrushSizeEditor::BrushSizeEditor(QWidget *parent) : QWidget(parent)
{
    auto layout = new QHBoxLayout(this);
    layout->addWidget(m_preview = new BrushPreview);
    m_slider = new QSlider(Qt::Horizontal);
    m_slider->setMaximumWidth(100);
    m_slider->setMinimum(1);
    m_slider->setMaximum(20);
    layout->addWidget(m_slider);
    layout->addStretch();
    m_slider->setSliderPosition(5);
    m_preview->setBrushDiameter(5);

    connect(m_slider, SIGNAL(sliderMoved(int)),
            m_preview, SLOT(setBrushDiameter(int)));
}

double BrushSizeEditor::brushDiameter() const
{
    return m_slider->sliderPosition();
}
