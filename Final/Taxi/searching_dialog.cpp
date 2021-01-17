#include "searching_dialog.h"
#include "ui_searching_dialog.h"
#include "Toolfunction.h"
#include "mainwindow.h"
#include "searchthread.h"

extern double lng1, lng2;
extern double lat1, lat2;
extern taxidata Tdata[10000000];
extern QString message;
searching_Dialog::searching_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searching_Dialog)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
    ui->setupUi(this);
    this->setWindowTitle("Chengdu Car-hailing Orders Analysis - Searching");
    ui->doubleSpinBox_a_lat->setMaximum(lat2);
    ui->doubleSpinBox_a_lat->setMinimum(lat1);
    ui->doubleSpinBox_d_lat->setMaximum(lat2);
    ui->doubleSpinBox_d_lat->setMinimum(lat1);
    ui->doubleSpinBox_a_lng->setMaximum(lng2);
    ui->doubleSpinBox_a_lng->setMinimum(lng1);
    ui->doubleSpinBox_d_lng->setMaximum(lng2);
    ui->doubleSpinBox_d_lng->setMinimum(lng1);
    ui->doubleSpinBox_a_lat->setSingleStep(0.01);
    ui->doubleSpinBox_d_lat->setSingleStep(0.01);
    ui->doubleSpinBox_a_lng->setSingleStep(0.01);
    ui->doubleSpinBox_d_lng->setSingleStep(0.01);
    ui->doubleSpinBox_d_lat->setValue(30.68595961);
    ui->doubleSpinBox_a_lat->setValue(30.71293922);
    ui->doubleSpinBox_d_lng->setValue(104.0338623);
    ui->doubleSpinBox_a_lng->setValue(104.0965897);
    ui->progressBar->setVisible(0);
}

searching_Dialog::~searching_Dialog()
{
    delete ui;
}

void searching_Dialog::on_pushButton_clicked()
{
    ui->textBrowser->clear();
    ui->textBrowser->append("            Order ID            / Departure Time /  Arrival Time  / Fee");
    double alat = ui->doubleSpinBox_a_lat->value();
    double alng = ui->doubleSpinBox_a_lng->value();
    double dlat = ui->doubleSpinBox_d_lat->value();
    double dlng = ui->doubleSpinBox_d_lng->value();
    Searchthread = new searchthread(dlng,dlat,alng,alat);
    Searchthread->createThread(dlng,dlat,alng,alat);
    connect(Searchthread,SIGNAL(changed(int)),ui->progressBar,SLOT(setValue(int)));
}

void searching_Dialog::on_progressBar_valueChanged(int value)
{
    if(value == 100)
    {
        ui->textBrowser->append(message);
        message.clear();
    }
    ui->textBrowser->moveCursor(QTextCursor::Start);
}
