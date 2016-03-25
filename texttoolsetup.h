#ifndef TEXTTOOLSETUP_H
#define TEXTTOOLSETUP_H

#include <QWidget>

class ColorPickerAction;

class TextToolSetup : public QWidget
{
    Q_OBJECT
public:
    explicit TextToolSetup(QWidget *parent = 0);
    QColor textColor() const;

signals:

public slots:

private:
    ColorPickerAction *m_colorPicker;
};

#endif // TEXTTOOLSETUP_H
