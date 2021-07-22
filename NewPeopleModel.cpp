#include "NewPeopleModel.h"

#include <QDate>
#include <QDebug>

#include "MySQLite.h"

void NewPeopleModel::applyChage()
{
}

MySQLite *NewPeopleModel::sql() {
    return m_sql;
}

void NewPeopleModel::setSex(int sex) {
    m_sex = sex;
}

int NewPeopleModel::sex() {
    return m_sex;
}

int NewPeopleModel::weight() { return _weight; }

void NewPeopleModel::setWeight(int weight) {
    _weight = weight;
    sigWeight(weight);
}

int NewPeopleModel::age() { return m_age; }
void NewPeopleModel::setAge(int age) { m_age = age; sigAge(age);}

int NewPeopleModel::growth() { return m_growth; }
void NewPeopleModel::setGrowth(int growth) { m_growth = growth; sigGrowth(growth);}

int NewPeopleModel::nation() { return m_nationality; }
void NewPeopleModel::setNation(int nation) { m_nationality = nation; sigNation(nation); }

QString NewPeopleModel::birthday() { return m_birthday;  }
void NewPeopleModel::setBirthday(QString birthday) { m_birthday = birthday; sigBirthday(m_birthday); }

QString NewPeopleModel::deathday() { return m_deathday; }
void NewPeopleModel::setDeathday(QString deathday) { m_deathday = deathday; sigDeathday(m_deathday); }

NewPeopleModel::NewPeopleModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

QHash<int, QByteArray> NewPeopleModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[SexRole] = "sex";
    roles[AgeRole] = "age";
    roles[WeightRole] = "weight";
    roles[NationalityRole] = "nationality";
    roles[BirthdayRole] = "birthday";
    roles[DeathdayRole] = "death";
    roles[StatusRole] = "status";

    return roles;
}

// QAbstractItemModel interface
QModelIndex NewPeopleModel::index(int row, int column, const QModelIndex &) const
{
    if (column != 0 || row >= peoples.size() || row < 0)
        return QModelIndex();

    return createIndex(row, column, peoples.at(row));
}

int NewPeopleModel::rowCount(const QModelIndex &) const
{
    return peoples.count();
}

QVariant NewPeopleModel::data(const QModelIndex &index, int role) const
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



    if(role == AgeRole)
        return peoples.at(row)->age();

    if (role == GrowthRole)
        return peoples.at(row)->growth();




    if (role == BirthdayRole)
        return peoples.at(row)->birthday();

    if (role == BirthdayRole)
        return peoples.at(row)->birthday();

    if (role == DeathdayRole)
        return peoples.at(row)->deathday();

    if (role == StatusRole)
        return peoples.at(row)->status();

    return QVariant();
}

// other:
void NewPeopleModel::addPople(People *newPeople) {
    peoples.append(newPeople);
}

QString NewPeopleModel::name() {
    return _name;
}

void NewPeopleModel::setName(QString name) {
    _name = name;

    sigName(name);
}

void NewPeopleModel::info() {
    qInfo() << "_name:" << _name;
    qInfo() << "m_birthday" << m_birthday;
    qInfo() << "m_deathday:" << m_deathday;
    qInfo() << "_nationality:" << m_nationality;
    qInfo() << "m_sex:" << m_sex;
    qInfo() << "_weight:" << _weight;
}
