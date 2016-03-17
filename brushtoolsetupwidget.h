#ifndef BRUSHTOOLSETUPWIDGET_H
#define BRUSHTOOLSETUPWIDGET_H

#include <QWidget>

class ColorPickerAction;

class BrushToolSetupWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BrushToolSetupWidget(QWidget *parent = 0);
    QColor brushColor() const;

signals:

public slots:

private:
    ColorPickerAction *m_pickColorAction;
};

#endif // BRUSHTOOLSETUPWIDGET_H
