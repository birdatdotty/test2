#include "MySQLite.h"
#include "PeopleModel.h"

#include <QDebug>


PeopleModel::PeopleModel(QObject *parent): QAbstractListModel(parent) {}

PeopleModel::~PeopleModel()
{
    qInfo() << "PeopleModel::~PeopleModel(): ";
    for (int i = 0; i < peoples.size(); i++)
        delete peoples.at(i);
}

QHash<int, QByteArray> PeopleModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[SexRole] = "sex";
    roles[WeightRole] = "weight";
    roles[NationalityRole] = "nationality";
    roles[BirthdayRole] = "birthday";
    roles[DeathdayRole] = "death";
    roles[GrowthRole] = "growth";
    roles[AgeRole] = "age";
    roles[StatusRole] = "status";

    return roles;
}

QModelIndex PeopleModel::index(int row, int column, const QModelIndex &parent) const
{
    // warning: maybe need drop one function:
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    if (column != 0 || row >= peoples.size() || row < 0)
        return QModelIndex();

    return createIndex(row, column, peoples.at(row));
}

int PeopleModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return peoples.count();
}

QVariant PeopleModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();

    if(role == NameRole)
        return peoples.at(row)->name();

    if(role == NameRole)
        return peoples.at(row)->name();

    if(role == SexRole)
        return peoples.at(row)->sex();

    if(role == WeightRole)
        return peoples.at(row)->weight();

    if (role == NationalityRole)
        return peoples.at(row)->nationality();

    if (role == BirthdayRole)
        return peoples.at(row)->birthday();

    if (role == BirthdayRole)
        return peoples.at(row)->birthday();

    if (role == DeathdayRole)
        return peoples.at(row)->deathday();

    if (role == StatusRole)
        return peoples.at(row)->status();

    if (role == GrowthRole)
        return peoples.at(row)->growth();

    if (role == AgeRole)
        return peoples.at(row)->age();

    return QVariant();
}

void PeopleModel::setObjectForNewPeoples(PeopleModel *child) {
    if (m_child == nullptr)
        m_child = child;

    sigObjectForNewPeoples(child);
}

PeopleModel *PeopleModel::objectForNewPeoples() { return m_child; }

void PeopleModel::addPeople(People *newPeople) {
    beginResetModel();
    peoples.append(newPeople);
    endResetModel();
}

void PeopleModel::addPeople(int id, QString name, int id_sex, int weight, int id_nation, QString birthday, QString deathday, int age, int growth)
{
    People *newPeople = new People(id, name, id_sex, weight, id_nation, birthday, deathday, age, growth);
    addPeople(newPeople);
}

void PeopleModel::addNewPeople(QString name, int id_sex, int weight, int id_nation, QString birthday, QString deathday, int age, int growth)
{
    People *newPeople = new People(People::NEW, 0, name, id_sex, weight, id_nation, birthday, deathday, age, growth);

    addPeople(newPeople);
    newPeoples.append(newPeople);

    testNeedSave();
}

void PeopleModel::saveToSQL(MySQLite* sql) {
    for (QList<People*>::iterator it = newPeoples.begin(); it != newPeoples.end(); it++) {
        People* people = *it;
        sql->addPeople(people->name(), people->sex(),
                       people->weight(), people->nationality(),
                       people->birthday(), people->deathday(),
                       people->age(), people->growth() );
    }
    for (int i = 0; i < peoples.size(); i++)
        delete peoples.at(i);

    newPeoples.clear();
    peoples.clear();
    testNeedSave();
}

int PeopleModel::rowNewCount() { return newPeoples.count(); }

