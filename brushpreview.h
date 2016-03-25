#ifndef BRUSHPREVIEW_H
#define BRUSHPREVIEW_H

#include <QWidget>

class BrushPreview : public QWidget
{
    Q_OBJECT
public:
    explicit BrushPreview(QWidget *parent = 0);

signals:

public slots:
    void setBrushDiameter(int brushDiameter);
    void setBrushDiameter(double brushDiameter);

protected:
    void paintEvent(QPaintEvent *);

private:
    double m_brushDiameter;
};

#endif // BRUSHPREVIEW_H
