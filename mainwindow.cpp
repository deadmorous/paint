#include "mainwindow.h"
#include "canvas.h"
#include "colorpickeraction.h"

#include "brushtool.h"
#include "texttool.h"

#include <QToolBar>
#include <QIcon>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_canvas(new Canvas)
{
    m_brushTool = new BrushTool(this);
    m_textTool = new TextTool(this);

    QToolBar *tbr = addToolBar(tr("Tools"));
    // QAction *a;

    ColorPickerAction *pickColorAction = new ColorPickerAction(this);
    tbr->addAction(pickColorAction);
    connect(pickColorAction, SIGNAL(colorPicked(QColor)),
            m_canvas, SLOT(setBrushColor(QColor)));

    tbr->addAction(m_brushTool->toolAction());
    tbr->addAction(m_textTool->toolAction());

    setCentralWidget(m_canvas);
}

