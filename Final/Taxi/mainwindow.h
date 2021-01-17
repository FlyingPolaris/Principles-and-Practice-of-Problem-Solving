#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "workerthread.h"
#include <QMainWindow>
#include <QThread>
#include <QDateTime>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct taxidata
{
    std::string order_id;
    QDateTime Departure_time;
    QDateTime End_time;
    double orig_lng;
    double orig_lat;
    qint64 Departure_Location_num;
    qint64 End_Location_num;
    double dest_lng;
    double dest_lat;
    double fee;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    WorkerThread* workthread;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
