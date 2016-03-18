#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPixmap>

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = 0);
    QSize sizeHint() const;

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *e);

private:
    QPixmap m_pix;
    friend class CanvasPixmap;
};

class CanvasPixmap
{
public:
    explicit CanvasPixmap(Canvas *canvas) :
        m_canvas(canvas)
    {}
    ~CanvasPixmap()
    {
        m_canvas->update();
    }
    operator QPixmap*() {
        return &m_canvas->m_pix;
    }

private:
    Canvas *m_canvas;
};

#endif // CANVAS_H
