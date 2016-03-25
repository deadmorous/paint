#ifndef BRUSHSIZEEDITOR_H
#define BRUSHSIZEEDITOR_H

#include <QWidget>

class BrushPreview;
class QSlider;

class BrushSizeEditor : public QWidget
{
    Q_OBJECT
public:
    explicit BrushSizeEditor(QWidget *parent = 0);
    double brushDiameter() const;

signals:

public slots:

private:
    BrushPreview *m_preview;
    QSlider *m_slider;
};

#endif // BRUSHSIZEEDITOR_H
