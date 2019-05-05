#include "dialog1.h"
#include "ui_dialog1.h"
#include "QMessageBox"

#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <time.h>

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

//Seleccionamos la imagen a modificar
QString Dialog1::obtenerRuta()
{
    rutaOrigen = QFileDialog::getOpenFileName(this, tr("Abrir"), "nombre",tr("ImageFiles(*.png *.jpg *.bmp)"));
    original = QImage(rutaOrigen);

    return rutaOrigen;
}

//cargamos la ruta
void Dialog1::on_pushButton_2_clicked()
{
    QString ruta = obtenerRuta();
    original.load(rutaOrigen);

}

void Dialog1::on_pushButton_clicked()
{

    //definimos variables que nos van a hacer falta
    clock_t inicio, fin;
    int tam = 5;
    double tiempos[tam];
    double sumaTiempos = 0;
    double media = 0;

    //hacemos un bucle que hace los 5 tiempos
    for(int bu = 0; bu < tam; bu++){
        modificada = original;
        //iniciamos el tiempo
        inicio = clock();

        //Modificamos el color
        for(int i = 0; i < modificada.width(); i++){  //ancho de la imagen
            for(int j = 0; j < modificada.height(); j++){ //alto de la imagen
                QRgb rgb = modificada.pixel(i, j);
                QRgb nuevoValorRgb = qRgb(qRed(rgb), 0, 0);
                modificada.setPixel(i, j, nuevoValorRgb);
            }
        }

        //Finalizamos los tiempos
        fin = clock();
        //lo pasamos a segundos
        tiempos[bu] = (double)(fin - inicio)/CLOCKS_PER_SEC;
        sumaTiempos = sumaTiempos + tiempos[bu];
        //Calculamos la media
        media = sumaTiempos / tam;

    }

    //Mostramos los tiempos
    ui->tiempo1->setText(QString::number(tiempos[0]) + " segundos");
    ui->tiempo2->setText(QString::number(tiempos[1]) + " segundos");
    ui->tiempo3->setText(QString::number(tiempos[2]) + " segundos");
    ui->tiempo4->setText(QString::number(tiempos[3]) + " segundos");
    ui->tiempo5->setText(QString::number(tiempos[4]) + " segundos") ;
    ui->media->setText(QString::number(media) + " segundos");

    //guardamos la imagen
    QMessageBox msgBox;
        msgBox.setText("La imagen ha sido modificada.");
        msgBox.setInformativeText("¿Quieres guardar los cambios?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
       int elegido = msgBox.exec();
        if (elegido == QMessageBox::Save) {
             modificada.save("/home/delsi/Descargas/bancoDePruebasFinal-master/ARCHIVOS/modificada.jpg","jpg",-1);
        }
}

//limpiamos los lineEdit
void Dialog1::on_pushButton_3_clicked()
{
    ui->tiempo1->clear();
    ui->tiempo2->clear();
    ui->tiempo3->clear();
    ui->tiempo4->clear();
    ui->tiempo5->clear();
    ui->media->clear();
}
