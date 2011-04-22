#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "messageapi.h"

class QUdpSocket;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionConnect_triggered();

    void on_actionSend_triggered();

    void messageRecieved(UdpMessage*);
    void messengerServiceStarted(bool);

    void on_pushButton1_clicked();

private:
    Ui::MainWindow *ui;
    BroadcastService *messenger;

    void processTheDatagram(QByteArray datagram);
};

#endif // MAINWINDOW_H
