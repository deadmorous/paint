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

    QColor brushColor() const;

public slots:
    void setBrushColor(QColor c);

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);

private:
    QPixmap m_pix;
    QPoint m_lastPos;
    QColor m_brushColor;
    friend class CanvasPixmap;
};

class CanvasPixmap
{
public:
    explicit CanvasPixmap(Canvas *canvas) :
        pix(canvas->m_pix),
        m_canvas(canvas)
    {}
    ~CanvasPixmap() {
        m_canvas->update();
    }

    QPixmap& pix;
private:
    Canvas *m_canvas;
};

#endif // CANVAS_H
