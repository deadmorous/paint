#ifndef BRUSHTOOLSETUPWIDGET_H
#define BRUSHTOOLSETUPWIDGET_H

#include <QWidget>

class ColorPickerAction;
class BrushSizeEditorWidget;

class BrushToolSetupWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BrushToolSetupWidget(QWidget *parent = 0);
    QColor brushColor() const;
    double brushDiameter() const;

signals:

public slots:

private:
    ColorPickerAction *m_pickColorAction;
    BrushSizeEditorWidget *m_brushSizeEditor;
};

#endif // BRUSHTOOLSETUPWIDGET_H
