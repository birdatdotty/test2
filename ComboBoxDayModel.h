#ifndef COMBOBOXDATEMODEL_H
#define COMBOBOXDATEMODEL_H
// https://blog.altuninvv.ru/программирование/qt5/модели/54-qcombobox-работа-с-моделями-в-qt5-для-отображения-данных-в-виджетах

#include <QAbstractListModel>
#include <QDate>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>

class MySQLite;

class ComboBoxDayModel:
        public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int year READ year WRITE setYear NOTIFY sigYear)
    Q_PROPERTY(int month READ month WRITE setMonth NOTIFY sigMonth)
    Q_PROPERTY(int day READ day WRITE setDay NOTIFY dayChanged)
    Q_PROPERTY(QString result READ result NOTIFY resultChanged)
    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)

public:
    enum MyRoles {NUM, TXT};
    ComboBoxDayModel(QObject *parent=nullptr);

    Q_INVOKABLE int updateDay(int day);
    Q_INVOKABLE void info();

    void setYear(int year);
    int year() { return m_year; }
    void setMonth(int month);
    int month() { return m_month; }
    void setDay(int day);
    int day();
    QString result();
    bool active();
    void setActive (bool active);

    int rowCount(const QModelIndex &) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    Q_INVOKABLE int testMin(int a, int min);

private:
    int m_year;
    int m_month;
    int m_day;
    bool m_active;
    MySQLite* m_sql;

signals:
    void dayChanged(int);
    void resultChanged();
    void activeChanged(bool);
    void sigMonth(int);
    void sigYear(int);
    void sigDay(int);

    // QAbstractItemModel interface
public:
    QHash<int, QByteArray> roleNames() const override;
};

#endif // COMBOBOXDATEMODEL_H
