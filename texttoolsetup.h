#ifndef TEXTTOOLSETUP_H
#define TEXTTOOLSETUP_H

#include <QWidget>

class ColorPickerAction;
class FontPicker;

class TextToolSetup : public QWidget
{
    Q_OBJECT
public:
    explicit TextToolSetup(QWidget *parent = 0);
    QColor textColor() const;
    QFont textFont() const;

signals:

public slots:

private:
    ColorPickerAction *m_colorPicker;
    FontPicker *m_fontPicker;
};

#endif // TEXTTOOLSETUP_H
