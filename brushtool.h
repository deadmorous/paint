#ifndef BRUSHTOOL_H
#define BRUSHTOOL_H

#include "painttool.h"
#include <QPoint>

class BrushTool : public PaintTool
{
    Q_OBJECT
public:
    explicit BrushTool(QObject *parent = 0);

    // PaintTool interface
    QAction *toolAction();
    QWidget *toolSetupWidget();

protected:
    bool eventFilter(QObject* watched, QEvent *event);

private:
    QAction *m_toolAction;
    QWidget *m_toolSetupWidget;
    QPoint m_lastPos;
};

#endif // BRUSHTOOL_H
