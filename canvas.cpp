#include "canvas.h"

//#include <QVBoxLayout>
//#include <QHBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QResizeEvent>

Canvas::Canvas(QWidget *parent)
    : QWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
}

QSize Canvas::sizeHint() const
{
    return QSize(600, 400);
}

void Canvas::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0, 0, m_pix);
}

void Canvas::resizeEvent(QResizeEvent *e)
{
    QPixmap newPix(e->size());
    {
        QPainter p(&newPix);
        p.fillRect(newPix.rect(), Qt::white);
        if (!m_pix.isNull())
            p.drawPixmap(0, 0, m_pix);
    }
    m_pix = newPix;
}
