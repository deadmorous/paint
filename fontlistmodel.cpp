#include "fontlistmodel.h"

FontListModel::FontListModel(QObject *parent) : QAbstractListModel(parent)
{
    m_fontFamilies = m_fdb.families();
}

int FontListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    else
        return m_fontFamilies.size();
}

QVariant FontListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    switch (role) {
    case Qt::DisplayRole:
        return m_fontFamilies[index.row()];
    case Qt::FontRole:
        return m_fdb.font(m_fontFamilies[index.row()], QString(), 18);
    default:
        return QVariant();
    }
}
