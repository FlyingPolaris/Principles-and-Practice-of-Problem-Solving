#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <QFile>
#include <QFileDialog>
class WorkerThread : public QThread
{
    Q_OBJECT

signals:
    void changed(int);
public:
    WorkerThread(const QFileInfoList& infolist, QObject *parent = nullptr);
    qint64 createThread(const QFileInfoList& infolist);
    void destorythread();
    qint64 getprogress();
private:
    void run();
    QFileInfoList infolist;
};


#endif // WORKERTHREAD_H
