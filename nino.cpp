#include "nino.h"


Nino::Nino(string nombre, int edad, int cal, int index)
{
    this->nombre = nombre;
    longitud=0;
    latitud =0;
    this->edad = edad;
    this->index = index;
    se_porto_bien = cal;
}

Nino::Nino()
{
    nombre ="";
    longitud=0;
    latitud=0;
    edad =0;
    index = -1;
    se_porto_bien =0;
}

void Nino::addRegalo(string descr, char C_Prtal)
{
    Regalos.push_back(new Regalo(descr, C_Prtal));
}

void Nino::changeCarbon()
{
    Regalos.clear();
    Regalos.push_back(new Regalo("Carbon",'T'));

}
