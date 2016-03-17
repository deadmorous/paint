#include "mainwindow.h"
#include "canvas.h"
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
    m_tbr = addToolBar(tr("Tools"));

    auto toolActionGroup = new QActionGroup(this);

    QList<PaintTool*> paintTools;
    foreach (PaintTool::Generator g, PaintToolRegistry::generators()) {
        PaintTool *tool = g(this);
        paintTools << tool;
        tool->setCanvas(m_canvas);
        QAction *toolAction = tool->toolAction();
        toolAction->setCheckable(true);
        m_tbr->addAction(toolAction);
        toolActionGroup->addAction(toolAction);
        connect(toolAction, SIGNAL(toggled(bool)), tool, SLOT(setActive(bool)));
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
