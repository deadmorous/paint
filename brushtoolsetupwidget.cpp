#include "brushtoolsetupwidget.h"

#include <QToolBar>
#include <QHBoxLayout>
#include "colorpickeraction.h"
#include "brushsizeeditorwidget.h"

BrushToolSetupWidget::BrushToolSetupWidget(QWidget *parent) : QWidget(parent)
{
    auto layout = new QHBoxLayout(this);
    layout->setMargin(0);
    auto tbr = new QToolBar;
    tbr->setStyleSheet("QToolBar { margin: 0px; }");
    layout->addWidget(tbr);
    tbr->addAction(m_pickColorAction = new ColorPickerAction(this));
    tbr->addSeparator();
    tbr->addWidget(m_brushSizeEditor = new BrushSizeEditorWidget);
}

QColor BrushToolSetupWidget::brushColor() const
{
    return m_pickColorAction->color();
}

double BrushToolSetupWidget::brushDiameter() const
{
    return m_brushSizeEditor->brushDiameter();
}
