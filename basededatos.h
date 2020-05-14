#ifndef BASEDEDATOS_H
#define BASEDEDATOS_H

#include <string.h>
#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;

class basededatos
{
private:
    //salas
    struct datossala{int filas;int columnas;int tipoasiento;};
    map<int,datossala> saladatos;

    //tipo de asiento
    struct datoasiento{string clasificacion;int costo;};
    map<int,datoasiento> datosasiento;  //<id:clasificacion,costo>

    //cartelera
    struct datoscartelera{int idpelicula; string fecha; string hora; int idsala;};
    map<int,datoscartelera> Cartelera;// <id:{idpelicula, fecha, hora,id sala}

    //pelicula
    struct datospelicula{string nombre; string genero; int duracion; string clase;};
    map<int,datospelicula> pelidatos; //<id:{nombre, genero, duracion, clase}>

    //Usuario
    struct userdata{string nombre,clave; int edad;};
    map<string,userdata> Usuario; //<cc:{nombre, clave, edad}>
    string cc;  //id de usuario que inicia sesion

    //Reserva
    struct datosreserva{int idfuncion; int idusuario; int asientofila; int asientocolumna;};
    map<int,datosreserva> reserva;
public:
    basededatos();
    //Metodos salas y asientos
    bool salaisVoid();//retorna true si no hay salas registradas
    void Insertsala(int, int, int, int);//Registra una nueva sala
    void InsertAsiento();// para insertar un nuevo tipo de asiento
    void PrintSalas();
    void PrintAsientos();
    bool Existsala(int); //retorna true si la sala existe
    void Guardarsala(); //Guarda los cambios hechos al archivo sala
    void Guardarasiento();
    void CambiarPrecioAsiento();//cambiar precio de un asiento

    //metodo cartelera
    void Insertpeliculacartelera(int,int); //Para ingresar una pelicula a la cartelera
    string ValidarFecha();
    string ValidarHora();
    void Guardarcartelera();

    //metodos pelicula
    void Guardarpelicula();//guarda los datos en el archivo
    void Insertpelicula();//insertar una nueva pelicula
    int Printpeliculas();//imprime todas las peliculas retorna la cantidad de peliculas

    //metodos usuario
    void InsertUser();       //Registrar un usuario
    bool Login();  //inicio de sesion, retorna true si el usuario y contraeña es correcta
    void Guardarusuario(); //Guarda los datos en el archivo


    //metodos reserva
    void PrintHorarios(int);
    void Newreserva(int); //Hacer una nueva reserva
    bool cartelerapelicula(int,int);// verifica si en una funcion esta una pelicula

};


#endif // BASEDEDATOS_H
