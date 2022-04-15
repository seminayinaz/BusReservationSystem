#ifndef SEAT_H
#define SEAT_H

#include <QWidget>
#include <QDialog>
#include <QDebug>
#include "busreservation.h"
#include <vector>
//#include "Reservation.h"
#include <map>

namespace Ui {
class Seat;
}

class Seat : public QWidget
{
    Q_OBJECT

public:
    explicit Seat(QWidget *parent = nullptr);
    ~Seat();
    void readData(int bus);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Seat *ui;
};

#endif // SEAT_H
