#include "passenger.h"
#include "ui_passenger.h"

passenger::passenger(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::passenger)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("QLabel {color: #00007f; font-family: Century Schoolbook}");
    ui->label_2->setStyleSheet("QLabel {color: #00007f; font-family: Century Schoolbook}");
    ui->label_3->setStyleSheet("QLabel {color: #00007f; font-family: Century Schoolbook}");
    ui->label_4->setStyleSheet("QLabel {color: #00007f; font-family: Century Schoolbook}");
    ui->label_5->setStyleSheet("QLabel {color: #00007f; font-family: Century Schoolbook}");

}

passenger::~passenger()
{
    delete ui;
}

void passenger::on_addPassenger_clicked()
{
    QString TC = this->ui->lineEdit->text();
    QString name = this->ui->lineEdit_2->text();
    QString surname = this->ui->lineEdit_3->text();
    QString mail = this->ui->lineEdit_4->text();
    QString tel = this->ui->lineEdit_5->text();

    if(TC.length() == 11 and tel.length() == 11){
        int ret = BusReservation::getInstance()->PassengerInfo(name, surname, TC,  mail, tel);

        QString msg = "";
        ret==0?msg="Success!":"Failure!";

        this->hide();

        if(ret == 0)
        {
            QMessageBox::information(
            this,
            tr("Success!"),
            tr("Kaydiniz olusturulmustur.") );
        }

    }
    else {
        QMessageBox::information(
        this,
        tr("Error!"),
        tr("Bilgilerinizi doğru girdiğinizden emin olun.") );

    }

}

