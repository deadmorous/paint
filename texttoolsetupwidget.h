#ifndef TEXTTOOLSETUPWIDGET_H
#define TEXTTOOLSETUPWIDGET_H

#include <QWidget>

class ColorPickerAction;
class FontPickerWidget;

class TextToolSetupWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TextToolSetupWidget(QWidget *parent = 0);
    QColor textColor() const;
    QFont textFont() const;

signals:

public slots:

private:
    ColorPickerAction *m_pickColorAction;
    FontPickerWidget *m_fontPickerWidget;
};

#endif // TEXTTOOLSETUPWIDGET_H
