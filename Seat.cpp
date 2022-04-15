#include "Seat.h"
#include "ui_Seat.h"
#include <map>
#include <vector>

using namespace std;
Seat::Seat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Seat)
{
    ui->setupUi(this);
}

Seat::~Seat()
{
    delete ui;
}


void Seat::readData(int bus){
    map<int,vector<int>> Bus = BusReservation::getInstance()->getBusList();
    ui->lblinfo->setStyleSheet("QLabel { background-color : red; font-family: Century Schoolbook}");
    ui->label->setStyleSheet("QLabel { background-color : #e0ffde;font-family: Century Schoolbook}");

    std::vector<int>seatNumber =  {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};

    for(std::vector<int>::iterator it = seatNumber.begin(); it!=seatNumber.end(); it++ )
    {
        //Etiketlerin renklerini degistirir.
        QString lblname = "lbl" + QString::number(*it);
        QLabel * ptr = this->findChild<QLabel*>(lblname);

        if(ptr)
        {
            ptr->setStyleSheet("QLabel { background-color : #e0ffde; font-family: Century Schoolbook}");
        }

    }
    for(auto& busIdSeatNo : Bus) {
            qDebug() << "bus_id_seat_no: " << busIdSeatNo.first << "\ncourses:\n";
            for(auto& seat_no : busIdSeatNo.second)
              qDebug() << seat_no << ", ";
            qDebug() << '\n';
    }

    for(auto& busIdSeatNo : Bus) {
        if (busIdSeatNo.first == bus){
            for(auto& seat_no : busIdSeatNo.second){
                QString lblname = "lbl" + QString::number(seat_no);
                QLabel * ptr = this->findChild<QLabel*>(lblname);

                if(ptr)
                {
                    ptr->setStyleSheet("QLabel { background-color : red; font-family: Century Schoolbook}");
                }
             }

        }
    }

}


void Seat::on_pushButton_clicked()
{
    this->hide();

}
