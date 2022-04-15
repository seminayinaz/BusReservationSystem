#ifndef BUSRESERVATION_H
#define BUSRESERVATION_H

#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QStandardItemModel>
#include <QDate>
#include <QDateTimeEdit>
#include <QLineEdit>
#include <map>
#include <vector>
using namespace std;

class BusReservation
{
private:
    BusReservation(){}
    BusReservation(BusReservation const &){}
    static BusReservation * instance;

public:
    int PassengerInfo(QString name, QString surname, QString tcNo, QString mail, QString tel);
    int Check(int busId, QString TC, int seatNo);
    static BusReservation* getInstance();
    std::map<int,vector<int>> getBusList();
    std::vector<int> getBusNoList();

};


#endif // BUSRESERVATION_H
