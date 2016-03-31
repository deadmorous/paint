#ifndef FONTLISTMODEL_H
#define FONTLISTMODEL_H

#include <QAbstractListModel>
#include <QFontDatabase>

class FontListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    FontListModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

private:
    QStringList m_fontFamilies;
    QFontDatabase m_fdb;
};

#endif // FONTLISTMODEL_H
