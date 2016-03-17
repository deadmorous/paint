#include "mainwindow.h"
#include "canvas.h"
#include "painttool.h"

#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QSignalMapper>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_canvas(new Canvas),
    m_currentTool(nullptr)
{
    m_tbr = addToolBar(tr("Tools"));
    // QAction *a;

    QSignalMapper *toolSignalMapper = new QSignalMapper(this);
    connect(toolSignalMapper, SIGNAL(mapped(QObject*)), SLOT(activateTool(QObject*)));
    QList<PaintTool*> paintTools;
    foreach (PaintTool::Generator g, PaintToolRegistry::generators()) {
        PaintTool *tool = g(this);
        paintTools << tool;
        QAction *toolAction = tool->toolAction();
        m_tbr->addAction(toolAction);
        toolSignalMapper->setMapping(toolAction, tool);
        connect(toolAction, SIGNAL(triggered(bool)), toolSignalMapper, SLOT(map()));
    }
    m_tbr->addSeparator();

    auto toolSetupPlaceholder = new QWidget;
    auto toolSetupPlaceholderLayout = new QHBoxLayout(toolSetupPlaceholder);
    toolSetupPlaceholderLayout->setMargin(0);
    foreach (PaintTool *tool, paintTools) {
        auto *toolSetupWidget = tool->toolSetupWidget();
        if (toolSetupWidget)
            toolSetupPlaceholderLayout->addWidget(toolSetupWidget);
    }
    m_tbr->addWidget(toolSetupPlaceholder);

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
