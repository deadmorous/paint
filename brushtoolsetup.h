#ifndef BRUSHTOOLSETUP_H
#define BRUSHTOOLSETUP_H

#include <QWidget>

class ColorPickerAction;
class BrushSizeEditor;

class BrushToolSetup : public QWidget
{
    Q_OBJECT
public:
    explicit BrushToolSetup(QWidget *parent = 0);
    QColor brushColor() const;
    double brushDiameter() const;

signals:

public slots:

private:
    ColorPickerAction *m_colorPicker;
    BrushSizeEditor *m_brushSizeEditor;
};

#endif // BRUSHTOOLSETUP_H
