#include "Transaction.h"
#include "ui_Transaction.h"

#define database "QPSQL"
#define hostName "localhost"
#define userName "postgres"
#define password "1234"
#define databaseName "bus"

Transaction::Transaction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transaction)
{
    ui->setupUi(this);

    ui->label->setStyleSheet("QLabel {color: #00007f; font-family: Century Schoolbook}");
    ui->label_2->setStyleSheet("QLabel {color: #00007f; font-family: Century Schoolbook}");
}

Transaction::~Transaction()
{
    delete ui;
}

void Transaction::on_Login_clicked()
{
    QString loginName = this->ui->lineEdit->text();
    QString loginPassword = this->ui->lineEdit_2->text();
;

    if (loginName == "admin" and loginPassword == "1234"){
        QStandardItemModel *model;
        QStringList horizontalHeader;
        QStringList verticalHeader;

        horizontalHeader.append("ADI");
        horizontalHeader.append("SOYADI");
        horizontalHeader.append("OTOBUS NUMARASI");
        horizontalHeader.append("KOLTUK NUMARASI");
        horizontalHeader.append("UCRET");
        model = new QStandardItemModel();

        model->setHorizontalHeaderLabels(horizontalHeader);
        model->setVerticalHeaderLabels(verticalHeader);

        this->ui->tableView->setModel(model);
        this->ui->tableView->verticalHeader()->setVisible(false);
        this->ui->tableView->verticalHeader()->setDefaultSectionSize(20);
        this->ui->tableView->setShowGrid(false);

        QSqlQuery query;
        QSqlDatabase db = QSqlDatabase::addDatabase(database);
        db.setHostName(hostName);
        db.setUserName(userName);
        db.setPassword(password);
        db.setDatabaseName(databaseName);
        db.open();
        query = db.exec("SELECT passenger.name, passenger.last_name, reserve.bus_id, reserve.seat_no, ticket.price FROM ticket, reserve, passenger where passenger.tc = reserve.tc and reserve.bus_id = ticket.bus_id;");
        while (query.next()) {
            QString name = query.value(0).toString();
            QString surname = query.value(1).toString();
            QString busId = query.value(2).toString();
            QString seatNo = query.value(3).toString();
            QString price = query.value(4).toString();

            QStandardItem *col1 = new QStandardItem(name);
            QStandardItem *col2 = new QStandardItem(surname);
            QStandardItem *col3 = new QStandardItem(busId);
            QStandardItem *col4 = new QStandardItem(seatNo);
            QStandardItem *col5 = new QStandardItem(price);
            model->appendRow( QList<QStandardItem*>() << col1 << col2 << col3 << col4 << col5);
        }
        db.close();
    }

    else {
        QMessageBox::information(
        this,
        tr("Error!"),
        tr("Kullanici adi ya da sifrenizi dogru girdiginizden emin olun!") );
        return;
    }

}

