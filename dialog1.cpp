#include <QFileDialog>
#include "dialog1.h"
#include "ui_dialog1.h"

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_pushButton_2_clicked()
{
    ruta=QFileDialog::getExistingDirectory();
    ui->lineEdit_9->setText(ruta);
    if(ui->lineEdit_9->text() !="")
    {
            ui->pushButton->setEnabled(true);
            ui->pushButton_2->setEnabled(true);
    }
}

void Dialog1::on_pushButton_3_clicked()
{
    rutaDestino=QFileDialog::getExistingDirectory();
    ui->lineEdit_8->setText(rutaDestino);
    if(ui->lineEdit_8->text() !="")
    {
        ui->pushButton->setEnabled(true);
    }
}
