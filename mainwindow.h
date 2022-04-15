#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "passenger.h"
#include "Reservation.h"
#include "Seat.h"
#include "Transaction.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_passenger_clicked();
    void on_pushButton_reserved_clicked();
    void on_reservasyonGoster_clicked();

private:
    Ui::MainWindow *ui;

    passenger *new_user;
    Reservation *new_reservation;
    Transaction *new_transaction;

};
#endif // MAINWINDOW_H
