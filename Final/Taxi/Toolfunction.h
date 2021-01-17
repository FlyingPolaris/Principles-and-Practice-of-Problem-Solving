#ifndef TOOLFUNCTION_H
#define TOOLFUNCTION_H

#include <QDir>
#include <QFile>
#include <QFileDialog>
#include "mainwindow.h"


QStringList getFileNames(const QString &path);

QFileInfoList getFileInfoList(const QDir &dir, const QStringList &strlist);

qint64 getLocationNum(double lng, double lat);

bool isnear(double lng1, double lat1, double lng2, double lat2);

#endif
