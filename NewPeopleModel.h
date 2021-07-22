// https://doc.qt.io/qt-5/qtquick-modelviewsdata-cppmodels.html
// https://habr.com/ru/post/349822/
// https://doc.qt.io/qt-5/qjsengine.html

#ifndef NEWPEOPLEMODEL_H
#define NEWPEOPLEMODEL_H

#include <QAbstractListModel>
#include <QDate>
#include "People.h"
#include <QDebug>
class MySQLite;

class NewPeopleModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY sigName)
    Q_PROPERTY(int sex READ sex WRITE setSex NOTIFY sigSex)
    Q_PROPERTY(QString birthday READ birthday WRITE setBirthday NOTIFY sigBirthday)
    Q_PROPERTY(QString deathday READ deathday WRITE setDeathday NOTIFY sigDeathday)
    Q_PROPERTY(int weight READ weight WRITE setWeight NOTIFY sigWeight)
    Q_PROPERTY(int nation READ nation WRITE setNation NOTIFY sigNation)
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY sigAge)
    Q_PROPERTY(int growth READ growth WRITE setGrowth NOTIFY sigGrowth)

public:
    Q_INVOKABLE void applyChage();
    void setSQL(MySQLite sql);
    MySQLite* sql();

    void setSex(int sex);
    int sex();

    int weight();
    void setWeight(int weight);

    int age();
    void setAge(int age);

    int growth();
    void setGrowth(int growth);

    int nation();
    void setNation(int nation);

    QString birthday();
    void setBirthday(QString birthday);

    QString deathday();
    void setDeathday(QString deathday);

    //имя, пол, возраст, рост, вес, национальность (выбор из внутреннего списка, например, подмножество https://tinyurl.com/q73okuc ),
    //дата рождения,    дата смерти (может отсутствовать, ситуация должна быть корректно обработана).
    enum PeopleRoles {
        NameRole = Qt::UserRole + 1,
        SexRole,
        AgeRole,
        GrowthRole,
        WeightRole,
        NationalityRole,
        BirthdayRole,
        DeathdayRole,
        StatusRole
    };

    NewPeopleModel(QObject *parent = nullptr);
    ~NewPeopleModel() {
        for (int i = 0; i < peoples.size(); i++)
            delete peoples.at(i);
    }
    QHash<int, QByteArray> roleNames() const;

    // QAbstractItemModel interface
public:
    QModelIndex index(int row, int column, const QModelIndex &/*parent*/) const;
    int rowCount(const QModelIndex &/*parent*/) const;
    QVariant data(const QModelIndex &index, int role) const;

    // other:
    void addPople(People* newPeople);
    QString name();
    void setName(QString name);

    Q_INVOKABLE void info();

private:
    QList<People*> peoples;
    People* curPeople;
    QString _name;
    int m_sex;
    uint _age;
    uint _weight;
    int m_nationality;
    QString m_birthday;
    QString m_deathday;
    QString _status;
    MySQLite* m_sql;
    int m_age;
    int m_growth;

    QDate curDate;

signals:
    void daysChanged();
    void sigName(QString);
    void menChanged(bool);
    void sigWeight(int);
    void sigNation(int);
    void sigSex();
    void sigSQL();
    void sigBirthday(QString);
    void sigDeathday(QString);
    void sigAge(int);
    void sigGrowth(int);
};
#endif // NEWPEOPLEMODEL_H
