#ifndef NINO_H
#define NINO_H
#include<iostream>
#include<QList>
using namespace std;

class Regalo{

    string descripcion;
    char control_parental;
public:
    string getDesc(){
        return descripcion;
    }
    char getPC(){
        return control_parental;
    }

    Regalo(string d, char C_Prtal){
        descripcion = d;
        control_parental = C_Prtal;
    }
};

class Nino
{
public:
    string nombre;
    int index;
    int se_porto_bien; //valor del 0 al 10,  0 = Diablillo , 10 = La encarnación del Bien.
    QList<Regalo*> Regalos;
    int longitud;
    int latitud;
    int edad;
    Nino(string nombre, int edad, int cal, int index);
    Nino();

    void addRegalo(string descr, char C_Prtal);
    void changeCarbon();
};

#endif // NINO_H
