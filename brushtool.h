#ifndef BRUSHTOOL_H
#define BRUSHTOOL_H

#include "painttool.h"

class BrushTool : public PaintTool
{
Q_OBJECT
public:
    BrushTool(QObject *parent = NULL);

    // PaintTool interface
    QAction *toolAction();
    QWidget *toolSetupWidget();

private:
    QAction *m_toolAction;
    QWidget *m_toolSetupWidget;
};

#endif // BRUSHTOOL_H
