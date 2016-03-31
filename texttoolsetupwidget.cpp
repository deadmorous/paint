#include "texttoolsetupwidget.h"

#include <QToolBar>
#include <QHBoxLayout>
#include "colorpickeraction.h"
#include "fontpickerwidget2.h"

TextToolSetupWidget::TextToolSetupWidget(QWidget *parent) : QWidget(parent)
{
    auto layout = new QHBoxLayout(this);
    layout->setMargin(0);
    auto tbr = new QToolBar;
    tbr->setStyleSheet("QToolBar { margin: 0px; }");
    layout->addWidget(tbr);
    m_pickColorAction = new ColorPickerAction(this);
    tbr->addAction(m_pickColorAction);

    tbr->addWidget(m_fontPickerWidget = new FontPickerWidget2);
}

QColor TextToolSetupWidget::textColor() const
{
    return m_pickColorAction->color();
}

QFont TextToolSetupWidget::textFont() const
{
    return m_fontPickerWidget->selectedFont();
}
