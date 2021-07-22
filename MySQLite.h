#ifndef MYSQLITE_H
#define MYSQLITE_H

#include <QQuickItem>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>

class ComboBoxModel;
class PeopleModel;

class MySQLite : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString file READ file WRITE setFile)

    enum People{id = 0, name, id_sex, weight, id_nation, birthday, deathday, age, growth};

public:
    MySQLite(QQuickItem *parent = nullptr);
    ~MySQLite();
    bool exec(QString req);
    QSqlQuery select (QString req);
    Q_INVOKABLE bool createStruct();
    Q_INVOKABLE void populateComboBox(ComboBoxModel *model, QString table, QString key, QString value);
    Q_INVOKABLE void populatePeopleModel(PeopleModel* model);
    Q_INVOKABLE bool addPeople(QString name, int sex, int weight, int id_nation, QString birthday, QString deathday, int age, int growth);

    void componentComplete();

private:
    void setFile(QString file);
    QString file();
    QSqlDatabase db;
    bool status;
    QString DBName;

signals:
    void connected();
};

#endif // MYSQLITE_H
