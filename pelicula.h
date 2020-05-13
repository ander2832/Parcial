#ifndef PELICULA_H
#define PELICULA_H

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;

using namespace std;
class Pelicula
{
private:
    struct datos{string nombre; string genero; int duracion; string clase;};
    map<int,datos> pelidatos; //<id:{nombre, genero, duracion, clase}>
public:
    Pelicula();//constructor que carga los datos en el atributo pelidatos
    void Guardar();//guarda los datos en el archivo
    void Insert();//insertar una nueva pelicula
    void Printpeliculas();//imprime todas las peliculas
};

#endif // PELICULA_H
