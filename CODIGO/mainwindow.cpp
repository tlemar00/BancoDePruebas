#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "dialog1.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Dialog *ventana1=new Dialog();
    ventana1->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    Dialog1 *ventana2=new Dialog1();
    ventana2->show();
}
