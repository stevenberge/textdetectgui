
#define _MAIN
#include <opencv/highgui.h>
#include "mainwindow.h"
#include "mainthread.h"
#include <QApplication>
#include <QFrame>
#include <QLabel>
#include <QThread>
int main( int argc, char** argv )
{
  QApplication a(argc, argv);
  MainWindow mw;
  mw.show();
   a.exec();
}
