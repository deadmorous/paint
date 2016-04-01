#include "fontfamilymodel.h"

FontFamilyModel::FontFamilyModel(QObject *parent) :
    QAbstractListModel(parent)
{
    m_families = m_fdb.families();
}

int FontFamilyModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return m_families.size();
}

QVariant FontFamilyModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    switch (role) {
    case Qt::DisplayRole:
        return m_families[index.row()];
    case Qt::FontRole:
        return m_fdb.font(m_families[index.row()], QString(), 12);
    default:
        return QVariant();
    }
}
