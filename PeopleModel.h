// https://doc.qt.io/qt-5/qtquick-modelviewsdata-cppmodels.html
// https://habr.com/ru/post/349822/
// https://doc.qt.io/qt-5/qjsengine.html

#ifndef PEOPLEMODEL_H
#define PEOPLEMODEL_H

#include <QAbstractListModel>
#include "People.h"

class MySQLite;

class PeopleModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(bool needSave READ needSave NOTIFY sigNeedSave)
    Q_PROPERTY(PeopleModel* objectForNewPeoples READ objectForNewPeoples WRITE setObjectForNewPeoples NOTIFY sigObjectForNewPeoples)
    Q_PROPERTY(int rowNewCount READ rowNewCount NOTIFY sigRowNewCount)
public:
    //имя, пол, возраст, рост, вес, национальность (выбор из внутреннего списка, например, подмножество https://tinyurl.com/q73okuc ),
    //дата рождения,    дата смерти (может отсутствовать, ситуация должна быть корректно обработана).
    enum PeopleRoles {
        NameRole = Qt::UserRole + 1,
        SexRole,
        AgeRole,
        WeightRole,
        NationalityRole,
        BirthdayRole,
        DeathdayRole,
        GrowthRole,
        StatusRole
    };
    bool needSave() {return m_needSave;}
    void testNeedSave() {
        m_needSave = newPeoples.size() > 0;
        sigRowNewCount(newPeoples.size());
        sigNeedSave(m_needSave);
    }

    PeopleModel(QObject *parent = nullptr);
    ~PeopleModel();
    QHash<int, QByteArray> roleNames() const;

    // QAbstractItemModel interface
public:
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    void setObjectForNewPeoples(PeopleModel* child);
    PeopleModel* objectForNewPeoples();

    // other:
    void addPeople(People* newPeople);
    void addPeople(int id, QString name, int id_sex, int weight, int id_nation, QString birthday, QString deathday, int age, int growth);
    Q_INVOKABLE void addNewPeople(QString name, int id_sex, int weight, int id_nation, QString birthday, QString deathday, int age, int growth);
    Q_INVOKABLE void saveToSQL(MySQLite* sql);
    int rowNewCount();

private:
    QList<People*> peoples;
    QList<People*> newPeoples;
    bool m_needSave = false;
    bool parent;
    PeopleModel* m_child;

signals:
    void sigNeedSave(bool);
    void sigObjectForNewPeoples(PeopleModel*);
    void sigRowNewCount(int);
};
#endif // PEOPLEMODEL_H
