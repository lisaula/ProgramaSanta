#include "nino.h"


Nino::Nino(string nombre, int edad, int cal, int index, int regalos)
{
    this->nombre = nombre;
    cant_regalos = regalos;
    this->edad = edad;
    this->index = index;
    se_porto_bien = cal;
}

Nino::Nino()
{
    cant_regalos=0;
    nombre ="";
    edad =0;
    index = -1;
    se_porto_bien =0;
}

QString Nino::imprimirRegalos()
{
    QString texto="";
    for(int i =0; i < Regalos.size();i++){
        texto+=QString("%1 - Clasificacion : %2\n").arg(Regalos[i]->getDesc().c_str()).arg(Regalos[i]->getPC());
    }
    return texto;
}

void Nino::addRegalo(string descr, char C_Prtal)
{
    Regalos.push_back(new Regalo(descr, C_Prtal));
}

void Nino::addList(vector<Regalo *> list, int cant)
{
    for(int i =0; i < cant;i++){
        Regalos.push_back(list[i]);
    }
}

void Nino::changeCarbon()
{
    Regalos.clear();
    Regalos.push_back(new Regalo("Carbon",'T'));

}
