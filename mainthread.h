#ifndef MAINTHREAD_H
#define MAINTHREAD_H
#include <QThread>
#include <opencv2/opencv.hpp>
using cv::Mat;

class MainThread: public QThread
{
    Q_OBJECT
public:
    MainThread(QString qfile, bool debug = false){
        this->qfile = qfile;
        this->debug = debug;
    }
    void run();
    QString qfile;
    bool debug;
    bool running = true;
   /*   void run(){
        while(running){
            sleep(2);
            std::cout<<"running...."<<std::endl;
        }
    }*/
//void  run(QString filename, bool debug);
private slots:

    void  stop(){
        running = false;
    }

 signals:
     void setFrameSig(int, Mat *);
     void setLabelSig(int, int);
};

#endif // MAINTHREAD_H
