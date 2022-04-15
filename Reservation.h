#ifndef RESERVATION_H
#define RESERVATION_H

#include <QWidget>
#include "Seat.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QStandardItemModel>
#include <QDate>
#include <QDateTimeEdit>
#include <QLineEdit>
#include <vector>

#include "busreservation.h"

namespace Ui {
class Reservation;
}

class Reservation : public QWidget
{
    Q_OBJECT

public:
    explicit Reservation(QWidget *parent = nullptr);
    ~Reservation();
    void readData();

private slots:
    void on_seatState_clicked();
    void on_showTicket_clicked();
    void on_takeTicket_clicked();

private:
    Ui::Reservation *ui;

    Seat *new_seat;
};

#endif // RESERVATION_H
