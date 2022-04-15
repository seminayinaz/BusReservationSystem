#ifndef PASSENGER_H
#define PASSENGER_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QStandardItemModel>
#include <QDialog>
#include <QtDebug>
#include <QMessageBox>
#include <QLineEdit>
#include "busreservation.h"
namespace Ui {
class passenger;
}

class passenger : public QWidget
{
    Q_OBJECT

public:
    explicit passenger(QWidget *parent = nullptr);
    ~passenger();

private slots:
    void on_addPassenger_clicked();

private:
    Ui::passenger *ui;
};

#endif // PASSENGER_H
