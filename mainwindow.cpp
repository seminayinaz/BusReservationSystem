#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    new_user = new passenger();
    new_reservation = new Reservation();
    new_transaction = new Transaction();


    ui->label->setStyleSheet("QLabel {color: #00007f; font-family: Century Schoolbook}");
    //ui->reservasyonGoster->setStyleSheet("QLabel {font-family: Century Schoolbook}");
    //ui->pushButton_passenger->setStyleSheet("QLabel { font-family: Century Schoolbook}");
    //ui->pushButton_reserved->setStyleSheet("QLabel {color: #00007f; font-family: Century Schoolbook}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_passenger_clicked()
{
    new_user->show();
}


void MainWindow::on_pushButton_reserved_clicked()
{
    new_reservation->show();
}



void MainWindow::on_reservasyonGoster_clicked()
{
    new_transaction->show();
}

