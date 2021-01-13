#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QString>
class DataBaseController
{
public:

    ~DataBaseController();
    static DataBaseController* GetInstance()
    {
        if(_instance == nullptr)
        {
            _instance = new DataBaseController();
        }
        return _instance;
    }
    void init(void);
    void CreateTable();
    void InsertData(QString date,QString time,float tem,float humidity);
    void QueryData();
    void DeleteData();
    void UpdateData();
private:
    QSqlDatabase database;
    static int id;
    DataBaseController();
    static DataBaseController* _instance;
};
#endif // DATABASECONTROLLER_H

