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
    clock_t t_inicio, t_fin;
    double secs, milisecs;

    int tam=5, i, j, NUM_MAX=10000, p, k, aux;
    double tiempos[tam];
    double media=0;
    long arrayDes[NUM_MAX];


    for(i=0;i<tam;i++)
    {
        t_inicio=clock();
        FILE* documento=fopen("Salida.txt", "rt");
        for(j=0;j<NUM_MAX;j++)
        {
            long num;
            fscanf(documento, "%ld", &num);
            arrayDes[j]=num;
        }

        fclose(documento);

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

        FILE* numerosOrdenados=fopen("numOrd.txt", "w");
        for(j=0;j<NUM_MAX;j++)
        {
            fprintf(numerosOrdenados, "%ld ", arrayDes[j]);
        }

        fclose(numerosOrdenados);

        t_fin=clock();
        tiempos[i]=(double)(t_fin-t_inicio)/CLOCKS_PER_SEC;
        media=media+tiempos[i]/tam;
    }

    ui->lineEdit_3->setText(QString::number(tiempos[0])+" segundos.");
    ui->lineEdit_4->setText(QString::number(tiempos[0])+" segundos.");
    ui->lineEdit_5->setText(QString::number(tiempos[0])+" segundos.");
    ui->lineEdit_6->setText(QString::number(tiempos[0])+" segundos.");
    ui->lineEdit_7->setText(QString::number(tiempos[0])+" segundos.");
    ui->lineEdit_8->setText(QString::number(media)+" segundos.");
}
