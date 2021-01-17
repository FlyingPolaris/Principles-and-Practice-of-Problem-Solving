#include "drawing_dialog.h"
#include "ui_drawing_dialog.h"

#include "mainwindow.h"
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QDateTimeEdit>
#include <QMouseEvent>
#include <QButtonGroup>
#include <QPainter>
#include <QtCharts>
#include "searching_dialog.h"

QPainter* painter;
QButtonGroup* CBgroup;

QChartView *chartView;
QChart *chart;

drawing_Dialog::drawing_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::drawing_Dialog)
{
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
    ui->setupUi(this);
    this->setWindowTitle("Chengdu Car-hailing Orders Analysis - Drawing");
    chart = new QChart();
    chartView = new QChartView(this);
    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->move(540,120);
    chartView->resize(1000,800);
    chartView->show();
    //ui->dateTimeEdit->setCalendarPopup(1);
    //ui->dateTimeEdit_2->setCalendarPopup(1);
    CBgroup = new QButtonGroup;
    CBgroup->setExclusive(0);
    CBgroup->addButton(ui->CHB01,1);
    CBgroup->addButton(ui->CHB02,2);
    CBgroup->addButton(ui->CHB03,3);
    CBgroup->addButton(ui->CHB04,4);
    CBgroup->addButton(ui->CHB05,5);
    CBgroup->addButton(ui->CHB06,6);
    CBgroup->addButton(ui->CHB07,7);
    CBgroup->addButton(ui->CHB08,8);
    CBgroup->addButton(ui->CHB09,9);
    CBgroup->addButton(ui->CHB10,10);
    CBgroup->addButton(ui->CHB11,11);
    CBgroup->addButton(ui->CHB12,12);
    CBgroup->addButton(ui->CHB13,13);
    CBgroup->addButton(ui->CHB14,14);
    CBgroup->addButton(ui->CHB15,15);
    CBgroup->addButton(ui->CHB16,16);
    CBgroup->addButton(ui->CHB17,17);
    CBgroup->addButton(ui->CHB18,18);
    CBgroup->addButton(ui->CHB19,19);
    CBgroup->addButton(ui->CHB20,20);
    CBgroup->addButton(ui->CHB21,21);
    CBgroup->addButton(ui->CHB22,22);
    CBgroup->addButton(ui->CHB23,23);
    CBgroup->addButton(ui->CHB24,24);
    CBgroup->addButton(ui->CHB25,25);
    CBgroup->addButton(ui->CHB26,26);
    CBgroup->addButton(ui->CHB27,27);
    CBgroup->addButton(ui->CHB28,28);
    CBgroup->addButton(ui->CHB29,29);
    CBgroup->addButton(ui->CHB30,30);
    CBgroup->addButton(ui->CHB31,31);
    CBgroup->addButton(ui->CHB32,32);
    CBgroup->addButton(ui->CHB33,33);
    CBgroup->addButton(ui->CHB34,34);
    CBgroup->addButton(ui->CHB35,35);
    CBgroup->addButton(ui->CHB36,36);
    CBgroup->addButton(ui->CHB37,37);
    CBgroup->addButton(ui->CHB38,38);
    CBgroup->addButton(ui->CHB39,39);
    CBgroup->addButton(ui->CHB40,40);
    CBgroup->addButton(ui->CHB41,41);
    CBgroup->addButton(ui->CHB42,42);
    CBgroup->addButton(ui->CHB43,43);
    CBgroup->addButton(ui->CHB44,44);
    CBgroup->addButton(ui->CHB45,45);
    CBgroup->addButton(ui->CHB46,46);
    CBgroup->addButton(ui->CHB47,47);
    CBgroup->addButton(ui->CHB48,48);
    CBgroup->addButton(ui->CHB49,49);
    CBgroup->addButton(ui->CHB50,50);
    CBgroup->addButton(ui->CHB51,51);
    CBgroup->addButton(ui->CHB52,52);
    CBgroup->addButton(ui->CHB53,53);
    CBgroup->addButton(ui->CHB54,54);
    CBgroup->addButton(ui->CHB55,55);
    CBgroup->addButton(ui->CHB56,56);
    CBgroup->addButton(ui->CHB57,57);
    CBgroup->addButton(ui->CHB58,58);
    CBgroup->addButton(ui->CHB59,59);
    CBgroup->addButton(ui->CHB60,60);
    CBgroup->addButton(ui->CHB61,61);
    CBgroup->addButton(ui->CHB62,62);
    CBgroup->addButton(ui->CHB63,63);
    CBgroup->addButton(ui->CHB64,64);
    CBgroup->addButton(ui->CHB65,65);
    CBgroup->addButton(ui->CHB66,66);
    CBgroup->addButton(ui->CHB67,67);
    CBgroup->addButton(ui->CHB68,68);
    CBgroup->addButton(ui->CHB69,69);
    CBgroup->addButton(ui->CHB70,70);
    CBgroup->addButton(ui->CHB71,71);
    CBgroup->addButton(ui->CHB72,72);
    CBgroup->addButton(ui->CHB73,73);
    CBgroup->addButton(ui->CHB74,74);
    CBgroup->addButton(ui->CHB75,75);
    CBgroup->addButton(ui->CHB76,76);
    CBgroup->addButton(ui->CHB77,77);
    CBgroup->addButton(ui->CHB78,78);
    CBgroup->addButton(ui->CHB79,79);
    CBgroup->addButton(ui->CHB80,80);
    CBgroup->addButton(ui->CHB81,81);
    CBgroup->addButton(ui->CHB82,82);
    CBgroup->addButton(ui->CHB83,83);
    CBgroup->addButton(ui->CHB84,84);
    CBgroup->addButton(ui->CHB85,85);
    CBgroup->addButton(ui->CHB86,86);
    CBgroup->addButton(ui->CHB87,87);
    CBgroup->addButton(ui->CHB88,88);
    CBgroup->addButton(ui->CHB89,89);
    CBgroup->addButton(ui->CHB90,90);
    CBgroup->addButton(ui->CHB91,91);
    CBgroup->addButton(ui->CHB92,92);
    CBgroup->addButton(ui->CHB93,93);
    CBgroup->addButton(ui->CHB94,94);
    CBgroup->addButton(ui->CHB95,95);
    CBgroup->addButton(ui->CHB96,96);
    CBgroup->addButton(ui->CHB97,97);
    CBgroup->addButton(ui->CHB98,98);
    CBgroup->addButton(ui->CHB99,99);
    CBgroup->addButton(ui->CHB100,100);
}

drawing_Dialog::~drawing_Dialog()
{
    delete ui;
}

void drawing_Dialog::on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    on_comboBox_currentIndexChanged(ui->comboBox->currentIndex());
}

void drawing_Dialog::on_dateTimeEdit_2_dateTimeChanged(const QDateTime &dateTime)
{
    QDateTime begindate(QDate(2016,11,1),QTime(0,0,0,0));
    QDateTime enddate(QDate(2016,11,15),QTime(23,59,59,0));
    switch (ui->comboBox->currentIndex())
    {
    case 0:
        ui->dateTimeEdit->setMaximumDateTime(enddate.addSecs(-10 * 60));
        ui->dateTimeEdit_2->setMinimumDateTime(begindate.addSecs(10 * 60));
        ui->dateTimeEdit->setDateTime(ui->dateTimeEdit_2->dateTime().addSecs(-10 * 60));
        break;
    case 1:
        ui->dateTimeEdit->setMaximumDateTime(enddate.addSecs(-30 * 60));
        ui->dateTimeEdit_2->setMinimumDateTime(begindate.addSecs(30 * 60));
        ui->dateTimeEdit->setDateTime(ui->dateTimeEdit_2->dateTime().addSecs(-30 * 60));
        break;
    case 2:
        ui->dateTimeEdit->setMaximumDateTime(enddate.addSecs(-60 * 60));
        ui->dateTimeEdit_2->setMinimumDateTime(begindate.addSecs(60 * 60));
        ui->dateTimeEdit->setDateTime(ui->dateTimeEdit_2->dateTime().addSecs(-60 * 60));
        break;
    case 3:
        ui->dateTimeEdit->setMaximumDateTime(enddate.addSecs(-60 * 60 * 2));
        ui->dateTimeEdit_2->setMinimumDateTime(begindate.addSecs(60 * 60 * 2));
        ui->dateTimeEdit->setDateTime(ui->dateTimeEdit_2->dateTime().addSecs(-60 * 60 * 2));
        break;
    case 4:
        ui->dateTimeEdit->setMaximumDateTime(enddate.addSecs(-60 * 60 * 6));
        ui->dateTimeEdit_2->setMinimumDateTime(begindate.addSecs(60 * 60 * 6));
        ui->dateTimeEdit->setDateTime(ui->dateTimeEdit_2->dateTime().addSecs(-60 * 60 * 6));
        break;
    case 5:
        ui->dateTimeEdit->setMaximumDateTime(enddate.addSecs(-60 * 60 * 12));
        ui->dateTimeEdit_2->setMinimumDateTime(begindate.addSecs(60 * 60 * 12));
        ui->dateTimeEdit->setDateTime(ui->dateTimeEdit_2->dateTime().addSecs(-60 * 60 * 12));
        break;
    case 6:
        ui->dateTimeEdit->setMaximumDateTime(enddate.addSecs(-60 * 60 * 24));
        ui->dateTimeEdit_2->setMinimumDateTime(begindate.addSecs(60 * 60 * 24));
        ui->dateTimeEdit->setDateTime(ui->dateTimeEdit_2->dateTime().addSecs(-60 * 60 * 24));
        break;
    case 7:
        ui->dateTimeEdit->setMaximumDateTime(enddate.addDays(-3));
        ui->dateTimeEdit_2->setMinimumDateTime(begindate.addDays(3));
        ui->dateTimeEdit->setDateTime(ui->dateTimeEdit_2->dateTime().addDays(-3));
        break;
    case 8:
        ui->dateTimeEdit->setMaximumDateTime(enddate.addDays(-7));
        ui->dateTimeEdit_2->setMinimumDateTime(begindate.addDays(7));
        ui->dateTimeEdit->setDateTime(ui->dateTimeEdit_2->dateTime().addDays(-7));
        break;
    case 9:
        ui->dateTimeEdit->setMaximumDateTime(enddate.addDays(-10));
        ui->dateTimeEdit_2->setMinimumDateTime(begindate.addDays(10));
        ui->dateTimeEdit->setDateTime(ui->dateTimeEdit_2->dateTime().addDays(-10));
        break;
    default:
        ui->dateTimeEdit->setMaximumDateTime(enddate);
        ui->dateTimeEdit_2->setMinimumDateTime(begindate);
        ui->dateTimeEdit->setDateTime(enddate);
        break;
    }
}


void drawing_Dialog::on_comboBox_currentIndexChanged(int index)
{
    QDateTime begindate(QDate(2016,11,1),QTime(0,0,0,0));
    QDateTime enddate(QDate(2016,11,15),QTime(23,59,59,0));
    switch (index)
    {
    case 0:
        ui->dateTimeEdit->setMaximumDateTime(enddate.addSecs(-10 * 60));
        ui->dateTimeEdit_2->setMinimumDateTime(begindate.addSecs(10 * 60));
        ui->dateTimeEdit_2->setDateTime(ui->dateTimeEdit->dateTime().addSecs(10 * 60));
        break;
    case 1:
        ui->dateTimeEdit->setMaximumDateTime(enddate.addSecs(-30 * 60));
        ui->dateTimeEdit_2->setMinimumDateTime(begindate.addSecs(30 * 60));
        ui->dateTimeEdit_2->setDateTime(ui->dateTimeEdit->dateTime().addSecs(30 * 60));
        break;
    case 2:
        ui->dateTimeEdit->setMaximumDateTime(enddate.addSecs(-60 * 60));
        ui->dateTimeEdit_2->setMinimumDateTime(begindate.addSecs(60 * 60));
        ui->dateTimeEdit_2->setDateTime(ui->dateTimeEdit->dateTime().addSecs(60 * 60));
        break;
    case 3:
        ui->dateTimeEdit->setMaximumDateTime(enddate.addSecs(-60 * 60 * 2));
        ui->dateTimeEdit_2->setMinimumDateTime(begindate.addSecs(60 * 60 * 2));
        ui->dateTimeEdit_2->setDateTime(ui->dateTimeEdit->dateTime().addSecs(60 * 60 * 2));
        break;
    case 4:
        ui->dateTimeEdit->setMaximumDateTime(enddate.addSecs(-60 * 60 * 6));
        ui->dateTimeEdit_2->setMinimumDateTime(begindate.addSecs(60 * 60 * 6));
        ui->dateTimeEdit_2->setDateTime(ui->dateTimeEdit->dateTime().addSecs(60 * 60 * 6));
        break;
    case 5:
        ui->dateTimeEdit->setMaximumDateTime(enddate.addSecs(-60 * 60 * 12));
        ui->dateTimeEdit_2->setMinimumDateTime(begindate.addSecs(60 * 60 * 12));
        ui->dateTimeEdit_2->setDateTime(ui->dateTimeEdit->dateTime().addSecs(60 * 60 * 12));
        break;
    case 6:
        ui->dateTimeEdit->setMaximumDateTime(enddate.addSecs(-60 * 60 * 24));
        ui->dateTimeEdit_2->setMinimumDateTime(begindate.addSecs(60 * 60 * 24));
        ui->dateTimeEdit_2->setDateTime(ui->dateTimeEdit->dateTime().addSecs(60 * 60 * 24));
        break;
    case 7:
        ui->dateTimeEdit->setMaximumDateTime(enddate.addDays(-3));
        ui->dateTimeEdit_2->setMinimumDateTime(begindate.addDays(3));
        ui->dateTimeEdit_2->setDateTime(ui->dateTimeEdit->dateTime().addDays(3));
        break;
    case 8:
        ui->dateTimeEdit->setMaximumDateTime(enddate.addDays(-7));
        ui->dateTimeEdit_2->setMinimumDateTime(begindate.addDays(7));
        ui->dateTimeEdit_2->setDateTime(ui->dateTimeEdit->dateTime().addDays(7));
        break;
    case 9:
        ui->dateTimeEdit->setMaximumDateTime(enddate.addDays(-10));
        ui->dateTimeEdit_2->setMinimumDateTime(begindate.addDays(10));
        ui->dateTimeEdit_2->setDateTime(ui->dateTimeEdit->dateTime().addDays(10));
        break;
    default:
        ui->dateTimeEdit->setMaximumDateTime(enddate);
        ui->dateTimeEdit_2->setMinimumDateTime(begindate);
        ui->dateTimeEdit->setDateTime(begindate);
        ui->dateTimeEdit_2->setDateTime(enddate);
        break;
    }
}

extern taxidata Tdata[10000000];
extern int date_index[20];
QSplineSeries* departure_series;
QSplineSeries* arrival_series;
bool checkbox_chosen[101] = {0};
void drawing_Dialog::on_pushButton_clicked()
{
    for(qint64 i = 1;i <= 100;++i)
    {
        if(CBgroup->button(i)->isChecked()) checkbox_chosen[i] = true;
        else checkbox_chosen[i] = false;
    }
    qint64 diffs = ui->dateTimeEdit->dateTime().secsTo(ui->dateTimeEdit_2->dateTime());
    qint64 step = diffs / 80;
    chart = new QChart();
    departure_series = new QSplineSeries();
    arrival_series = new QSplineSeries();
    //QScatterSeries *scatterSeries = new QScatterSeries();
    QDateTimeAxis *axisX = new QDateTimeAxis();
    axisX->setTickCount(5);
    axisX->setFormat("MM-dd hh:mm");
    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%d");

    QDateTime begintime;
    QDateTime endtime;
    int max_sum = 0;
    int max_sum2 = 0;
    QVector<QPointF> points;
    QVector<QPointF> points_2;
    for(qint64 i = 0;i < 80;++i)
    {
        begintime = ui->dateTimeEdit->dateTime().addSecs(i * step);
        endtime = begintime.addSecs(step);
        int begindate = begintime.date().day();
        int enddate = endtime.date().day();
        int beginindex = date_index[begindate];
        int endindex = enddate == 15 ? 2943723 : date_index[enddate + 1];
        qint64 sum = 0;
        qint64 sum2 = 0;
        for(int j = beginindex;j < endindex;++j)
        {
            if(Tdata[j].Departure_time > begintime && Tdata[j].Departure_time < endtime && checkbox_chosen[Tdata[j].Departure_Location_num])
                sum++;
            if(Tdata[j].End_time > begintime && Tdata[j].End_time < endtime && checkbox_chosen[Tdata[j].End_Location_num])
                sum2++;
        }
        if(sum)
            points.append(QPointF(begintime.toMSecsSinceEpoch() + step * 1000 / 2,sum));
        if(sum2)
            points_2.append(QPointF(begintime.toMSecsSinceEpoch() + step * 1000 / 2,sum2));
        if(sum > max_sum) max_sum = sum;
        if(sum2 > max_sum2) max_sum2 = sum2;
    }
    departure_series->replace(points);
    arrival_series->replace(points_2);
    //scatterSeries->replace(points);
    QFont chartfont;
    chartfont.setFamily("Consolas");
    axisX->setRange(ui->dateTimeEdit->dateTime(),ui->dateTimeEdit_2->dateTime());
    axisY->setRange(0,(max_sum > max_sum2 ? max_sum : max_sum2) * 1.2);
    chart->legend()->setFont(chartfont);
    chart->setTitle("Analysis of Passenger Flow Direction");
    chart->setTitleFont(chartfont);
    chart->addAxis(axisY, Qt::AlignLeft);
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addSeries(departure_series);
    chart->addSeries(arrival_series);
    chart->setAnimationOptions(QChart::AllAnimations);
    //chart->setTheme(QChart::ChartThemeQt);
    //chart->addSeries(scatterSeries);
    departure_series->setName("Departure Orders");
    departure_series->setUseOpenGL(true);
    departure_series->attachAxis(axisX);
    departure_series->attachAxis(axisY);
    arrival_series->setName("Arrival Orders");
    arrival_series->setUseOpenGL(true);
    arrival_series->attachAxis(axisX);
    arrival_series->attachAxis(axisY);
    //scatterSeries->attachAxis(axisX);
    //scatterSeries->attachAxis(axisY);
    chart->axes(Qt::Horizontal).back()->setTitleText("Time");
    chart->axes(Qt::Horizontal).back()->setTitleFont(chartfont);
    chart->axes(Qt::Horizontal).back()->setLabelsFont(chartfont);
    chart->axes(Qt::Vertical).back()->setTitleText("The number of orders");
    chart->axes(Qt::Vertical).back()->setTitleFont(chartfont);
    chart->axes(Qt::Vertical).back()->setLabelsFont(chartfont);
    chartView = new QChartView(this);
    chartView->setFont(chartfont);
    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->move(540,120);
    chartView->resize(1000,800);
    chartView->show();
}

void drawing_Dialog::on_radioButton_pressed()
{
    if(ui->radioButton->isChecked())
    {
        for(int i=1;i<=100;++i)
        {
            CBgroup->button(i)->setChecked(0);
        }
    }
    else
    {
        for(int i=1;i<=100;++i)
        {
            CBgroup->button(i)->setChecked(1);
        }
    }
}

QPieSeries *pieseries;
void drawing_Dialog::on_pushButton_2_clicked()
{
    for(qint64 i = 1;i <= 100;++i)
    {
        if(CBgroup->button(i)->isChecked()) checkbox_chosen[i] = true;
        else checkbox_chosen[i] = false;
    }
    QDateTime begintime;
    QDateTime endtime;
    begintime = ui->dateTimeEdit->dateTime();
    endtime = ui->dateTimeEdit_2->dateTime();
    int begindate = begintime.date().day();
    int enddate = endtime.date().day();
    int beginindex = date_index[begindate];
    int endindex = enddate == 15 ? 2943723 : date_index[enddate + 1];

    qint64 _5min = 0;
    qint64 _10min = 0;
    qint64 _20min = 0;
    qint64 _30min = 0;
    qint64 _45min = 0;
    qint64 _1h = 0;
    qint64 over1h = 0;

    for(int j = beginindex;j < endindex;++j)
    {
        if(Tdata[j].Departure_time > begintime && Tdata[j].Departure_time < endtime && checkbox_chosen[Tdata[j].Departure_Location_num])
        {
            qint64 traveltime = Tdata[j].Departure_time.secsTo(Tdata[j].End_time);
            if(traveltime <= 60 * 5) _5min++;
            else if(traveltime <= 60 * 10) _10min++;
            else if(traveltime <= 60 * 20) _20min++;
            else if(traveltime <= 60 * 30) _30min++;
            else if(traveltime <= 60 * 45) _45min++;
            else if(traveltime <= 60 * 60) _1h++;
            else over1h++;
        }
    }

    QFont chartfont;
    chartfont.setFamily("Consolas");
    chart = new QChart();
    pieseries = new QPieSeries();

    pieseries->append("0-5 mins",_5min);
    pieseries->append("5-10 mins",_10min);
    pieseries->append("10-20 mins",_20min);
    pieseries->append("20-30 mins",_30min);
    pieseries->append("30-45 mins",_45min);
    pieseries->append("45-60 mins",_1h);
    pieseries->append(">60 mins",over1h);
    chart->legend()->setFont(chartfont);
    //pieseries->setLabelsPosition(QPieSlice::LabelPosition::LabelInsideHorizontal);
    //pieseries->setLabelsVisible();
    //chart->legend()->hide();
    chart->setTitle("Analysis of Passenger Travel Time");
    chart->setTitleFont(chartfont);
    chart->addSeries(pieseries);
    chart->setAnimationOptions(QChart::AllAnimations);
    chartView = new QChartView(this);
    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->move(540,120);
    chartView->resize(1000,800);
    chartView->show();
}

QSplineSeries* revenue_series;
QAreaSeries* area_series;
void drawing_Dialog::on_pushButton_3_clicked()
{
    for(qint64 i = 1;i <= 100;++i)
    {
        if(CBgroup->button(i)->isChecked()) checkbox_chosen[i] = true;
        else checkbox_chosen[i] = false;
    }
    qint64 diffs = ui->dateTimeEdit->dateTime().secsTo(ui->dateTimeEdit_2->dateTime());
    qint64 step = diffs / 200;
    chart = new QChart();
    revenue_series = new QSplineSeries();
    QDateTimeAxis *axisX = new QDateTimeAxis();
    axisX->setTickCount(5);
    axisX->setFormat("MM-dd hh:mm");
    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%d");

    QDateTime begintime;
    QDateTime endtime;
    int max_sum = 0;
    QVector<QPointF> points;
    for(qint64 i = 0;i < 200;++i)
    {
        begintime = ui->dateTimeEdit->dateTime().addSecs(i * step);
        endtime = begintime.addSecs(step);
        int begindate = begintime.date().day();
        int enddate = endtime.date().day();
        int beginindex = date_index[begindate];
        int endindex = enddate == 15 ? 2943723 : date_index[enddate + 1];
        qint64 sum = 0;
        for(int j = beginindex;j < endindex;++j)
        {
            if(Tdata[j].Departure_time > begintime && Tdata[j].Departure_time < endtime && checkbox_chosen[Tdata[j].Departure_Location_num])
                sum += static_cast<qint64>(Tdata[j].fee);
        }
        //if(sum)
            points.append(QPointF(begintime.toMSecsSinceEpoch() + step * 1000 / 2, sum));
        if(sum > max_sum) max_sum = sum;
        sum = 0;
    }
    //QScatterSeries *scatterSeries = new QScatterSeries();
    //scatterSeries->replace(points);
    revenue_series->replace(points);
    QFont chartfont;
    chartfont.setFamily("Consolas");
    axisX->setRange(ui->dateTimeEdit->dateTime(),ui->dateTimeEdit_2->dateTime());
    axisY->setRange(0, max_sum * 1.2);
    revenue_series->setName("Total Revenue");
    revenue_series->setUseOpenGL(true);
    area_series = new QAreaSeries();
    area_series->setUpperSeries(revenue_series);
    QPen pen(0x059605);
    pen.setWidth(3);
    area_series->setPen(pen);
    area_series->setColor(0x3cc63c);
    chart->setTitle("Analysis of Total Revenue");
    chart->setTitleFont(chartfont);
    chart->addAxis(axisY, Qt::AlignLeft);
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->legend()->hide();
    chart->legend()->setFont(chartfont);
    chart->addSeries(area_series);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->axes(Qt::Horizontal).back()->setTitleText("Time");
    chart->axes(Qt::Horizontal).back()->setTitleFont(chartfont);
    chart->axes(Qt::Horizontal).back()->setLabelsFont(chartfont);
    chart->axes(Qt::Vertical).back()->setTitleText("The revenue in a time step (yuan)");
    chart->axes(Qt::Vertical).back()->setTitleFont(chartfont);
    chart->axes(Qt::Vertical).back()->setLabelsFont(chartfont);
    chartView = new QChartView(this);
    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->move(540,120);
    chartView->resize(1000,800);
    chartView->show();
}

void drawing_Dialog::on_pushButton_5_clicked()
{
    searching_Dialog s_dia;
    s_dia.exec();
}
