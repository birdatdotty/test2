#include "People.h"

#include <QDate>

#include <QDebug>

People::People(QVariantMap data) {
    if (data.contains("name"))
        _name = data["name"].toString();

    if (data.contains("sex"))
        _sex = data["sex"].toInt();

    if (data.contains("weight"))
        _weight = data["weight"].toUInt();

    if (data.contains("nationality"))
        _nationality = data["nationality"].toInt();

    if (data.contains("birthday"))
        _birthday = data["birthday"].toString();

    if (data.contains("deathday"))
        _deathday = data["deathday"].toString();
    else
        _deathday = "";

    _status = NONE;

}

People::People(int id, QString name, int id_sex, int weight, int id_nation, QString birthday, QString deathday, int age, int growth)
    : id(id), _name(name), _sex(id_sex), _weight(weight), _nationality(id_nation), _birthday(birthday), _deathday(deathday), _age(age), _growth(growth) {}

People::People(People::Type type, int id, QString name, int id_sex, int weight, int id_nation, QString birthday, QString deathday, int age, int growth)
    : id(id), _name(name), _sex(id_sex), _weight(weight), _nationality(id_nation), _birthday(birthday), _deathday(deathday), _age(age), _growth(growth), _status(type)  {}

People::~People() {
    qInfo() << "People::~People(): " << _name;
}

QString People::name() const {return _name;}

int People::sex() const {return _sex;}

int People::weight() const {return _weight;}

int People::nationality() const {return _nationality;}

int People::age() const {return _age; }

int People::growth() const { return _growth; }

QString People::birthday() const {return _birthday;}

QString People::deathday() const {return _deathday;}

People::Type People::status() const {return _status;}
