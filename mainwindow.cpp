#include "mainwindow.h"
#include "widget.h"
#include "colorpickeraction.h"
#include <QToolBar>
#include <QIcon>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_canvas(new Widget)
{
    QToolBar *tbr = addToolBar(tr("Tools"));
    // QAction *a;

    ColorPickerAction *pickColorAction = new ColorPickerAction(this);
    tbr->addAction(pickColorAction);
    connect(pickColorAction, SIGNAL(colorPicked(QColor)),
            m_canvas, SLOT(setBrushColor(QColor)));

    setCentralWidget(m_canvas);
}

