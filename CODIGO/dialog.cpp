#include <QFileDialog>
#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>

using namespace std;

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
    //Definimos las variables necesarias para calcular los tiempos de ejecución.
    clock_t t_inicio, t_fin;
    double secs, milisecs;

    //Definimos el número de veces que realizamos el calculo y el array en el cual guardamos los números.
    int tam=5, i, j, NUM_MAX=10000, p, k, aux;
    double tiempos[tam];
    double media=0;
    long arrayDes[NUM_MAX];

    for(i=0;i<tam;i++)
    {
        //Inicializamos el tiempo de inicio.
        t_inicio=clock();

        //Escogemos la ruta de origen para abrir el archivo en el que se encuentran los números. Se debe poner la ruta de cada usuario.
        FILE* documento = fopen("/home/delsi/Descargas/bancoDePruebasFinal-master/ARCHIVOS/Salida.txt", "rt");
        for(j=0;j<NUM_MAX;j++)
        {
            long num;

            //Lee los números del documento anteriormente escogido y abierto.
            fscanf(documento, "%ld", &num);
            arrayDes[j]=num;
        }

        //Cerramos el archivo en el que se encuentran los números.
        fclose(documento);

        //Algoritmo que ordena los números de menor a mayor.
        for(p=0;p<NUM_MAX;p++)
        {
            for (k=p+1;k<NUM_MAX;k++)
            {
                if(arrayDes[p]>arrayDes[k])
                {
                    aux=arrayDes[p];
                    arrayDes[p]=arrayDes[k];
                    arrayDes[k]=aux;
                }
            }
        }

        //Guarda un archivo con los números ordenados. Se debe poner la ruta de cada usuario.
        FILE* numerosOrdenados=fopen("/home/delsi/Descargas/bancoDePruebasFinal-master/ARCHIVOS/numOrd.txt", "w+");
        for(j=0;j<NUM_MAX;j++)
        {
            //Escribimos los números en el archivo anteriormente creado y abierto.
            fprintf(numerosOrdenados, "%ld ", arrayDes[j]);
        }

        //Cerramos el archivo.
        fclose(numerosOrdenados);

        //Inicializamos el tiempo de finalización.
        t_fin=clock();

        //Guardamos los tiempos de cada ejecución.
        tiempos[i]=(double)(t_fin-t_inicio)/CLOCKS_PER_SEC;

        //Calculamos la media de todos los tiempos.
        media=media+tiempos[i]/tam;
    }

    //Imprimimos en la interfaz los tiempos de ejecución.
    ui->lineEdit_3->setText(QString::number(tiempos[0])+" segundos.");
    ui->lineEdit_4->setText(QString::number(tiempos[1])+" segundos.");
    ui->lineEdit_5->setText(QString::number(tiempos[2])+" segundos.");
    ui->lineEdit_6->setText(QString::number(tiempos[3])+" segundos.");
    ui->lineEdit_7->setText(QString::number(tiempos[4])+" segundos.");
    ui->lineEdit_8->setText(QString::number(media)+" segundos.");
}
