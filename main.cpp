#include <iostream>
#include <stdlib.h>

#include "usuario.h"
#include "admin.h"
#include "pelicula.h"
#include "cartelera.h"
#include "sala.h"


using namespace std;
usuario DatosUsuario=usuario();
admin Administrador=admin();
Pelicula peli=Pelicula();
cartelera datosCartelera=cartelera();
sala saladatos=sala();

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
            if(Administrador.Login()==true){  //si el usuario y contraseña es correcto
                bool login=true;
                while(login==true){  //Mientras el administrador no cierre sesion
                cout <<"-------------------------------------------\n\n"<<endl;
                cout<<"1) Ingresar Pelicula "<<endl;
                cout<<"2) Programar Funcion"<<endl;
                cout<<"3) Administrar Salas"<<endl;
                cout<<"4) Tipos de asientos"<<endl;
                cout<<"5) Cambiar clave"<<endl;
                cout<<"6) Reporte de ventas"<<endl;
                cout<<"7) Regresar"<<endl;
                cout<<"8) Cerrar sesion"<<endl;
                int optionadmin;
                cin>>optionadmin;
                switch (optionadmin) {
                case 1:
                    peli.Insert();
                    peli.Guardar();
                    break;
                case 2:
                    if(saladatos.isVoid()==false){ //si hay salas registradas
                        cout<<"Seleccione La pelicula para ingresar a cartelera: \n"<<endl;
                        int npelis=peli.Printpeliculas();//Imprime todas las peliculas guardadas
                        int pelicula,sala;
                        cin>>pelicula;
                        while(pelicula>npelis || pelicula<1){
                            cout<<"Por favor seleccione una opcion valida"<<endl;
                            cin>>pelicula;
                        }
                        cout<<"Seleccione una sala para la pelicula: "<<endl;
                        saladatos.PrintSalas();
                        cin>>sala;
                        while(saladatos.Exist(sala)==false){
                            cout<<"Seleccione una valida.. "<<endl;
                            cout<<"Sala: ";cin>>sala;
                        }
                        datosCartelera.Insert(pelicula,sala);
                        datosCartelera.Guardar();


                    }else{
                        cout<<"No se puede programar funcion ya que no hay salas registradas"<<endl;
                    }

                    break;
                case 3:
                    cout <<"-------------------------------------------\n\n"<<endl;
                    cout<<"1) Ingresar sala Nueva"<<endl;
                    cout<<"2) Ver salas Registradas"<<endl;
                    cout<<"3) Regresar"<<endl;
                    int optionsala;
                    cin >>optionsala;
                    switch (optionsala) {
                    case 1:
                        int id,filas,columnas,tipoasiento;
                        cout<<"Numero de sala: ";cin>>id;
                        cout<<"Numero de filas: ";cin>>filas;
                        while(filas>26){
                            cout<<"La sala no puede tener mas de 26 filas "<<endl;
                            cin>>filas;
                        }
                        cout<<"Numero de columnas: ";cin>>columnas;
                        cout<<"Seleccione un tipo de asiento "<<endl;
                        saladatos.PrintAsientos();
                        cin>>tipoasiento;
                        saladatos.Insert(id,filas,columnas,tipoasiento);
                        saladatos.Guardarsala();
                        break;
                    case 2:
                        saladatos.PrintSalas();
                        break;
                    default:
                        break;

                    }
                    break;
                case 4:
                    cout <<"-------------------------------------------\n\n"<<endl;
                    saladatos.PrintAsientos();
                    cout<<"\n1) Ingresar un tipo nuevo"<<endl;
                    cout<<"2) Modificar Precio"<<endl;
                    cout<<"3) Regresar"<<endl;
                    int optionasientos;
                    cin>>optionasientos;
                    switch (optionasientos) {
                    case 1:
                        saladatos.InsertAsiento();
                        saladatos.Guardarasiento();
                        break;
                    case 2:
                        saladatos.CambiarPrecioAsiento();
                        saladatos.Guardarasiento();
                        break;
                    }
                    break;
                case 5:
                    Administrador.cambiarclave();
                    Administrador.Guardar();
                    break;
                case 6:

                    break;
                default:
                    login=false;
                    break;
                 }
                }

            }

            break;
        case 2:
            cout <<"-------------------------------------------\n\n"<<endl;
            cout<<"1) Iniciar Sesion"<<endl;
            cout<<"2) Registrarse"<<endl;
            cout<<"3) Regresar"<<endl;
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
            default:
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
