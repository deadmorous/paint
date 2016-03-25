#ifndef BRUSHTOOL_H
#define BRUSHTOOL_H

#include "painttool.h"
#include <QPoint>

class BrushToolSetup;

class BrushTool : public PaintTool
{
    Q_OBJECT
public:
    explicit BrushTool(QObject *parent = 0);

    // PaintTool interface
    QAction *toolAction();
    QWidget *toolSetupWidget();

    DECL_PAINT_TOOL_GENERATOR(BrushTool)

protected:
    bool eventFilter(QObject* watched, QEvent *event);

private:
    QAction *m_toolAction;
    BrushToolSetup *m_toolSetupWidget;
    QPoint m_lastPos;
};

#endif // BRUSHTOOL_H
