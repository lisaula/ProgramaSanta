#ifndef WIDGET_H
#define WIDGET_H
#include<iostream>
using namespace std;
#include <QWidget>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QMessageBox>
#include"Btree.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    int hashCode(string text);
    int fibonacci(int n );
    explicit Widget(QWidget *parent = 0);
    void insertar();
    void borrarcorrido(int n, Nino* &nino);
    int checkGifts(Nino* & nino);
    ~Widget();

private slots:
    void on_AddButton_clicked();

    void on_pushButton_2_clicked();

    void on_asignar_clicked();

    void on_buscar_clicked();

private:
    Btree<Nino,3>tree;
    vector<Regalo*>lista;
    Ui::Widget *ui;
};


#endif // WIDGET_H
