#include <QFileDialog>
#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    ruta=QFileDialog::getExistingDirectory();
    ui->lineEdit->setText(ruta);
    if(ui->lineEdit->text() !="")
    {
            ui->pushButton->setEnabled(true);
            ui->pushButton_2->setEnabled(true);
    }
}

void Dialog::on_pushButton_2_clicked()
{
    rutaDestino=QFileDialog::getExistingDirectory();
    ui->lineEdit_2->setText(rutaDestino);
    if(ui->lineEdit_2->text() !="")
    {
        ui->pushButton_3->setEnabled(true);
    }
}

void Dialog::on_pushButton_3_clicked()
{
    clock_t t_inicio, t_final;
    double segundos, milisegundos;

    t_inicio=clock();
}
