#ifndef CARTELERA_H
#define CARTELERA_H


#include <string.h>
#include <map>
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;

class cartelera
{
private:
    struct datoscartelera{int idpelicula; string fecha; string hora; int idsala;};
   map<int,datoscartelera> Cartelera;// <id:{idpelicula, fecha, hora,id sala}
public:
    cartelera();
    void Insert(int,int); //Para ingresar una pelicula a la cartelera
    string ValidarFecha();
    string ValidarHora();
    void Guardar();
};

#endif // CARTELERA_H
