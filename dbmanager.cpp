
#include "dbmanager.h"
#include <QDebug>
#include <QSqlQuery>

dbmanager::dbmanager()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("plane");
    db.setUserName("root");
    db.setPassword("root");
}

bool dbmanager::conn()
{
    return db.open();
}

void dbmanager::disc()
{
    db.close();
}

bool dbmanager::addPer(const QString &nom, const QString &prenom)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO personne (`id`, `nom`, `prenom`) VALUES (NULL, :nom, :prenom)");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);

    qDebug() << "Executing " << nom;
    if(query.exec())
    {
        return true;
    }
    else
    {
        qDebug() << "Error\n" ;
    }
    return false;
}

bool dbmanager::delPer(const QString &id)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM personne WHERE id=:id");
    query.bindValue(":id", id);


    qDebug() << "Executing " << id;
    if(query.exec())
    {
        return true;
    }
    else
    {
        qDebug() << "Error\n" ;
    }
    return false;
}

