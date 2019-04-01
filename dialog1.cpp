#include "dialog1.h"
#include "ui_dialog1.h"

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

//Seleccionamos el directorio donde estan las imagenes
void Dialog1::on_pushButton_2_clicked()
{
    rutaOrigen = QFileDialog::getExistingDirectory(0, ("select input directory"), QDir::homePath());

}

//Seleccionamos el directorio donde queremos guardar las imagenes modificadas
void Dialog1::on_pushButton_3_clicked()
{
    rutaDestino = QFileDialog::getExistingDirectory(0, ("select input directory"), QDir::homePath());
}


void Dialog1::on_pushButton_clicked()
{
    //Selecciona todas las imagenes de la ruta selecciona
    QStringList fotos = rutaOrigen.entryList(QStringList() << "*.jpg", QDir::Files);

    clock_t inicio, fin;

    int tam = 5;
    double tiempos[tam];
    double media = 0;

    for(int i = 0; i < tam; i++){

        //iniciamos el tiempo
        inicio = clock();

        //Seleccionamos el nombre de la imagen
        QString nombre;
        QString name;
        nombre = name;
        nombre = rutaOrigen.absoluteFilePath(nombre);

        //Cambiamos el nombre a las imagenes modificadas
        QImage original, modificada;
        original.load(nombre);
        modificada.load(nombre);

        //Modificamos el color
        for(int i = 0; original.width(); i++){  //ancho de la imagen
            for(int j = 0; original.height(); j++){ //alto de la imagen
                QRgb pix = original.pixel(i,j);
                int rojo = qRed(pix);
                QRgb value = qRgb(rojo, 0, 0);
                modificada.setPixel(i, j, value);
            }
        }
        //Cambiamos el nombre con la imagen modificada
        QPixmap a = QPixmap::fromImage(modificada);
        a.save(rutaDestino.absolutePath()+"/"+nombre.split(".jpg")[0]+"Modificada.jpg");

        //Finalizamos los tiempos
        fin = clock();
        tiempos[i] = (double)(fin - inicio)/CLOCKS_PER_SEC;
        media = media + tiempos[i];
    }
    //Mostramos los tiempos
    ui->tiempo1->setText(QString::number(tiempos[0]) + " segundos");
    ui->tiempo2->setText(QString::number(tiempos[1]) + " segundos");
    ui->tiempo3->setText(QString::number(tiempos[2]) + " segundos");
    ui->tiempo4->setText(QString::number(tiempos[3]) + " segundos");
    ui->tiempo5->setText(QString::number(tiempos[4]) + " segundos") ;
    ui->media->setText(QString::number(media) + " segundos");




}
