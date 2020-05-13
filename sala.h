#ifndef SALA_H
#define SALA_H

#include <string.h>
#include <map>
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;

class sala
{
private:
    struct datos{int filas;int columnas;int tipoasiento;};
    map<int,datos> saladatos;

    //tipo de asiento
    struct dato{string clasificacion;int costo;};
    map<int,dato> datosasiento;  //<id:clasificacion,costo>
public:
    sala();
    bool isVoid();//retorna true si no hay salas registradas
    void Insert(int, int, int, int);//Registra una nueva sala
    void InsertAsiento();// para insertar un nuevo tipo de asiento
    void PrintSalas();
    void PrintAsientos();
    bool Exist(int); //retorna true si la sala existe
    void Guardarsala(); //Guarda los cambios hechos al archivo sala
    void Guardarasiento();
    void CambiarPrecioAsiento();//cambiar precio de un asiento

};


#endif // SALA_H
