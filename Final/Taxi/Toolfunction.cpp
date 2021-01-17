#include "Toolfunction.h"

extern double lng1, lng2;
extern double lat1, lat2;
QStringList getFileNames(const QString &path)
{
    QDir dir(path);
    QStringList nameFilters;
    nameFilters << "*.csv";
    QStringList files = dir.entryList(nameFilters, QDir::Files|QDir::Readable, QDir::Name);
    return files;
}

QFileInfoList getFileInfoList(const QDir &dir,const QStringList &strlist)
{
    qint64 len = strlist.size();
    QFileInfoList infolist;
    for(qint64 i = 0; i < len; ++i)
    {
        QFileInfo info(dir,strlist[i]);
        infolist.append(info);
    }
    return infolist;
}

qint64 getLocationNum(double lng, double lat)
{
    int num = 1;
    double deta_x = (lng2 - lng1)/10.0;
    double deta_y = (lat2 - lat1)/10.0;
    qint64 x_index = static_cast<qint64>((lng - lng1)/deta_x) + 1;
    qint64 y_index = static_cast<qint64>((lat - lat1)/deta_y) + 1;
    num = 10 * x_index + y_index;
    if(num < 1 || num > 100) num = 0;
    return num;
}

void doubleswap(double &a, double &b)
{
    double tmp;
    tmp = a;
    a = b;
    b = tmp;
}

bool isnear(double lng1, double lat1, double lng2, double lat2)
{
    bool isnear = false;
    if(lng1 < lng2) doubleswap(lng1, lng2);
    if(lat1 < lat2) doubleswap(lat1, lat2);
    if((lng1 - lng2 <= 0.01) &&(lat1 - lat2 <= 0.01))
    {
        isnear = true;
    }
    return isnear;
}
