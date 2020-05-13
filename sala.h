#ifndef SALA_H
#define SALA_H
#include <vector>
#include <iostream>

using namespace std;

class Sala
{
private:
    //Creamos una matriz de bool (true:reservado, false:disponible)
    // que representa los asientos en la sala de cine
    vector<vector<bool>> matriz;
    int fil;
    int col;
public:
    Sala(int, int);         //constructor
    void PrintAsientos();   //Imprime la matriz de asientos
};

#endif // SALA_H
