#ifndef TIPOASIENTO_H
#define TIPOASIENTO_H

#include <string.h>
#include <map>
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;

class tipoasiento
{
private:
    struct datos{string clasificacion;int costo;};
    map<int,datos> datosasiento;  //<id:clasificacion,costo>
public:
    tipoasiento();
    void PrintAsientos();
    string consultarAsiento(int);
};

#endif // TIPOASIENTO_H
