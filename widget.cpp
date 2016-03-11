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
    m_pix = QPixmap(e->size());
    QPainter p(&m_pix);
    p.fillRect(m_pix.rect(), Qt::white);
}

void Widget::mousePressEvent(QMouseEvent *e)
{
}

void Widget::mouseReleaseEvent(QMouseEvent *e)
{
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{
    QPainter p(&m_pix);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::green);
    p.setRenderHint(QPainter::Antialiasing);
    p.drawEllipse(e->pos(), 9, 9);
    update();
}

