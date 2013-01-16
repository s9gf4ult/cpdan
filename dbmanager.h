#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>

class DBManager
{
public:
    DBManager();

    static void createTables(QSqlDatabase *database);

};

#endif // DBMANAGER_H
