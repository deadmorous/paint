#ifndef FONTPICKERWIDGET_H
#define FONTPICKERWIDGET_H

#include <QWidget>

class FontPickerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FontPickerWidget(QWidget *parent = 0);
    QFont selectedFont() const;

signals:

public slots:

protected:
    void mouseReleaseEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);

private:
    QFont m_font;

};

#endif // FONTPICKERWIDGET_H
