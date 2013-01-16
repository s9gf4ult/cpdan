#include "dbmanager.h"

DBManager::DBManager()
{

}

void DBManager::createTables(QSqlDatabase *database) {
    if (database) {
        if (database->isOpen()) {
            QSqlQuery q = database->exec("create table portfolios ("
                                         "id integer primary key,"
                                         "name text unique not null,"
                                         "ticks boolean,"
                                         "candlebase text,"
                                         "candleseconds integer"
                                         ")");
            q.exec();




        }
    }
}
