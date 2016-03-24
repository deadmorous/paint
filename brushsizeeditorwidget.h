#ifndef BRUSHSIZEEDITORWIDGET_H
#define BRUSHSIZEEDITORWIDGET_H

#include <QWidget>

class BrushPreviewWidget;

class BrushSizeEditorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BrushSizeEditorWidget(QWidget *parent = 0);
    double brushDiameter() const;

signals:
    void brushDiameterChanged(double brushDiameter);

public slots:

private slots:
    void sliderMoved(int position);

private:
    double m_brushDiameter;
    BrushPreviewWidget *m_brushPreview;
};

#endif // BRUSHSIZEEDITORWIDGET_H
