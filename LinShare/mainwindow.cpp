#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtNetwork/QtNetwork"
#include "QMessageBox"
#include "messageapi.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    messenger = new BroadcastService("255.255.255.255", 5684);

    connect(messenger, SIGNAL(OnMessageRecieved(UdpMessage*)),this, SLOT(messageRecieved(UdpMessage*)));
    //connect(messenger, SIGNAL(OnServiceStarted(bool)),this,SLOT(messengerServiceStarted(bool)));
    ui->pushButton1->setAutoDefault(true);
    ui->pushButton1->setDefault(true);
}

MainWindow::~MainWindow()
{
    //messenger->close();
    delete ui;
}

void MainWindow::on_actionConnect_triggered()
{
}

void MainWindow::on_actionSend_triggered()
{
    QString message = "Broadcast message: Hello!";
    //messenger->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, 5683);
    messenger->sendMessage(message, UdpMessage::Chat);
}

void MainWindow::messageRecieved(UdpMessage *message)
{
    if(message->MessageType == message->Chat){
        ui->textEdit->append(message->SenderUser->Username+":"+message->Message);
    } else if(message->MessageType == message->Whois) {
        //if(message->Message )
    }
}

void MainWindow::messengerServiceStarted(bool success){
    QMessageBox msgBox;
    if(success == true){
        msgBox.setText(tr("Service Started!"));
    } else {
        msgBox.setText(tr("Service Start Failed"));
    }
    msgBox.exec();
}

void MainWindow::on_pushButton1_clicked()
{
    if(ui->lineEdit->text() != "")
    {
        messenger->sendMessage(ui->lineEdit->text(), UdpMessage::Chat);
    }
}
