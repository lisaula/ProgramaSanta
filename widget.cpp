#include "widget.h"
#include "ui_widget.h"
#include<QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->comboBox_2->addItem("--");
    setWindowTitle("Santa's Program");
    ui->comboBoxCP->addItem("A(0-3)");
    ui->comboBoxCP->addItem("B(4-7)");
    ui->comboBoxCP->addItem("C(8-10)");
    ui->comboBoxCP->addItem("D(10-15)");
    ui->comboBoxCP->addItem("E(16-18)");
    ui->comboBoxCP->addItem("F(19...)");
    ui->comboBoxCP->addItem("G(Todas las edades)");
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

void Widget::borrarcorrido(int n, Nino *&nino)
{
    for(int i =n; i<nino->Regalos.size()-n+1;i++){
        nino->Regalos[i]=nino->Regalos[i+1];
    }
    nino->Regalos.erase(nino->Regalos.end());
}

int Widget::checkGifts(Nino *&nino)
{
    int cant=0;
    if(nino->se_porto_bien<3){
        nino->Regalos.clear();
        for(int i =0; i < nino->Regalos.size();i++){
            nino->addRegalo("CARBON",'G');
        }
        cant=-1;
    }else{
        //vector<Regalo*>::iterator it = nino->Regalos.begin();
        char cp;
        int edad = nino->edad;

        Regalo *re;
        for(int i =0; i < nino->Regalos.size();i++){
            cp = nino->Regalos[i]->getPC();
            re = nino->Regalos[i];
            if( cp == 'A'){
                if(edad < 0){
                    nino->Regalos.erase(nino->Regalos.begin()+i);
                    cant++;
                }
            }else if( cp == 'B'){
                if(edad < 4){
                    nino->Regalos.erase(nino->Regalos.begin()+i);
                    cant++;
                }
            }else if( cp == 'C'){
                if(edad < 8){
                    nino->Regalos.erase(nino->Regalos.begin()+i);
                    cant++;
                }
            }else if( cp == 'D'){
                if(edad < 10){
                    nino->Regalos.erase(nino->Regalos.begin()+i);
                    cant++;
                }
            }else if( cp == 'E'){
                if(edad < 16){
                    nino->Regalos.erase(nino->Regalos.begin()+i);
                    cant++;
                }
            }else if( cp == 'F'){
                if(edad <19 ){
                    nino->Regalos.erase(nino->Regalos.begin()+i);
                    cant++;
                }
            }
            //it++;
        }
    }
    return cant;
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
    int cant = fibonacci(cal);
    nino = new Nino(nombre,edad,cal,index,cant);
    tree.insertar(nino);
    //tree.mostrarArbol();
    ui->comboBox_2->addItem(nombre.c_str());
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

void Widget::on_pushButton_2_clicked()
{
    string nombre = ui->comboBox_2->currentText().toStdString();
    if(nombre == "--"){
        string control_p = ui->comboBoxCP->currentText().toStdString();
        char cp = control_p[0];
        string des = ui->desc->text().toStdString();
        Regalo* r = new Regalo(des,cp);
        lista.push_back(r);
        int n = ui->sizeLista->text().toInt();
        ui->sizeLista->setText(QString::number(n+1));
    }else{
        string control_p = ui->comboBoxCP->currentText().toStdString();
        char cp = control_p[0];
        string des = ui->desc->text().toStdString();
        Nino* nino = new Nino(nombre,0,0,hashCode(nombre),0);
        tree.buscar(nino);
        nino->addRegalo(des,cp);
    }
}

void Widget::on_asignar_clicked()
{
    string nombre = ui->comboBox_2->currentText().toStdString();
    int n = ui->sizeLista->text().toInt();
    if(n =0){
        QMessageBox::warning(this,"WARNInG","No hay regalos por asignar");
    }else{
        if(nombre != "--"){
            string control_p = ui->comboBoxCP->currentText().toStdString();
            char cp = control_p[0];
            string des = ui->desc->text().toStdString();
            Nino* nino = new Nino(nombre,0,0,hashCode(nombre),0);
            if(tree.buscar(nino)){
                nino->addList(lista, lista.size());
                lista.clear();
                ui->sizeLista->setText(QString::number(0));
            }
        }
    }
}

void Widget::on_buscar_clicked()
{
    QString texto="";
    QGraphicsScene * scene = new QGraphicsScene();
    QGraphicsSimpleTextItem * text = new QGraphicsSimpleTextItem();

    string nombre = ui->nombre->text().toStdString();
    if(nombre != ""){
        Nino* nino = new Nino(nombre,0,0,hashCode(nombre),0);
        if(tree.buscar(nino)){
            texto = QString("Nombre: %1 - Edad: %2 - Calificacion: %3 \nPodra recibir %4\n").arg(nino->nombre.c_str()).arg(nino->edad).arg(nino->se_porto_bien).arg(nino->cant_regalos);
            if(nino->Regalos.size()>nino->cant_regalos){
                vector<Regalo*>::iterator it = nino->Regalos.begin();
                int borrado = nino->Regalos.size()-nino->cant_regalos;
                for(int i =0; i < borrado;i++){
                    nino->Regalos.erase(it);
                    it++;
                }
                texto += QString("Cantidad de regalos sobrepasa cantidad que puede recibir, se han borrado %5\n").arg(borrado);
            }
            int cant = checkGifts(nino);
            if(cant >0){
                texto+=QString("Se encontraron regalos no aptos para la edad del nino, se han borrado %1\n").arg(cant);
            }else if(cant <0){
                texto += QString("Nino muy malo, recibira carbon\n");
            }
            texto+=QString("%1").arg(nino->imprimirRegalos());
            text->setText(texto);
            scene->addItem(text);
            ui->graphicsView->setScene(scene);
        }else{
            QMessageBox::warning(this,"ERROR","Nombre no encontrado");
        }
    }else{
        QMessageBox::warning(this,"ERROR","No ha especificado un nombre");
    }
}

int Widget::fibonacci(int n ){
    if(n > 1){
        return fibonacci(n-1 )+ fibonacci(n-2);
    }
    return n;
}
