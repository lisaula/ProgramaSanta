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
    explicit Widget(QWidget *parent = 0);
    void insertar();
    ~Widget();

private slots:
    void on_AddButton_clicked();

private:
    Btree<Nino,3>tree;
    Ui::Widget *ui;
};


#endif // WIDGET_H
