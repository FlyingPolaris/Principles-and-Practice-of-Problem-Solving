#ifndef READING_FILE_H
#define READING_FILE_H

#include "mainwindow.h"
#include <QFile>
#include <QFileDialog>

void readfile(QString path,taxidata Tdata[],int &num)
{
    if (path.isEmpty() == false)
    {
        QFile file (path);
        bool isOk =file.open(QIODevice::ReadOnly);
        if (isOk)
        {
            QByteArray array ;
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
                int i = 0;
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
                Tdata[num].departure_time = f;
                ++i;
                f = 0;
                while(str[i] != ',')
                {
                    f *= 10;
                    f += str[i] - '0';
                    ++i;
                }
                Tdata[num].end_time = f;
                ++i;
                f = 0;
                int tmp = 1;
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
                        f += (str[i] - '0') / tmp;
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
                        f += (str[i] - '0') / tmp;
                        ++i;
                    }
                }
                Tdata[num].orig_lat = f;
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
                        f += (str[i] - '0') / tmp;
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
                        f += (str[i] - '0') / tmp;
                        ++i;
                    }
                }
                Tdata[num].dest_lat = f;
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
                        f += (str[i] - '0') / tmp;
                        ++i;
                    }
                }
                Tdata[num].fee = f;
                num++;
            }
        }
        file.close();
    }
}


#endif
