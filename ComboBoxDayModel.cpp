#include "ComboBoxDayModel.h"

void ComboBoxDayModel::setYear(int year) {
    beginResetModel();
    m_year = year;
    endResetModel();

    dayChanged(m_day);
    sigYear(year);
    resultChanged();
}

void ComboBoxDayModel::setMonth(int month) {
    beginResetModel();
    m_month = month;
    endResetModel();

    sigMonth(m_month);
    resultChanged();
}

ComboBoxDayModel::ComboBoxDayModel(QObject *parent)
    : QAbstractListModel(parent),
      m_year(1900),
      m_month(1)
{
}

int ComboBoxDayModel::updateDay(int day) {
    if (day < 1)
        return 1;

    QDate date(m_year,m_month,1);
    if (day > date.daysInMonth())
        return date.daysInMonth();
    else
        return day;
}

void ComboBoxDayModel::setDay(int day) {
    QDate date(m_year,m_month,1);
    if (day > date.daysInMonth())
        m_day = date.daysInMonth();
    else
        m_day = day;

    dayChanged(m_day);
    sigDay(m_day);

    resultChanged();
}

int ComboBoxDayModel::day() {
    return m_day;
}

QString ComboBoxDayModel::result() {
    if (!m_active)
        return "";

    QString ret = "%1.%2.%3";
    return ret.arg(m_day).arg(m_month).arg(m_year);;
}

bool ComboBoxDayModel::active() {
    return m_active;
}

void ComboBoxDayModel::setActive(bool active) {
    m_active = active;
    activeChanged(active);
    resultChanged();
}

int ComboBoxDayModel::rowCount(const QModelIndex &) const {
    QDate date(m_year,m_month,1);
    return date.daysInMonth();
}

QVariant ComboBoxDayModel::data(const QModelIndex &index, int role) const {
    QVariant value;
    if (!index.isValid())
        return value;

    if ( role == Qt::DisplayRole || MyRoles::NUM || MyRoles::TXT)
        return index.row()+1;

    return value;
}

int ComboBoxDayModel::testMin(int a, int min) {
    if (a >= min) return a;
    return min;
}

QHash<int, QByteArray> ComboBoxDayModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[MyRoles::NUM] = "num";
    roles[MyRoles::TXT] = "txt";

    return roles;
}

void ComboBoxDayModel::info() {
    qInfo() << "m_year:" << m_year;
    qInfo() << "m_month:" << m_month;
    if (QDate::isLeapYear(m_year))
        qInfo() << "высокосный";
    else
        qInfo() << "не высокосный";

    QString str = "%1.%2.%3";
    qInfo() << str.arg(m_day).arg(m_month).arg(m_year);
}


