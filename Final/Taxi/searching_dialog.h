#ifndef SEARCHING_DIALOG_H
#define SEARCHING_DIALOG_H

#include <QDialog>
#include "searchthread.h"
namespace Ui {
class searching_Dialog;
}

class searching_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit searching_Dialog(QWidget *parent = nullptr);
    ~searching_Dialog();


private slots:
    void on_pushButton_clicked();

    void on_progressBar_valueChanged(int value);

private:
    Ui::searching_Dialog *ui;
    searchthread* Searchthread;
};

#endif // SEARCHING_DIALOG_H
