#ifndef SEARCHTHREAD_H
#define SEARCHTHREAD_H

#include <QThread>
class searchthread : public QThread
{
    Q_OBJECT

signals:
    void changed(int);

public:
    searchthread(const double& lng1,const double& lat1,const double& lng2,const double& lat2,QObject *parent = nullptr);
    qint64 createThread(const double& lng1,const double& lat1,const double& lng2,const double& lat2);
    void destorythread();
    qint64 getprogress();
private:
    void run();
    double dlat, dlng, alat, alng;
};

#endif // SEARCHTHREAD_H
