#include "brushtool.h"

#include <QAction>
#include <QIcon>

BrushTool::BrushTool(QObject *parent) :
    PaintTool(parent)
{
    m_toolAction = new QAction(QIcon(":/pix/brush.png"), tr("Brush"), this);
    m_toolSetupWidget = nullptr;
}

QAction *BrushTool::toolAction()
{
    return m_toolAction;
}

QWidget *BrushTool::toolSetupWidget()
{
    return m_toolSetupWidget;
}
