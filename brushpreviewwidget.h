#ifndef BRUSHPREVIEWWIDGET_H
#define BRUSHPREVIEWWIDGET_H

#include <QWidget>

class BrushPreviewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BrushPreviewWidget(QWidget *parent = 0);
    void setBrushDiameter(double brushDiameter);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *);

private:
    double m_brushDiameter;
};

#endif // BRUSHPREVIEWWIDGET_H
