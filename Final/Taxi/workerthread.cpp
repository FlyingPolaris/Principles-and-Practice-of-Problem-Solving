#include "mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include "Toolfunction.h"

extern taxidata Tdata[3000000];
extern int date_index[20];
extern int num;
const int MAXNUM = 2943723;
extern double lng1, lng2;
extern double lat1, lat2;
WorkerThread::WorkerThread(const QFileInfoList& InfoList, QObject *parent): QThread(parent)
{
    infolist = InfoList;
}

qint64 WorkerThread::createThread(const QFileInfoList& InfoList)
{
    infolist = InfoList;
    start();
    return 0;
}

qint64 WorkerThread::getprogress()
{
    if(num <= 0) return 0;
    else return num * 100 / MAXNUM;
}

void WorkerThread::destorythread()
{
    wait();
}

void WorkerThread::run()
{
    num = 0;
    qint64 len = infolist.size();
    QString path = infolist[len - 1].filePath();
    QString filename = infolist[len - 1].fileName();
    QFile file (path);
    bool isOk =file.open(QIODevice::ReadOnly);
    if (isOk)
    {
        QByteArray array;
        bool istitle = true;
        while (file.atEnd() == false)
        {
            array = file.readLine();
            char* str = array.data();
            if(istitle)
            {
                istitle = false;
                continue;
            }
            qint64 i = 0;
            float f = 0;
            while(str[i] != ',')
            {
                f *= 10;
                f += str[i] - '0';
                ++i;
            }
            if(f == 0)
            {
                ++i;
                f = 0;
                double tmp = 1;
                bool isint = true;
                while(str[i] != ',')
                {
                    if(str[i] == '.')
                    {
                        isint = 0;
                        ++i;
                    }
                    else if(isint)
                    {
                        f *= 10;
                        f += str[i] - '0';
                        ++i;
                    }
                    else
                    {
                        tmp *= 10;
                        f += (double)(str[i] - '0') / tmp;
                        ++i;
                    }
                }
                lng1 = f;
                ++i;
                for(qint64 j = 0; j < 6; ++j)
                {
                    while(str[i] != ',') ++i;
                    ++i;
                }
                f = 0;
                tmp = 1;
                isint = true;
                while(str[i] != '\n')
                {
                    if(str[i] == '.')
                    {
                        isint = 0;
                        ++i;
                    }
                    else if(isint)
                    {
                        f *= 10;
                        f += str[i] - '0';
                        ++i;
                    }
                    else
                    {
                        tmp *= 10;
                        f += (double)(str[i] - '0') / tmp;
                        ++i;
                    }
                }
                lat1 = f;
            }
            else if(f == 9)
            {
                ++i;
                for(qint64 j = 0; j < 2; ++j)
                {
                    while(str[i] != ',') ++i;
                    ++i;
                }
                f = 0;
                double tmp = 1;
                bool isint = true;
                while(str[i] != ',')
                {
                    if(str[i] == '.')
                    {
                        isint = 0;
                        ++i;
                    }
                    else if(isint)
                    {
                        f *= 10;
                        f += str[i] - '0';
                        ++i;
                    }
                    else
                    {
                        tmp *= 10;
                        f += (double)(str[i] - '0') / tmp;
                        ++i;
                    }
                }
                lng2 = f;
                continue;
            }
            else if(f == 99)
            {
                ++i;
                for(qint64 j = 0; j < 3; ++j)
                {
                    while(str[i] != ',') ++i;
                    ++i;
                }
                f = 0;
                double tmp = 1;
                bool isint = true;
                while(str[i] != ',')
                {
                    if(str[i] == '.')
                    {
                        isint = 0;
                        ++i;
                    }
                    else if(isint)
                    {
                        f *= 10;
                        f += str[i] - '0';
                        ++i;
                    }
                    else
                    {
                        tmp *= 10;
                        f += (double)(str[i] - '0') / tmp;
                        ++i;
                    }
                }
                lat2 = f;
                continue;
            }
            else continue;
        }
        file.close();
    }
    qint64 datefile = 0;
    for(qint64 n = 0; n < len - 1; ++n)
    {
        if(n % 5 == 0)
        {
            datefile++;
            date_index[datefile] = num;
        }
        QString path = infolist[n].filePath();
        QString filename = infolist[n].fileName();
        if (path.isEmpty() == false)
        {
            QFile file (path);
            bool isOk =file.open(QIODevice::ReadOnly);
            if (isOk)
            {
                QByteArray array;
                bool istitle = true;
                while (file.atEnd() == false)
                {
                    array = file.readLine();
                    char* str = array.data();
                    if(istitle)
                    {
                        istitle = false;
                        continue;
                    }
                    qint64 i = 0;
                    std::string s = "";
                    while(str[i] != ',')
                    {
                        s += str[i];
                        ++i;
                    }
                    Tdata[num].order_id = s;
                    ++i;
                    float f = 0;
                    while(str[i] != ',')
                    {
                        f *= 10;
                        f += str[i] - '0';
                        ++i;
                    }
                    Tdata[num].Departure_time = QDateTime::fromSecsSinceEpoch(static_cast<int>(f));
                    ++i;
                    f = 0;
                    while(str[i] != ',')
                    {
                        f *= 10;
                        f += str[i] - '0';
                        ++i;
                    }
                    Tdata[num].End_time = QDateTime::fromSecsSinceEpoch(static_cast<int>(f));
                    ++i;
                    f = 0;
                    double tmp = 1;
                    bool isint = true;
                    while(str[i] != ',')
                    {
                        if(str[i] == '.')
                        {
                            isint = 0;
                            ++i;
                        }
                        else if(isint)
                        {
                            f *= 10;
                            f += str[i] - '0';
                            ++i;
                        }
                        else
                        {
                            tmp *= 10;
                            f += (double)(str[i] - '0') / tmp;
                            ++i;
                        }
                    }
                    Tdata[num].orig_lng = f;
                    ++i;
                    f = 0;
                    tmp = 1;
                    isint = true;
                    while(str[i] != ',')
                    {
                        if(str[i] == '.')
                        {
                            isint = 0;
                            ++i;
                        }
                        else if(isint)
                        {
                            f *= 10;
                            f += str[i] - '0';
                            ++i;
                        }
                        else
                        {
                            tmp *= 10;
                            f += (double)(str[i] - '0') / tmp;
                            ++i;
                        }
                    }
                    Tdata[num].orig_lat = f;

                    Tdata[num].Departure_Location_num = getLocationNum(Tdata[num].orig_lng, Tdata[num].orig_lat);

                    ++i;
                    f = 0;
                    tmp = 1;
                    isint = true;
                    while(str[i] != ',')
                    {
                        if(str[i] == '.')
                        {
                            isint = 0;
                            ++i;
                        }
                        else if(isint)
                        {
                            f *= 10;
                            f += str[i] - '0';
                            ++i;
                        }
                        else
                        {
                            tmp *= 10;
                            f += (double)(str[i] - '0') / tmp;
                            ++i;
                        }
                    }
                    Tdata[num].dest_lng = f;
                    ++i;
                    f = 0;
                    tmp = 1;
                    isint = true;
                    while(str[i] != ',')
                    {
                        if(str[i] == '.')
                        {
                            isint = 0;
                            ++i;
                        }
                        else if(isint)
                        {
                            f *= 10;
                            f += str[i] - '0';
                            ++i;
                        }
                        else
                        {
                            tmp *= 10;
                            f += (double)(str[i] - '0') / tmp;
                            ++i;
                        }
                    }
                    Tdata[num].dest_lat = f;

                    Tdata[num].End_Location_num = getLocationNum(Tdata[num].dest_lng, Tdata[num].dest_lat);
                    ++i;
                    f = 0;
                    tmp = 1;
                    isint = true;
                    while(str[i] != '\n')
                    {
                        if(str[i] == '.')
                        {
                            isint = 0;
                            ++i;
                        }
                        else if(isint)
                        {
                            f *= 10;
                            f += str[i] - '0';
                            ++i;
                        }
                        else
                        {
                            tmp *= 10;
                            f += (double)(str[i] - '0') / tmp;
                            ++i;
                        }
                    }
                    Tdata[num].fee = f;
                    num++;
                    if(num % 20000 == 0 || num == MAXNUM)
                        emit changed(num*100/MAXNUM);
                }
            }
            file.close();
        }
    }

}
