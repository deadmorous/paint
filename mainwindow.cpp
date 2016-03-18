#include "mainwindow.h"
#include "canvas.h"
#include "colorpickeraction.h"

#include "brushtool.h"

#include <QToolBar>
#include <QIcon>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_canvas(new Canvas)
{
    QToolBar *tbr = addToolBar(tr("Tools"));
    // QAction *a;

//    ColorPickerAction *pickColorAction = new ColorPickerAction(this);
//    tbr->addAction(pickColorAction);

    BrushTool *bt = new BrushTool(this);
    bt->setCanvas(m_canvas);
    QAction *a = bt->toolAction();
    a->setCheckable(true);
    tbr->addAction(a);
    connect(a, SIGNAL(toggled(bool)),
            bt, SLOT(setActive(bool)));

    setCentralWidget(m_canvas);
}

