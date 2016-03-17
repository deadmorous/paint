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

signals:

public slots:
    void activate(Canvas *canvas);
    void deactivate();

protected:
    Canvas *canvas();

private:
    Canvas *m_canvas;
};

#endif // PAINTTOOL_H
