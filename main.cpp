#include <iostream>
#include <stdlib.h>

#include "admin.h"
#include "basededatos.h"


using namespace std;

admin Administrador=admin();
basededatos db=basededatos();

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
                    db.Insertpelicula();
                    db.Guardarpelicula();
                    break;
                case 2:
                    if(db.salaisVoid()==false){ //si hay salas registradas
                        cout<<"Seleccione La pelicula para ingresar a cartelera: \n"<<endl;
                        int npelis=db.Printpeliculas();//Imprime todas las peliculas guardadas
                        int pelicula,sala;
                        cin>>pelicula;
                        while(pelicula>npelis || pelicula<1){
                            cout<<"Por favor seleccione una opcion valida"<<endl;
                            cin>>pelicula;
                        }
                        cout<<"Seleccione una sala para la pelicula: "<<endl;
                        db.PrintSalas();
                        cin>>sala;
                        while(db.Existsala(sala)==false){
                            cout<<"Seleccione una valida.. "<<endl;
                            cout<<"Sala: ";cin>>sala;
                        }
                        db.Insertpeliculacartelera(pelicula,sala);
                        db.Guardarcartelera();


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
                        db.PrintAsientos();
                        cin>>tipoasiento;
                        db.Insertsala(id,filas,columnas,tipoasiento);
                        db.Guardarsala();
                        break;
                    case 2:
                        db.PrintSalas();
                        break;
                    default:
                        break;

                    }
                    break;
                case 4:
                    cout <<"-------------------------------------------\n\n"<<endl;
                    db.PrintAsientos();
                    cout<<"\n1) Ingresar un tipo nuevo"<<endl;
                    cout<<"2) Modificar Precio"<<endl;
                    cout<<"3) Regresar"<<endl;
                    int optionasientos;
                    cin>>optionasientos;
                    switch (optionasientos) {
                    case 1:
                        db.InsertAsiento();
                        db.Guardarasiento();
                        break;
                    case 2:
                        db.CambiarPrecioAsiento();
                        db.Guardarasiento();
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
            int npeli;
            case 1:
                if(db.Login()==true){  //si el usuario y contraseña es correcto
                    cout <<"-------------------------------------------\n\n"<<endl;
                    cout<<"1) Ver peliculas"<<endl;
                    cout<<"2) Mis Reservas"<<endl;
                    int optionusuario;
                    cin>>optionusuario;
                    switch (optionusuario) {
                    case 1:
                        cout <<"-------------------------------------------\n\n"<<endl;
                        npeli=db.Printpeliculas();
                        int p;
                        cout <<"Seleccione una pelicula ";cin>>p;
                        while(p>npeli || p<1){
                            cout<<"Por favor seleccione una opcion valida"<<endl;
                            cin>>p;
                        }
                        cout <<"-------------------------------------------\n\n"<<endl;
                        db.PrintHorarios(p);
                        int h; //id de la funcion
                        cout<<"Seleccione un Horario: ";cin>>h;
                        while(!db.cartelerapelicula(p,h)){
                            cout<<"Seleccione un Horario valido: ";cin>>h;
                        }
                        db.Newreserva(h);
                        break;
                    case 2:
                        break;
                    default:
                        break;
                    }

                }
                break;
            case 2:
                db.InsertUser();
                db.Guardarusuario();
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
