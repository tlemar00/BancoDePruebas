#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = nullptr);
    ~Dialog1();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Dialog1 *ui;
    QString ruta;
    QString rutaDestino;
};

#endif // DIALOG1_H
