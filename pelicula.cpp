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
    getline(fileinput,clavem);
    while(!fileinput.eof()){
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
            pelidatos[id]=d;
            getline(fileinput,clavem);

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
        file<<to_string(i->first)<<"\n"<<i->second.nombre<<"\n"<<i->second.genero<<"\n"<<i->second.duracion<<"\n"<<i->second.clase<<endl;

    }
    file.close();
}

void Pelicula::Insert()
{
    int id,duracion;
    string nombre,genero,clase;
    cin.sync();
    id=pelidatos.size()+1;
        datos d;
        cin.sync();//Limpia el bufer de entrada
        cout<<"Nombre: ";getline(cin,nombre);
        d.nombre=nombre;
        cin.sync();
        cout<<"Genero: ";getline(cin,genero);
        d.genero=genero;
        cin.sync();
        cout<<"Duracion: ";cin>>duracion;
        d.duracion=duracion;
        cin.sync();
        cout<<"Clase: ";getline(cin,clase);
        d.clase=clase;

        pelidatos[id]=d;
        cout<<"La pelicula ha sido ingresada,"
              " por favor seleccione la opcion programar funcion"
              " para poner la pelicula en cartelera"<<endl;
        system("pause");

}

void Pelicula::Printpeliculas()
{
    cout <<"-------------------------------------------\n\n"<<endl;
    for(auto i=begin(pelidatos);i!=end(pelidatos);i++){
        cout<<i->first<<" "<<i->second.nombre<<" "<<i->second.genero<<" "<<i->second.duracion<<" "<<i->second.clase<<endl;
    }
}

