#include "texttoolsetup.h"
#include <QHBoxLayout>
#include <QToolBar>
#include "colorpickeraction.h"

TextToolSetup::TextToolSetup(QWidget *parent) : QWidget(parent)
{
    auto layout = new QHBoxLayout(this);
    layout->setMargin(0);
    auto tbr = new QToolBar;
    tbr->addAction(m_colorPicker = new ColorPickerAction(this));
    tbr->setStyleSheet("QToolBar {margin: 0px;}");
    layout->addWidget(tbr);
}

QColor TextToolSetup::textColor() const
{
    return m_colorPicker->color();
}
