#ifndef ADMIN_H
#define ADMIN_H

#include <string.h>
#include <map>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;
class admin
{
private:
    string cc, clave;
public:
    admin();//constructor que obtiene el usuario y la contraseña de sudo.txt
    bool Login();//inicio de sesion, retorna true si el usuario y contraeña es correcta
};

#endif // ADMIN_H
