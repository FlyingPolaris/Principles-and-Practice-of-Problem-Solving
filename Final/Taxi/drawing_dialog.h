#ifndef DRAWING_DIALOG_H
#define DRAWING_DIALOG_H

#include <QDialog>

namespace Ui {
class drawing_Dialog;
}

class drawing_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit drawing_Dialog(QWidget *parent = nullptr);
    ~drawing_Dialog();   

private slots:
    void on_dateTimeEdit_2_dateTimeChanged(const QDateTime &dateTime);

    void on_comboBox_currentIndexChanged(int index);


    void on_pushButton_clicked();

    void on_radioButton_pressed();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime);

private:
    Ui::drawing_Dialog *ui;
};

#endif // DRAWING_DIALOG_H
