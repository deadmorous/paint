#ifndef PAINTTOOL_H
#define PAINTTOOL_H

#include <QObject>

class QAction;
class Canvas;

class PaintTool : public QObject
{
    Q_OBJECT
public:
    explicit PaintTool(QObject *parent = 0);

    virtual QAction *toolAction() = 0;
    virtual QWidget *toolSetupWidget() = 0;

    Canvas *canvas() const;
    bool isActive() const;
signals:

public slots:
    void setCanvas(Canvas* canvas);
    void setActive(bool active);

private:
    Canvas *m_canvas;
    bool m_active;
};

#endif // PAINTTOOL_H
