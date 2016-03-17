#include "brushtool.h"

#include <QAction>
#include <QIcon>
#include "registry.h"

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

DECL_PAINT_TOOL_REGISTRATOR(BrushTool)
