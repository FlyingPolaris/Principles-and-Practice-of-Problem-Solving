#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QtCharts>

int hour[24] = {0};
QChartView *chartView;
QChart *chart;
QLineSeries *series;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    chartView = new QChartView(this);
    chart = new QChart();
    chart->setTitle("The Line Chart of Taxi Demands over Time in Chengdu");
    QFont titlefont;
    titlefont.setFamily("Consolas");
    chart->setTitleFont(titlefont);
    chartView->setChart(chart);
    chartView->adjustSize();
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->move(60,160);
    chartView->resize(800,600);
    chartView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    for(int i=0;i<24;++i)
    {
        hour[i] = 0;
    }
    QString path = QFileDialog::getOpenFileName(this,"open","../","CSV(*.csv)");
    if (path.isEmpty() == false)
    {
        QFile file (path);
        bool isOk =file.open(QIODevice::ReadOnly);
        if (isOk)
        {
            QByteArray array ;
            while (file.atEnd() == false)
            {
                array = file.readLine();
                char* str = array.data();
                if(str[0] < '0' || str[0] > '9') continue;
                ui->textEdit->setText(array);
                int Hour = 0;
                int DATA = 0;
                int i=0;
                while(str[i]!=',')
                {
                    Hour *=10;
                    Hour += str[i] - '0';
                    ++i;
                }
                ++i;
                while(str[i] != '\n')
                {
                    DATA*=10;
                    DATA+= str[i] - '0';
                    ++i;
                }
                hour[Hour] = DATA;
            }
        }
        file.close();
        QFileInfo info(path);
        ui->textEdit->setText(info.fileName());
    }
}



void MainWindow::on_pushButton_2_clicked()
{
    int start = ui->spinBox->value();
    int end = ui->spinBox_2->value();
    series = new QLineSeries();
    QVector<QPointF> points;
    for(int i = start;i <= end;++i)
    {
        points.append(QPointF(i,hour[i]));
    }
    chart->legend()->hide();
    series->replace(points);
    chart->addSeries(series);
    series->setUseOpenGL(true);
    chart->createDefaultAxes();
    QFont titlefont;
    titlefont.setFamily("Consolas");
    chart->axes(Qt::Horizontal).back()->setRange(start,end);
    chart->axes(Qt::Horizontal).back()->setTitleText("Time (hour)");
    chart->axes(Qt::Horizontal).back()->setTitleFont(titlefont);
    chart->axes(Qt::Vertical).back()->setRange(0, 15000);
    chart->axes(Qt::Vertical).back()->setTitleText("Taxi Demands (num)");
    chart->axes(Qt::Vertical).back()->setTitleFont(titlefont);
    QValueAxis *axisX = qobject_cast<QValueAxis*>(chart->axes(Qt::Horizontal).first());
    QValueAxis *axisY = qobject_cast<QValueAxis*>(chart->axes(Qt::Vertical).first());
    axisX->setLabelFormat("%d");
    axisX->setTickCount((end - start) + 1);
    axisY->setLabelFormat("%d");
    chartView->show();
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->spinBox_2->setMinimum(arg1 + 1);
}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    ui->spinBox->setMaximum(arg1 - 1);
}
