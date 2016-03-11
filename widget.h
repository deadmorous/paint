#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
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
};

#endif // WIDGET_H
