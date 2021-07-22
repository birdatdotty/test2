#ifndef COMBOBOXMODEL_H
#define COMBOBOXMODEL_H

#include <QAbstractListModel>
#include <QDebug>

class ComboBoxModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {id = Qt::UserRole + 1, value};
    ComboBoxModel(QObject *parent = nullptr);
    void startReset();
    void endReset();
    int rowCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role) const;
    void add(int id, QString value);
    Q_INVOKABLE int updateIndex(int i);
    Q_INVOKABLE QString tr(int id);
    Q_INVOKABLE int valueToId(QString value);

private:
    // id, value:
    QList<QPair<int,QString>> values;
    QMap<int,QString> valuesMap;


    // QAbstractItemModel interface
public:
    QHash<int, QByteArray> roleNames() const;
};

#endif // COMBOBOXMODEL_H
