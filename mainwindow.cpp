#include "mainwindow.h"
#include "canvas.h"
#include "painttool.h"

#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QActionGroup>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QFileDialog>

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

    QMenuBar *mainMenu = menuBar();
    QMenu *fileMenu = mainMenu->addMenu(tr("&File"));

    QAction *a;

    a = new QAction(tr("&Open"), this);
    a->setShortcut(QKeySequence::Open);
    fileMenu->addAction(a);
    connect(a, SIGNAL(triggered(bool)), SLOT(open()));

    a = new QAction(tr("&Save"), this);
    a->setShortcut(QKeySequence::Save);
    fileMenu->addAction(a);
    connect(a, SIGNAL(triggered(bool)), SLOT(save()));

    a = new QAction(tr("Save as"), this);
    a->setShortcut(QKeySequence::SaveAs);
    fileMenu->addAction(a);
    connect(a, SIGNAL(triggered(bool)), SLOT(saveAs()));

    fileMenu->addSeparator();

    a = new QAction(tr("&Quit"), this);
    a->setShortcut(QKeySequence::Quit);
    fileMenu->addAction(a);
    connect(a, SIGNAL(triggered(bool)), SLOT(close()));

    setCentralWidget(m_canvas);
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open picture"), m_fileName, "Images (*.png *.jpg);;All files (*)" );
    if (fileName.isEmpty())
        return;
    m_canvas->loadImage(fileName);
    m_fileName = fileName;
    setWindowTitle(fileName);
}

void MainWindow::save()
{
    if (m_fileName.isEmpty())
        saveAs();
    else
        m_canvas->saveImage(m_fileName);
}

void MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save picture as"), m_fileName, "Images (*.png *.jpg);;All files (*)" );
    if (fileName.isEmpty())
        return;
    m_canvas->saveImage(fileName);
    m_fileName = fileName;
    setWindowTitle(fileName);
}
