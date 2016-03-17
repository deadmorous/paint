#include "brushtoolsetupwidget.h"

#include <QToolBar>
#include <QHBoxLayout>
#include "colorpickeraction.h"

BrushToolSetupWidget::BrushToolSetupWidget(QWidget *parent) : QWidget(parent)
{
    auto layout = new QHBoxLayout(this);
    layout->setMargin(0);
    auto tbr = new QToolBar;
    tbr->setStyleSheet("QToolBar { margin: 0px; }");
    layout->addWidget(tbr);
    m_pickColorAction = new ColorPickerAction(this);
    tbr->addAction(m_pickColorAction);
}

QColor BrushToolSetupWidget::brushColor() const
{
    return m_pickColorAction->color();
}
