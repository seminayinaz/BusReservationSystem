#include "Reservation.h"
#include "ui_Reservation.h"
using namespace std;
#define database "QPSQL"
#define hostName "localhost"
#define userName "postgres"
#define password "1234"
#define databaseName "bus"


Reservation::Reservation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reservation)
{
    ui->setupUi(this);

    new_seat = new Seat();

    this->ui->comboBox->addItem("Istanbul");
    this->ui->comboBox->addItem("Ankara");
    this->ui->comboBox->addItem("Izmir");
    this->ui->comboBox_2->addItem("Ankara");
    this->ui->comboBox_2->addItem("Izmir");
    this->ui->comboBox_2->addItem("Istanbul");

    ui->label->setStyleSheet("QLabel {color: #00007f; font-family: Century Schoolbook}");
    ui->label_11->setStyleSheet("QLabel {color: #00007f; font-family: Century Schoolbook}");
    ui->label_13->setStyleSheet("QLabel {color: #00007f; font-family: Century Schoolbook}");
    ui->label_14->setStyleSheet("QLabel {color: #00007f; font-family: Century Schoolbook}");
    ui->label_15->setStyleSheet("QLabel {color: #00007f; font-family: Century Schoolbook}");
    ui->label_16->setStyleSheet("QLabel {color: #00007f; font-family: Century Schoolbook}");
    ui->label_17->setStyleSheet("QLabel {color: #00007f; font-family: Century Schoolbook}");

}

void Reservation::on_seatState_clicked()
{
    new_seat->readData(this->ui->lineEdit_2->text().toInt());
    new_seat->show();

}


void Reservation::readData()
{
    map<int,vector<int>>Bus = BusReservation::getInstance()->getBusList();
    this->ui->lineEdit_3->clear();

}


Reservation::~Reservation()
{
    delete ui;
}


void Reservation::on_showTicket_clicked()
{
    QDate dates= this->ui->dateEdit->date();
    QString dateString = dates.toString("d.MM.yyyy");
    qDebug() << dateString;

    QStandardItemModel *model;
    QStringList horizontalHeader;
    QStringList verticalHeader;

    horizontalHeader.append("Otobus Numarasi");
    horizontalHeader.append("Kalkis Sehri");
    horizontalHeader.append("Varis Sehri");
    horizontalHeader.append("Tarih");
    horizontalHeader.append("Kalkis Saati");
    horizontalHeader.append("Ucret");
    model = new QStandardItemModel();

    model->setHorizontalHeaderLabels(horizontalHeader);
    model->setVerticalHeaderLabels(verticalHeader);

    this->ui->tableView->setModel(model);
    this->ui->tableView->verticalHeader()->setVisible(false);
    this->ui->tableView->verticalHeader()->setDefaultSectionSize(10);
    this->ui->tableView->setShowGrid(false);

    QSqlQuery query;
    QSqlDatabase db = QSqlDatabase::addDatabase(database);
    db.setHostName(hostName);
    db.setUserName(userName);
    db.setPassword(password);
    db.setDatabaseName(databaseName);
    db.open();
    query = db.exec("SELECT * FROM ticket;");
    qDebug() << this->ui->comboBox->currentText();
    qDebug() << this->ui->comboBox_2->currentText();

    while (query.next()) {
        QString busId = query.value(0).toString();
        QString departure = query.value(1).toString();
        QString arrival = query.value(2).toString();
        QString d_time = query.value(3).toString();
        QString a_time = query.value(4).toString();
        QString date = query.value(5).toString();
        QString price = query.value(6).toString();
        if(departure ==  this->ui->comboBox->currentText() and arrival == this->ui->comboBox_2->currentText() and dateString==date ){
            qDebug() << busId << departure << arrival << d_time<< a_time << date<< price;
            QStandardItem *col1 = new QStandardItem(busId);
            QStandardItem *col2 = new QStandardItem(departure);
            QStandardItem *col3 = new QStandardItem(arrival);
            QStandardItem *col4 = new QStandardItem(date);
            QStandardItem *col5 = new QStandardItem(d_time);
            QStandardItem *col6 = new QStandardItem(price);
            model->appendRow( QList<QStandardItem*>() << col1 << col2 << col3 << col4 << col5 << col6);
        }
    }
    db.close();


}

void Reservation::on_takeTicket_clicked()
{
    int bus = this->ui->lineEdit_2->text().toInt();
    QString TC = this->ui->lineEdit->text();
    int seat = this->ui->lineEdit_3->text().toInt();

    if(TC.length() != 11)
    {
            QMessageBox::information(
            this,
            tr("Error!"),
            tr("Kimlik bilgilerinizi dogru girdiginizden emin olun.") );
            return;
    }
    else {

        int ret = BusReservation::getInstance()->Check(bus, TC, seat);

        QString msg = "";
        ret==0?msg="Success!":"Failure!";

        this->hide();

        if(ret == 0)
        {
            QMessageBox::information(
            this,
            tr("Success!"),
            tr("Rezervasyonunuz olusturulmustur. Tekrar bekleriz :)") );
        }
    }

}

