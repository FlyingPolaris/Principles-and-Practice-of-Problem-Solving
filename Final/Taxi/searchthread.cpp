#include "searchthread.h"
#include "mainwindow.h"
#include "Toolfunction.h"
extern taxidata Tdata[3000000];
extern int date_index[20];
extern int num;
const int MAXNUM = 2943723;
extern double lng1, lng2;
extern double lat1, lat2;
extern QString message;
searchthread::searchthread(const double& lng1,const double& lat1,const double& lng2,const double& lat2,QObject *parent): QThread(parent)
{
    dlng = lng1;
    dlat = lat1;
    alng = lng2;
    alat = lat2;
}

qint64 searchthread::createThread(const double& lng1,const double& lat1,const double& lng2,const double& lat2)
{
    dlng = lng1;
    dlat = lat1;
    alng = lng2;
    alat = lat2;
    start();
    return 0;
}

qint64 searchthread::getprogress()
{
    if(num <= 0) return 0;
    else return num * 100 / MAXNUM;
}

void searchthread::destorythread()
{
    wait();
}

void searchthread::run()
{
    for(num = 0;num <= MAXNUM;++num)
    {
        if(isnear(dlng,dlat,Tdata[num].orig_lng,Tdata[num].orig_lat) && isnear(alng,alat,Tdata[num].dest_lng,Tdata[num].dest_lat))
        {
            message.append(QString::fromStdString(Tdata[num].order_id));
            message.append("/");
            message.append(Tdata[num].Departure_time.toString("yyyy-MM-dd hh:mm"));
            message.append("/");
            message.append(Tdata[num].End_time.toString("yyyy-MM-dd hh:mm"));
            message.append("/");
            message.append(QString::number(Tdata[num].fee,'g',3));
            message.append('\n');
        }
        if(num % 20000 == 0 || num == MAXNUM)
            emit changed(num*100/MAXNUM);
    }
}

