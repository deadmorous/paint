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
    typedef PaintTool *(*Generator)(QObject *);

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

typedef Registry<PaintTool::Generator> PaintToolRegistry;

#define DECL_PAINT_TOOL_GENERATOR(ClassName) \
static PaintTool *New(QObject *parent) { \
    return new ClassName(parent); \
}

#define DECL_PAINT_TOOL_REGISTRATOR(ClassName) \
Registrator<PaintTool::Generator> ClassName##Registrator(ClassName::New);

#endif // PAINTTOOL_H
