#include "canvas.h"

//#include <QVBoxLayout>
//#include <QHBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QResizeEvent>
#include <QMouseEvent>

Canvas::Canvas(QWidget *parent)
    : QWidget(parent)
{

//    QToolBar *w1 = new QToolBar;
//    QAction *aQuit = w1->addAction(QIcon(":/pix/f1.png"), "Quit");
//    w1->addAction(QIcon(":/pix/f2.png"), "Action 1");
//    w1->addAction("Action 2");
//    QLabel *w21 = new QLabel("w21");
//    QLabel *w22 = new QLabel("w22");
//    QLabel *w3 = new QLabel("w3");
//    QVBoxLayout *vl = new QVBoxLayout(this);
//    vl->addWidget(w1);
//    QHBoxLayout *hl = new QHBoxLayout;
//    hl->addWidget(w21);
//    hl->addWidget(w22);
//    vl->addLayout(hl);
//    vl->addWidget(w3);

//    connect(aQuit, SIGNAL(triggered()), this, SLOT(close()));
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
