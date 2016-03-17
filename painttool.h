#ifndef PAINTTOOL_H
#define PAINTTOOL_H

#include <QObject>
#include "registry.h"

class QAction;
class Canvas;

class PaintTool : public QObject
{
Q_OBJECT
public:
    explicit PaintTool(QObject *parent = 0);

    virtual QAction *toolAction() = 0;
    virtual QWidget *toolSetupWidget() = 0;

    typedef PaintTool* (*Generator)(QObject*);
    static QVector<Generator> toolGenerators();

signals:

public slots:
    void activate(Canvas *canvas);
    void deactivate();

protected:
    Canvas *canvas();

private:
    Canvas *m_canvas;
};

typedef Registry< PaintTool::Generator > PaintToolRegistry;

typedef Registrator< PaintTool::Generator > PaintToolRegistrator;

#define DECL_PAINT_TOOL_GENERATOR(ClassName) \
    static PaintTool *New(QObject *parent) { \
        return new ClassName(parent); \
        }

#define DECL_PAINT_TOOL_REGISTRATOR(ClassName) \
    PaintToolRegistrator ClassName##Registrator(&ClassName::New);

#endif // PAINTTOOL_H
