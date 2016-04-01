#ifndef FONTPICKER_H
#define FONTPICKER_H

#include <QWidget>

class QComboBox;
class QStandardItemModel;

class FontPicker : public QWidget
{
    Q_OBJECT
public:
    explicit FontPicker(QWidget *parent = 0);
    QFont textFont() const;

signals:

public slots:

private slots:
    void fontFamilyChanged(const QString& family);

private:
    QComboBox *m_cbFamilyList;
    QComboBox *m_cbStyleList;
    QStandardItemModel *m_styleModel;
    QComboBox *m_cbSizeList;
};

#endif // FONTPICKER_H
