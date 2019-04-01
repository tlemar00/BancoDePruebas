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
    ruta = QFileDialog::getExistingDirectory(0, ("select input directory"), QDir::homePath());

}

//Seleccionamos el directorio donde queremos guardar las imagenes modificadas
void Dialog1::on_pushButton_3_clicked()
{
    rutaDestino = QFileDialog::getExistingDirectory(0, ("select input directory"), QDir::homePath());
}


void Dialog1::on_pushButton_clicked()
{
    //Selecciona todas las imagenes de la ruta selecciona
    QStringList fotos = ruta.entryList(QStringList() << "*.jpg", QDir::Files);

    clock_t inicio, fin;

    int tam = 5;
    double tiempos[tam];
    double media = 0;

    for(int i = 0; i < tam; i++){

        //iniciamos el tiempo
        inicio = clock();

        foreach (QString name, fotos){
            //Seleccionamos el nombre de la imagen
            QString nombre = name;
            nombre = ruta.absoluteFilePath(nombre);

            //Cambiamos el nombre a las imagenes modificadas
            QImage original, modificada;
            original.load(nombre);
            modificada.load(nombre);

            //Modifamos el color
            for(int i = 0; original.width(); i++){
                for(int j = 0; original.height(); j++){
                    QRgb pix = original.pixel(i,j);
                    int rojo = qRed(pix);
                    QRgb value = qRgb(rojo, 0, 0);
                    modificada.setPixel(i, j, value);
                }
            }
            //Cambiamos el nombre con la imagen modificada
            QPixmap a = QPixmap::fromImage(modificada);
            a.save(rutaDestino.absolutePath()+"/"+nombre.split(".jpg")[0]+"Modificada.jpg");
        }
        //Finalizamos los tiempos
        fin = clock();
        tiempos[i] = (double)(fin - inicio)/CLOCKS_PER_SEC;
        media = media + tiempos[i];
    }
    //Mostramos los tiempos
    ui->lineEdit_3->setText(QString::number(tiempos[0]));
    ui->lineEdit_4->setText(QString::number(tiempos[1]));
    ui->lineEdit_5->setText(QString::number(tiempos[2]));
    ui->lineEdit_6->setText(QString::number(tiempos[3]));
    ui->lineEdit_7->setText(QString::number(tiempos[4]));
    ui->lineEdit_7->setText(QString::number(media));

}
