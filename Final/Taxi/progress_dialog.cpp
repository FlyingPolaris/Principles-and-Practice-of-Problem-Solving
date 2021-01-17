#include "progress_dialog.h"
#include "ui_progress_dialog.h"
#include <QTimer>
Progress_Dialog::Progress_Dialog(const QFileInfoList& infolist,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Progress_Dialog)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    //flags |=Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
    ui->setupUi(this);
    this->setWindowTitle("Chengdu Car-hailing Orders Analysis - Loading");
    workthread = new WorkerThread(infolist, this);
    workthread->createThread(infolist);
    connect(workthread,SIGNAL(changed(int)),ui->progressBar,SLOT(setValue(int)));
}

Progress_Dialog::~Progress_Dialog()
{
    delete ui;
}

void Progress_Dialog::on_progressBar_valueChanged(int value)
{
    if((value/6)%3 == 0) ui->label_2->setText("Please wait for the data loading to complete .");
    else if((value/6)%3 == 1)ui->label_2->setText("Please wait for the data loading to complete . .");
    else if((value/6)%3 == 2)ui->label_2->setText("Please wait for the data loading to complete . . .");
    if(value == 100)
    {
        this->accept();
    }
}
