#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QWidget>
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


namespace Ui {
class Transaction;
}

class Transaction : public QWidget
{
    Q_OBJECT

public:
    explicit Transaction(QWidget *parent = nullptr);
    ~Transaction();

private slots:
    void on_Login_clicked();

private:
    Ui::Transaction *ui;
};

#endif // TRANSACTION_H
