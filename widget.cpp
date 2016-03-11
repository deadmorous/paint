#include "widget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QPainter>
#include <QResizeEvent>
#include <QMouseEvent>

Widget::Widget(QWidget *parent)
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

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0, 0, m_pix);
}

void Widget::resizeEvent(QResizeEvent *e)
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

void Widget::mousePressEvent(QMouseEvent *e)
{
    m_lastPos = e->pos();
}

void Widget::mouseReleaseEvent(QMouseEvent *e)
{
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{
    QPainter p(&m_pix);
    QPen pen(Qt::green, 18);
    pen.setCapStyle(Qt::RoundCap);
    p.setPen(pen);
    p.setRenderHint(QPainter::Antialiasing);
    p.drawLine(m_lastPos, e->pos());
    update();
    m_lastPos = e->pos();
}

