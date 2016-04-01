#ifndef TEXTTOOL_H
#define TEXTTOOL_H

#include "painttool.h"
#include <QPoint>

class TextToolSetup;

class TextTool : public PaintTool
{
    Q_OBJECT
public:
    explicit TextTool(QObject *parent = 0);

    // PaintTool interface
    QAction *toolAction();
    QWidget *toolSetupWidget();

    DECL_PAINT_TOOL_GENERATOR(TextTool)

protected:
    bool eventFilter(QObject* watched, QEvent *event);

private:
    QAction *m_toolAction;
    TextToolSetup *m_toolSetupWidget;
    QPoint m_lastPos;
    int m_efCounter;
};

#endif // TEXTTOOL_H
