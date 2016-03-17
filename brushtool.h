#ifndef BRUSHTOOL_H
#define BRUSHTOOL_H

#include "painttool.h"

class BrushToolSetupWidget;

class BrushTool : public PaintTool
{
Q_OBJECT
public:
    BrushTool(QObject *parent = NULL);
    ~BrushTool();

    // PaintTool interface
    QAction *toolAction();
    QWidget *toolSetupWidget();

    DECL_PAINT_TOOL_GENERATOR(BrushTool)

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    QAction *m_toolAction;
    BrushToolSetupWidget *m_toolSetupWidget;
    QPoint m_lastPos;
};

#endif // BRUSHTOOL_H
