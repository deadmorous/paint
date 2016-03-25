#include "brushtoolsetup.h"

#include <QHBoxLayout>
#include <QToolBar>
#include "colorpickeraction.h"
#include "brushsizeeditor.h"

BrushToolSetup::BrushToolSetup(QWidget *parent) : QWidget(parent)
{
    auto layout = new QHBoxLayout(this);
    layout->setMargin(0);
    auto tbr = new QToolBar;
    tbr->addAction(m_colorPicker = new ColorPickerAction(this));
    tbr->setStyleSheet("QToolBar {margin: 0px;}");
    layout->addWidget(tbr);

    layout->addWidget(m_brushSizeEditor = new BrushSizeEditor);
}

QColor BrushToolSetup::brushColor() const
{
    return m_colorPicker->color();
}

double BrushToolSetup::brushDiameter() const
{
    return m_brushSizeEditor->brushDiameter();
}
