#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;

class usuario
{
private:
    struct userdata{string nombre,clave; int edad;};
    map<string,userdata> Usuario; //<cc:{nombre, clave, edad}>
public:
    usuario();// constructor que carga los datos del archivo en el atributo Usuario
    void InsertUser();       //Registrar un usuario
    void SelectUser(string); //Consultar datos de un Usuario,recibe como parametro la cedula
    bool Login();  //inicio de sesion, retorna true si el usuario y contraeña es correcta
    void Guardar(); //Guarda los datos en el archivo
};

#endif // USUARIO_H
