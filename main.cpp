/******************************************************************************

  Copyright (C), 2020, Fred

 ******************************************************************************
  File Name     : main.cpp
  Version       : v1.0
  Author        : wtzhu_13/Fred
  Created       : 2020/05
  Description   : this file was private for orderSystem
  History       :
  1.Date        :
    Author      :
    Modification: Created file
******************************************************************************/
#include "widget.h"
#include <QApplication>
#include <QDebug>
#include "dialog.h"
#include "connection.h"
#include "student.h"
#include "teacher.h"
#include "global.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog login;
    qDebug() << "hello";
//    qDebug()<<QSqlDatabase::drivers();
//    qDebug()<<QCoreApplication::libraryPaths();
    if(connectDatabase())
    {
        qDebug()<<"Success"<<endl;
        if(login.exec() == QDialog::Accepted){
            switch (globalIndex) {
                case 0:{
                    Student stu;
                    stu.show();
                    return a.exec();
                }
                break;
                case 1:{
                    Teacher teacher;
                    teacher.show();
                    return a.exec();
                }
                break;
                case 2:{
                    Widget w;
                    w.show();
                    return a.exec();
                }
                break;
                default:
                    break;
            }

        }
    }
    else
    {
        qDebug()<<"Failed"<<endl;
    }

    return a.exec();
}
