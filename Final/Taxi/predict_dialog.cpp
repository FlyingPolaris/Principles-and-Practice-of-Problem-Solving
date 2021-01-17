#include "predict_dialog.h"
#include "ui_predict_dialog.h"

Predict_Dialog::Predict_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Predict_Dialog)
{
    ui->setupUi(this);
}

Predict_Dialog::~Predict_Dialog()
{
    delete ui;
}
