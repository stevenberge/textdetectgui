#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->fileDialog = new QFileDialog(this);
   // this->fileDialog->show();
    ui->setupUi(this);

    //connect(this, SIGNAL(run(QString, bool)),  mt, SLOT(run(QString, bool)), Qt:: QueuedConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    DBG<<"filedial button clicked"<<endl;
    qfile = this->fileDialog->getOpenFileName();
}

void MainWindow::on_pushButton_2_clicked()
{
    DBG<<"begin handle with :"<<qfile<<endl;
    MainThread *mt = new MainThread(qfile);
    connect(mt, SIGNAL(setFrameSig(int, Mat*)), this, SLOT(setFrame(int, Mat*)), Qt::BlockingQueuedConnection);
    connect(mt, SIGNAL(setLabelSig(int, int)), this, SLOT(setLabel(int, int)), Qt::BlockingQueuedConnection);
    mt->start();
}

/*#define DisIMG(qlabel, tmp)  \
    cv::cvtColor(tmp, tmp, CV_BGR2RGB);\
    QImage tt =   QImage((const unsigned char*)(tmp.data),tmp.cols,tmp.rows, tmp.cols*tmp.channels(),  QImage::Format_RGB888);\
    qlabel->setPixmap(QPixmap::fromImage(tt));
*/
void MainWindow::setFrame(int id, Mat *mat){

    std::cout<<"set frame "<<id<<endl;

     char buf[10];
     sprintf(buf, "frame%d", id);

    QLabel *qf = this->findChild<QLabel*>(buf);
    Mat tmp = mat->clone();
    //DisIMG(qf, *tmp);
    if(tmp.channels() == 3)
        cv::cvtColor(tmp, tmp, CV_BGR2RGB);
    else
        cv::cvtColor(tmp, tmp, CV_GRAY2RGB);
    QImage tt = QImage((const unsigned char*)(tmp.data),tmp.cols,tmp.rows, tmp.cols*tmp.channels(),  QImage::Format_RGB888);
    qf->setPixmap(QPixmap::fromImage(tt));
}
void  MainWindow::setLabel(int step, int thr){
    // display current progress on UI
    std::cout<<"set label "<<step<<" "<<thr<<endl;
        QLabel *label = this->findChild<QLabel*>("label");
        char buf[40];
        sprintf(buf, "step : %d,       Thr = %d", step, thr);
        label->setText(buf);
}
