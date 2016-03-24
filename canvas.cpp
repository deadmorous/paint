#include "canvas.h"

#include <QLabel>
#include <QPainter>
#include <QResizeEvent>
#include <QMessageBox>

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

void Canvas::loadImage(const QString& fileName)
{
    if (!m_pix.load(fileName))
        QMessageBox::critical(this, QString(), tr("Unable to load picture from file %1").arg(fileName));
    update();
}

void Canvas::saveImage(const QString& fileName)
{
    if (!m_pix.save(fileName))
        QMessageBox::critical(this, QString(), tr("Unable to save picture to file %1").arg(fileName));
}
