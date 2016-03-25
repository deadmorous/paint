#include "colorpickeraction.h"
#include <QColorDialog>
#include <QPainter>

ColorPickerAction::ColorPickerAction(QObject *parent) :
    QAction(parent),
    m_color(Qt::black)
{
    setText(tr("Pick color"));
    updateColor();
    connect(this, SIGNAL(triggered(bool)), SLOT(pickColor()));
}

QColor ColorPickerAction::color() const
{
    return m_color;
}

void ColorPickerAction::pickColor()
{
    QColor c = QColorDialog::getColor(Qt::white, parentWidget(), tr("Select brush color"));
    if (!c.isValid())
        return;
    m_color = c;
    updateColor();
    emit colorPicked(c);
}

void ColorPickerAction::updateColor()
{
    QPixmap pix(16, 16);
    {
        QPainter p(&pix);
        p.fillRect(pix.rect(), m_color);
    }
    setIcon(QIcon(pix));
}
