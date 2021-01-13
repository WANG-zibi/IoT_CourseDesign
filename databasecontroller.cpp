#include "databasecontroller.h"
#include <QtDebug>
DataBaseController* DataBaseController::_instance = nullptr;
int DataBaseController::id = 0;
DataBaseController::DataBaseController()
{

}

void DataBaseController::init()
{
    QSqlDatabase database;

    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("MyDataBase.db");
        database.setUserName("WKNTXDY");
        database.setPassword("wkntxdy666");
    }

    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
    }
    else
    {
        qDebug() <<"database is open!";

    }
    CreateTable();
}

void DataBaseController::CreateTable()
{
    QSqlQuery sql_query;
    QString create_sql = "create table Tem (id INTEGER,date TEXT,time TEXT,tem REAL, humidity REAl)";
    sql_query.prepare(create_sql);
    if(!sql_query.exec())
    {
        qDebug() << "Error: Fail to create table." << sql_query.lastError();
    }
    else
    {
        qDebug() << "Table created!";
    }
}

void DataBaseController::InsertData(QString date,QString time,float tem,float humidity)
{
QSqlQuery sql_query;
    QString insert_sql = "insert into Tem values (?,?, ?, ?, ?)";
    sql_query.prepare(insert_sql);
    sql_query.addBindValue(id++);
    sql_query.addBindValue(date);
    sql_query.addBindValue(time);
    sql_query.addBindValue(tem);
    sql_query.addBindValue(humidity);
    if(!sql_query.exec())
    {
        qDebug() << sql_query.lastError();
    }
    else
    {
        qDebug() << "inserted!";
    }
}

void DataBaseController::QueryData()
{
    QSqlQuery sql_query;
    QString select_all_sql = "select * from Tem";
    sql_query.prepare(select_all_sql);
    if(!sql_query.exec())
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        while(sql_query.next())
        {
            //to do something
//            int id = sql_query.value(0).toInt();
//            QString name = sql_query.value(1).toString();
//            int age = sql_query.value(2).toInt();
//            qDebug()<<QString("id:%1    name:%2    age:%3").arg(id).arg(name).arg(age);
        }
    }
}

DataBaseController::~DataBaseController()
{
    if(database.open())
    {
        database.close();
    }
}
