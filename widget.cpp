#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Santa's Program");
}

void Widget::insertar()
{
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsSimpleTextItem *text = new QGraphicsSimpleTextItem();
    QString texto = "hola";
    text->setText(texto);
    scene->addItem(text);
    ui->graphicsView->setScene(scene);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_AddButton_clicked()
{
    Nino* nino;
    string nombre = ui->nombre_crear->text().toStdString();
    int edad = ui->edad->value();
    int cal = ui->calificaicion->value();
    int index = hashCode(nombre);
    nino = new Nino(nombre,edad,cal,index);
    tree.insertar(nino);
    //tree.mostrarArbol();
    cout<<endl;
}

int  Widget::hashCode(string text){
    int hash = 0, strlen = text.length(), i;
    char character;
    if (strlen == 0)
        return hash;
    for (i = 0; i < strlen; i++) {
        character = text[i];
        hash = (31 * hash) + int(character);
    }
    return hash;
}
