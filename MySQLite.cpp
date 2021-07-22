#include "ComboBoxModel.h"
#include "MySQLite.h"
#include "PeopleModel.h"

#include <QStandardPaths>
#include <QDir>

MySQLite::MySQLite(QQuickItem *parent)
    : QQuickItem(parent)
{
}

MySQLite::~MySQLite()
{
    if (status)
        db.close();
}

bool MySQLite::exec(QString req) {
    if (!status)
        return false;

    QSqlQuery query{db};
    return query.exec(req);
}

QSqlQuery MySQLite::select(QString req) {
    if (!status)
        return QSqlQuery{};

    QSqlQuery query{db};

    query.exec(req);
    return query;
}

bool MySQLite::createStruct()
{
    bool status;
    status = exec("CREATE TABLE people ("
             "id INTEGER PRIMARY KEY AUTOINCREMENT,"
             "name text NOT NULL,"
             "id_sex INTEGER NOT NULL,"
             "age INTEGER NOT NULL,"
             "growth INTEGER NOT NULL,"
             "weight INTEGER NOT NULL,"
             "id_nation INTEGER NOT NULL,"
             "birthday text NOT NULL,"
             "deathday text"
           ");");
    status = exec("CREATE TABLE nations ("
             "id INTEGER PRIMARY KEY AUTOINCREMENT,"
             "nation text NOT NULL"
           ");");
    if (!status)
        return status;

    status = exec("CREATE TABLE sex ("
             "id INTEGER PRIMARY KEY AUTOINCREMENT,"
             "sex text NOT NULL,"
             "txt text NOT NULL"
           ");");
    if (!status)
        return status;

    if (!status)
        return status;

    status = exec("INSERT INTO sex (sex, txt)"
             "VALUES"
             "('male', 'муж.'),"
           "('famale', 'жен.');");
    if (!status)
        return status;

    status = exec("INSERT INTO nations (nation) VALUES ('Русские'), ('Татары'), ('Украинцы'), ('Башкиры'), ('Чуваши'), ('Чеченцы'), ('Армяне'), ('Аварцы'), ('Мордва'), ('Казахи'), ('Азербайджанцы'), ('Даргинцы'), ('Удмурты'), ('Марийцы'), ('Осетины'), ('Белорусы'), ('Кабардинцы'), ('Кумыки'), ('Якуты'), ('Лезгины'), ('Буряты'), ('Ингуши'), ('Немцы'), ('Узбеки'), ('Тувинцы'), ('Коми'), ('Карачаевцы'), ('Цыгане'), ('Таджики'), ('Калмыки'), ('Лакцы'), ('Грузины'), ('Евреи'), ('Молдаване'), ('Корейцы'), ('Табасараны'), ('Адыгейцы'), ('Балкарцы'), ('Турки'), ('Ногайцы'), ('Киргизы'), ('Коми-пермяки'), ('Греки'), ('Алтайцы'), ('Черкесы'), ('Хакасы'), ('Казаки'), ('Карелы'), ('Мордва-эрзя'), ('Поляки'), ('Ненцы'), ('Абазины'), ('Езиды'), ('Эвенки'), ('Туркмены'), ('Рутульцы'), ('Кряшены'), ('Агулы'), ('Литовцы'), ('Ханты'), ('Китайцы'), ('Болгары'), ('Горные марийцы'), ('Курды'), ('Эвены'), ('Финны'), ('Латыши'), ('Эстонцы'), ('Чукчи'), ('Вьетнамцы'), ('Гагаузы'), ('Шорцы'), ('Цахуры'), ('Манси'), ('Нанайцы'), ('Андийцы'), ('Дидойцы'), ('Абхазы'), ('Ассирийцы'), ('Арабы'), ('Нагайбаки'), ('Коряки'), ('Ахвахцы'), ('Долганы'), ('Сибирские татары'), ('Коми-ижемцы'), ('Бежтинцы'), ('Вепсы'), ('Пуштуны (афганцы)'), ('Турки-месхетинцы'), ('Каратинцы'), ('Мордва-мокша'), ('Нивхи'), ('Удины'), ('Индийцы (хинди)'), ('Шапсуги'), ('Теленгиты'), ('Персы'), ('Уйгуры'), ('Селькупы'), ('Сойоты'), ('Сербы'), ('Ботлихцы'), ('Румыны'), ('Ительмены'), ('Поморы'), ('Монголы'), ('Кумандинцы'), ('Венгры'), ('Ульчи'), ('Телеуты'), ('Талыши'), ('Крымские татары'), ('Бесермяне'), ('Хемшилы'), ('Тубалары'), ('Камчадалы'), ('Чехи'), ('Тоджинцы (тыва-тоджинцы)'), ('Саамы'), ('Эскимосы'), ('Дунгане'), ('Юкагиры'), ('Таты'), ('Американцы США'), ('Удэгейцы'), ('Французы'), ('Каракалпаки'), ('Итальянцы'), ('Кеты'), ('Челканцы'), ('Испанцы'), ('Латгальцы'), ('Чуванцы'), ('Британцы'), ('Гунзибцы'), ('Японцы'), ('Нганасаны'), ('Мишари'), ('Горские евреи (таты-иудаисты)'), ('Тофалары'), ('Кубинцы'), ('Тиндалы'), ('Мегрелы'), ('Орочи'), ('Хваршины'), ('Негидальцы'), ('Пакистанцы'), ('Алеуты'), ('Гинухцы'), ('Финны-ингерманландцы'), ('Годоберинцы'), ('Бангладешцы'), ('Памирцы'), ('Чулымцы'), ('Ланкийцы'), ('Македонцы'), ('Словаки'), ('Хорваты'), ('Ульта(ороки)'), ('Тазы (удэ)'), ('Ижорцы'), ('Боснийцы'), ('Энцы'), ('Русины'), ('Осетины-дигорцы'), ('Лугово-восточные марийцы'), ('Сету'), ('Аджарцы'), ('Караимы'), ('Черногорцы'), ('Лазы'), ('Кубачинцы'), ('Ингилойцы'), ('Крымчаки'), ('Грузинские евреи'), ('Чеченцы-аккинцы'), ('Водь'), ('Среднеазиатские цыгане'), ('Осетины-иронцы'), ('Сваны'), ('Курманч (курмандж)'), ('Среднеазиатские евреи'), ('Чамалалы'), ('Карагаши'), ('Арчинцы'), ('Кайтагцы'), ('Астраханские татары'), ('Черкесогаи'), ('Багулалы'), ('Кереки'), ('Меннониты'), ('Греки-урумы'), ('Юги');");
    return status;
}

void MySQLite::setFile(QString file) {
    DBName = file;
}

QString MySQLite::file()
{
    return DBName;
}

void MySQLite::componentComplete()
{
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    QString p = path + QDir::separator() + DBName;
    QDir(path).mkpath(path);
    qInfo() << p;
    qInfo() << p.toLatin1();
    db = QSqlDatabase::addDatabase("QSQLITE", p.toLatin1());
    db.setDatabaseName(DBName);
    status = db.open();
    if (status)
        connected();
}

void MySQLite::populateComboBox(ComboBoxModel *model, QString table, QString key, QString value)
{
    QString query = "SELECT " + key + ", " + value + " FROM " +table;
    QSqlQuery res = select(query);

    model->startReset();
    while (res.next()) {
        int id = res.value(0).toInt();
        QString value = res.value(1).toString();

        model->add(id, value);
    }


    model->endReset();
}

void MySQLite::populatePeopleModel(PeopleModel *model)
{
    int     id,
            id_sex,
            weight,
            id_nation,
            age,
            growth;

    QString name,
            birthday,
            deathday;

    QSqlQuery res = select("SELECT "
                           "id," // 0
                           "name," // 1
                           "id_sex," // 2
                           "weight," // 3
                           "id_nation," // 4
                           "birthday," // 5
                           "deathday," // 6
                           "age," // 7
                           "growth" // 8
                           " FROM people");
    while (res.next()) {
        id = res.value(0).toInt();
        name = res.value(1).toString();
        id_sex = res.value(2).toInt();
        weight = res.value(3).toInt();
        id_nation = res.value(4).toInt();
        birthday = res.value(5).toString();
        deathday = res.value(6).toString();
        age = res.value(7).toInt();
        growth = res.value(8).toInt();

        model->addPeople(id, name, id_sex, weight, id_nation, birthday, deathday, age, growth);
    }


}

bool MySQLite::addPeople(QString name, int id_sex, int weight, int id_nation, QString birthday, QString deathday, int age, int growth)
{
    QString tmp = "INSERT INTO people(name, id_sex, weight, id_nation,"
                                    " birthday, deathday, age, growth) VALUES "
                                    "('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8')";

    return exec(tmp.arg(name).arg(id_sex).arg(weight).arg(id_nation).arg(birthday).arg(deathday).arg(age).arg(growth));
}
