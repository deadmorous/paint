#include "mainwindow.h"
#include "canvas.h"
#include "colorpickeraction.h"
#include "painttool.h"

#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QSignalMapper>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_canvas(new Canvas),
    m_currentTool(nullptr)
{
    QToolBar *tbr = addToolBar(tr("Tools"));
    // QAction *a;

    ColorPickerAction *pickColorAction = new ColorPickerAction(this);
    tbr->addAction(pickColorAction);
    connect(pickColorAction, SIGNAL(colorPicked(QColor)),
            m_canvas, SLOT(setBrushColor(QColor)));

    QSignalMapper *toolSignalMapper = new QSignalMapper(this);
    connect(toolSignalMapper, SIGNAL(mapped(QObject*)), SLOT(activateTool(QObject*)));
    foreach (PaintTool::Generator g, PaintToolRegistry::generators()) {
        PaintTool *tool = g(this);
        QAction *toolAction = tool->toolAction();
        tbr->addAction(toolAction);
        toolSignalMapper->setMapping(toolAction, tool);
        connect(toolAction, SIGNAL(triggered(bool)), toolSignalMapper, SLOT(map()));
    }

    setCentralWidget(m_canvas);
}

void MainWindow::activateTool(QObject *tool)
{
    if (m_currentTool) {
        m_currentTool->deactivate();
        m_currentTool = nullptr;
    }
    PaintTool *paintTool = qobject_cast<PaintTool*>(tool);
    Q_ASSERT(paintTool);
    paintTool->activate(m_canvas);
    m_currentTool = paintTool;
}
