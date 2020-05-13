#include <iostream>
#include <stdlib.h>

#include "sala.h"
#include "usuario.h"

using namespace std;
usuario DatosUsuario=usuario();

int main()
{
    while(true){
        int option;
        cout <<"\n\n-------------------------------------------\n";
        cout<<"          CINE \n"<<endl;
        cout<<"1) Administrador"<<endl;
        cout<<"2) Cliente"<<endl;
        cout<<"3) Salir"<<endl;
        cin >> option;
        switch (option) {
        case 1:
            cout <<"-------------------------------------------\n\n"<<endl;
            cout<<"1) Ingresar Pelicula"<<endl;

            break;
        case 2:
            cout <<"-------------------------------------------\n\n"<<endl;
            cout<<"1) Iniciar Sesion"<<endl;
            cout<<"2) Registrarse"<<endl;
            int op;
            cin >> op;
            switch (op) {
            case 1:
                if(DatosUsuario.Login()==true){  //si el usuario y contraseña es correcto

                }
                break;
            case 2:
                DatosUsuario.InsertUser();
                DatosUsuario.Guardar();
                break;

            }

            break;

        default:
            exit(1);
            break;
        }
    }
    return 0;
}
