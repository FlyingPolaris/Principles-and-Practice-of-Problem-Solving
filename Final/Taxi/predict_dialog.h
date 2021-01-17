#ifndef PREDICT_DIALOG_H
#define PREDICT_DIALOG_H

#include <QDialog>

namespace Ui {
class Predict_Dialog;
}

class Predict_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Predict_Dialog(QWidget *parent = nullptr);
    ~Predict_Dialog();

private:
    Ui::Predict_Dialog *ui;
};

#endif // PREDICT_DIALOG_H
