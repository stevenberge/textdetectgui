#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QAbstractButton>
#include <iostream>
#include <QString>
#include <QDebug>
#include <QLabel>
#include "mainthread.h"
#include <fstream>
using std::fstream;
 #define DBG qDebug()

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void (*prun) (MainWindow&, char*, bool);

signals:
    void run(QString, bool);

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void setFrame(int id, Mat *);

    void setLabel(int step, int thr);
private:
    QFileDialog *fileDialog;
    QString qfile;
    Ui::MainWindow *ui;
    //MainThread *mt;
};

#endif // MAINWINDOW_H
