
#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>



class dbmanager
{
public:
    dbmanager();
    bool conn();
    void disc();

    bool addPer(const QString& nom,const QString& prenom);
    bool delPer(const QString& id);
private:
    QSqlDatabase db;
};

#endif // DBMANAGER_H
