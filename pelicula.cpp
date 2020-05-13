#include "pelicula.h"

Pelicula::Pelicula()
{
    ifstream fileinput;
    fileinput.open("../Parcial/Data_Base/Pelicula.txt",ios::in);
    if(fileinput.fail()){
        cout<<"No se pudo abrir el archivo, verifique que el archivo si exista"<<endl;
        exit(1);//Si no se pudo abrir el archivo termina la ejecucion del programa
    }
    string clavem; //clave del mapa
    string linea;//variable que va recorriendo el archivo linea por linea
    while(true){
        //Leemos el archivo y lo guardamos en un mapa (clave: cedula, valor:datos del usuario)
        getline(fileinput,clavem);
        int id=atoi(clavem.c_str());
            datos d;
            getline(fileinput,linea);
            d.nombre=linea;
            getline(fileinput,linea);
            d.genero=linea;
            getline(fileinput,linea);
            d.duracion=atoi(linea.c_str());
            getline(fileinput,linea);
            d.clase=linea;
            if(fileinput.eof()){ //si el archivo termino se sale del ciclo
                break;
            }
            pelidatos[id]=d;
        }
    fileinput.close();
}

void Pelicula::Guardar()
{
    ofstream file;
    file.open("../Parcial/Data_Base/Pelicula.txt",ios::out);
    if(file.fail()){
        cout<<"No se pudo Guardar"<<endl;
        exit(1);//termina la ejecucion del programa
    }
    for(auto i=begin(pelidatos);i!=end(pelidatos);i++){
        file<<i->first<<"\n"<<i->second.nombre<<"\n"<<i->second.genero<<"\n"<<i->second.duracion<<"\n"<<i->second.clase<<endl;

    }
    file.close();
}

