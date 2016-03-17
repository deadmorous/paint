#ifndef COLORPICKERACTION_H
#define COLORPICKERACTION_H

#include <QAction>

class ColorPickerAction : public QAction
{
Q_OBJECT
public:
    explicit ColorPickerAction(QObject *parent = NULL);
    QColor color() const;

signals:
    void colorPicked(QColor color);

private slots:
    void pickColor();

private:
    QColor m_color;
    void updateColor();
};

#endif // COLORPICKERACTION_H
