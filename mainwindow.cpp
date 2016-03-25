#include "mainwindow.h"
#include "canvas.h"
#include "colorpickeraction.h"

#include "painttool.h"

#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QActionGroup>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_canvas(new Canvas)
{
    QToolBar *tbr = addToolBar(tr("Tools"));
    // QAction *a;

//    ColorPickerAction *pickColorAction = new ColorPickerAction(this);
//    tbr->addAction(pickColorAction);


    auto toolActionGroup = new QActionGroup(this);
    QVector<PaintTool*> paintTools;
    foreach (PaintTool::Generator g, PaintToolRegistry::generators()) {
        PaintTool *tool = g(this);
        paintTools << tool;
        tool->setCanvas(m_canvas);
        QAction *a = tool->toolAction();
        toolActionGroup->addAction(a);
        a->setCheckable(true);
        tbr->addAction(a);
        connect(a, SIGNAL(toggled(bool)),
                tool, SLOT(setActive(bool)));
    }

    auto toolSetupPlaceHolder = new QWidget;
    auto toolSetupPlaceHolderLayout = new QHBoxLayout(toolSetupPlaceHolder);
    toolSetupPlaceHolderLayout->setMargin(0);
    foreach (PaintTool *tool, paintTools) {
        QWidget *toolSetup = tool->toolSetupWidget();
        if (toolSetup) {
            toolSetup->hide();
            toolSetupPlaceHolderLayout->addWidget(toolSetup);
        }
    }
    tbr->addSeparator();
    tbr->addWidget(toolSetupPlaceHolder);
    setCentralWidget(m_canvas);
}

