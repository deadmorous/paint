#include "mainwindow.h"
#include "canvas.h"
#include "colorpickeraction.h"

#include "painttool.h"

#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QActionGroup>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_canvas(new Canvas)
{
    QToolBar *tbr = addToolBar(tr("Tools"));
    // QAction *a;

//    ColorPickerAction *pickColorAction = new ColorPickerAction(this);
//    tbr->addAction(pickColorAction);


    auto toolActionGroup = new QActionGroup(this);
    foreach (PaintTool::Generator g, PaintToolRegistry::generators()) {
        PaintTool *tool = g(this);
        tool->setCanvas(m_canvas);
        QAction *a = tool->toolAction();
        toolActionGroup->addAction(a);
        a->setCheckable(true);
        tbr->addAction(a);
        connect(a, SIGNAL(toggled(bool)),
                tool, SLOT(setActive(bool)));
    }
    setCentralWidget(m_canvas);
}

