#include "busreservation.h"
#include "QDebug"
#include <iterator>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define hostName "localhost"
#define userName "postgres"
#define password "1234"
#define databaseName "bus"
#define database "QPSQL"


BusReservation* BusReservation::instance = nullptr;


int BusReservation::Check(int busId, QString TC, int seatNo)
{
    QSqlDatabase db = QSqlDatabase::addDatabase(database);
    db.setHostName(hostName);
    db.setUserName(userName);
    db.setPassword(password);
    db.setDatabaseName(databaseName);
    db.open();
    QSqlQuery query(db);


    query.prepare("insert into reserve (bus_id, tc, seat_no) values ('" + QString::number(busId) + "','" +  TC + "','" +  QString::number(seatNo) + "')");
    QString reserve;

    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
    {
        qDebug() << "Update was successful "<< query.lastQuery();
        reserve = query.lastInsertId().toString();
        qDebug() <<"Last Inserted Id is  : "<< reserve;
    }

    db.close();
    return 0;
}

BusReservation* BusReservation::getInstance()
{
    if(instance == nullptr)
        instance = new BusReservation();
    return instance;
}

int BusReservation::PassengerInfo(QString name, QString surname,QString tcNo, QString mail, QString tel){
    QSqlDatabase db3 = QSqlDatabase::addDatabase(database);
    db3.setHostName(hostName);
    db3.setUserName(userName);
    db3.setPassword(password);
    db3.setDatabaseName(databaseName);
    db3.open();
    QSqlQuery query(db3);

    query.prepare("insert into passenger (tc, name, last_name, mail, tel) values ('" +  tcNo + "','" + name + "','" +  surname + "','" + mail + "','" + tel + "')");
    QString passenger;
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
    {
        qDebug() << "Update was successful "<< query.lastQuery();
        passenger = query.lastInsertId().toString();
        qDebug() <<"Last Inserted Id is  : "<< passenger;
    }

    db3.close();
    return 0;
}


map<int,vector<int>> BusReservation::getBusList(){
    //Otobus id, koltuk no'ları map de tutar.
    map<int,vector<int>> Bus;
    QSqlDatabase db4 = QSqlDatabase::addDatabase(database);
    db4.setHostName(hostName);
    db4.setUserName(userName);
    db4.setPassword(password);
    db4.setDatabaseName(databaseName);
    db4.open();
    QSqlQuery query(db4);

    query = db4.exec("SELECT * FROM reserve;");
    while (query.next()) {
        QString busId = query.value(0).toString();
        QString seatNo = query.value(2).toString();


        if(Bus.find(busId.toInt()) == Bus.end())
            Bus[busId.toInt()] = vector<int>();

        Bus[busId.toInt()].push_back(seatNo.toInt());

    }
    db4.close();
    return Bus;

}
