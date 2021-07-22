#ifndef PEOPLE_H
#define PEOPLE_H

#include <QString>
#include <QVariantList>
class People
{
    private:
    int id;
    QString _name;
    int _sex;
    int _weight;
    int _nationality;
    QString _birthday;
    QString _deathday;
    int _age;
    int _growth;

    int _bAge;
    int _bMonth;
    int _bDay;

public:
    enum Type {NONE, NEW};

private:
    Type _status;

public:
    People(QVariantMap data);
    People (int id, QString name, int id_sex, int weight, int id_nation, QString birthday, QString deathday, int age, int growth);
    People (Type type, int id, QString name, int id_sex, int weight, int id_nation, QString birthday, QString deathday, int age, int growth);
    ~People ();

    QString name() const;
    int sex() const;
    int weight() const;
    int nationality() const;
    int age() const;
    int growth() const;
    QString birthday() const;
    QString deathday() const;
    Type status() const;
};

#endif // PEOPLE_H
