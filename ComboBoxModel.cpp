#include "ComboBoxModel.h"


ComboBoxModel::ComboBoxModel(QObject *parent): QAbstractListModel(parent) {}

void ComboBoxModel::startReset() { beginResetModel(); }

void ComboBoxModel::endReset() { endResetModel(); }

int ComboBoxModel::rowCount(const QModelIndex &) const {
    return values.count();
}

QVariant ComboBoxModel::data(const QModelIndex &index, int role) const {
    QVariant value;
    if (!index.isValid())
        return value;

    if (role == Roles::id)
        value = values.value(index.row()).first;
    else if (role == Roles::value)
        value = values.value(index.row()).second;

    return value;
}

void ComboBoxModel::add(int id, QString value) {
    values.append(QPair<int,QString>(id, value));
    valuesMap[id] = value;
}

int ComboBoxModel::updateIndex(int i) {
    if (i < 1)
        return 1;

    if (i >= values.size())
        return values.size() - 1;
    else
        return i;
}

QString ComboBoxModel::tr(int id) {
    if (valuesMap.contains(id))
        return valuesMap[id];
    return "?";
}

int ComboBoxModel::valueToId(QString value)
{
    if (value.size() == 0)
        return 1;

    for (int i = 0; i < values.size(); i++) {
        if (values.at(i).second == value)
            return values.at(i).first;
    }
    return 1;
}

QHash<int, QByteArray> ComboBoxModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Roles::id] = "id";
    roles[Roles::value] = "value";

    return roles;
}
