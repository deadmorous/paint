#ifndef FONTFAMILYMODEL_H
#define FONTFAMILYMODEL_H

#include <QAbstractListModel>
#include <QFontDatabase>

class FontFamilyModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit FontFamilyModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

private:
    QFontDatabase m_fdb;
    QStringList m_families;
};

#endif // FONTFAMILYMODEL_H
