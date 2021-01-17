#include "ui_mainwindow.h"
#include "progress_dialog.h"
#include "drawing_dialog.h"
#include "mainwindow.h"
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include "Toolfunction.h"

taxidata Tdata[10000000];
int num = 0;
double lng1, lng2;
double lat1, lat2;
int date_index[20];
QString message;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Chengdu Car-hailing Orders Analysis - File Selection");
    this->setWindowIcon(QIcon(":/Didi.jpg"));
    ui->pushButton->setEnabled(0);
    ui->pushButton_3->hide();
    ui->label_3->hide();
}


MainWindow::~MainWindow()
{
    delete ui;
}

QString path;

void MainWindow::on_pushButton_clicked()
{
    QDir dir(path);
    QStringList strlist = getFileNames(path);
    QFileInfoList infolist = getFileInfoList(dir,strlist);
    Progress_Dialog dia(infolist);
    dia.exec();
    ui->pushButton->hide();
    ui->label_3->show();
    ui->pushButton_3->show();
}



void MainWindow::on_pushButton_2_clicked()
{
    path = QFileDialog::getExistingDirectory(this, tr("Select the Dataset Folder"), "../", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->textEdit->setText(path);
    ui->pushButton->setEnabled(1);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->pushButton_3->setEnabled(0);
    this->hide();
    drawing_Dialog dra;
    dra.exec();
}
