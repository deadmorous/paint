#include "fontpickerwidget.h"

#include <QFontDialog>
#include <QPainter>

FontPickerWidget::FontPickerWidget(QWidget *parent) : QWidget(parent)
{
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setMinimumSize(150, 20);
}

QFont FontPickerWidget::selectedFont() const
{
    return m_font;
}

void FontPickerWidget::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
    bool ok;
    QFont font = QFontDialog::getFont(&ok, m_font, this, tr("Select font"));
    if (ok)
    {
        m_font = font;
        update();
    }
}

void FontPickerWidget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QFont font = m_font;
    font.setPixelSize(16);
    QPainter p(this);
    p.fillRect(rect(), Qt::white);
    p.setFont(font);
    p.drawText(rect(), Qt::AlignCenter, font.family());
}
