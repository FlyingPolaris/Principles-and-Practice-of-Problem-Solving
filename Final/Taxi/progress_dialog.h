#ifndef PROGRESS_DIALOG_H
#define PROGRESS_DIALOG_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include "workerthread.h"

namespace Ui {
class Progress_Dialog;
}

class Progress_Dialog : public QDialog
{
    Q_OBJECT

public:
    Progress_Dialog(const QFileInfoList& infolist,QWidget *parent = nullptr);
    ~Progress_Dialog();
    WorkerThread* workthread;

private slots:
    void on_progressBar_valueChanged(int value);

private:
    Ui::Progress_Dialog *ui;
};

#endif // PROGRESS_DIALOG_H
