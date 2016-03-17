#include "texttool.h"

#include <QAction>
#include <QIcon>

TextTool::TextTool(QObject *parent) :
    PaintTool(parent)
{
    m_toolAction = new QAction(QIcon(":/pix/text.png"), tr("Brush"), this);
    m_toolSetupWidget = nullptr;
}

QAction *TextTool::toolAction()
{
    return m_toolAction;
}

QWidget *TextTool::toolSetupWidget()
{
    return m_toolSetupWidget;
}

DECL_PAINT_TOOL_REGISTRATOR(TextTool)
