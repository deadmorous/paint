#include "mainwindow.h"
#include "widget.h"
#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QColorDialog>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_canvas(new Widget)
{
    QToolBar *tbr = addToolBar(tr("Tools"));
    // QAction *a;

    m_pickColorAction = tbr->addAction(tr("Pick color"));
    connect(m_pickColorAction, SIGNAL(triggered(bool)), SLOT(pickColor()));

    setCentralWidget(m_canvas);
    updateColor();
}

void MainWindow::pickColor()
{
    QColor c = QColorDialog::getColor(Qt::white, this, "Select brush color");
    if (!c.isValid())
        return;
    m_canvas->setBrushColor(c);
    updateColor();
}

void MainWindow::updateColor()
{
    QColor c = m_canvas->brushColor();
    QPixmap pix(16, 16);
    {
        QPainter p(&pix);
        p.fillRect(pix.rect(), c);
    }
    m_pickColorAction->setIcon(QIcon(pix));
}
