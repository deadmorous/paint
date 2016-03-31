#ifndef TEXTTOOL_H
#define TEXTTOOL_H

#include "painttool.h"
#include <QPoint>

class TextToolSetupWidget;

class TextTool : public PaintTool
{
Q_OBJECT
public:
    TextTool(QObject *parent = NULL);

    // PaintTool interface
    QAction *toolAction();
    QWidget *toolSetupWidget();

    DECL_PAINT_TOOL_GENERATOR(TextTool)

protected:
    void onActivate();
    void onDeactivate();
    bool eventFilter(QObject *watched, QEvent *event);
    void timerEvent(QTimerEvent *event);

private:
    int m_eventFileterRecursionDepth;
    QAction *m_toolAction;
    TextToolSetupWidget *m_toolSetupWidget;

    QPoint m_lastPos;
    bool m_hasLastPos;
    bool m_cursorVisible;
    int m_timerId;
};

#endif // TEXTTOOL_H
