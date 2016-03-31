#ifndef FONTPICKERWIDGET2_H
#define FONTPICKERWIDGET2_H

#include <QWidget>

class QComboBox;
class QStandardItemModel;

class FontPickerWidget2 : public QWidget
{
    Q_OBJECT
public:
    explicit FontPickerWidget2(QWidget *parent = 0);
    QFont selectedFont() const;

signals:

public slots:

private slots:
    void fontFamilyChanged();

private:
    QComboBox *m_cbFamilyList;
    QComboBox *m_cbStyleList;
    QComboBox *m_cbSizeList;
    QStandardItemModel *m_styleModel;
};

#endif // FONTPICKERWIDGET2_H
