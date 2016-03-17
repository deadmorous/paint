#ifndef TEXTTOOL_H
#define TEXTTOOL_H

#include "painttool.h"

class TextTool : public PaintTool
{
Q_OBJECT
public:
    TextTool(QObject *parent = NULL);

    // PaintTool interface
    QAction *toolAction();
    QWidget *toolSetupWidget();

    DECL_PAINT_TOOL_GENERATOR(TextTool)

private:
    QAction *m_toolAction;
    QWidget *m_toolSetupWidget;
};

#endif // TEXTTOOL_H