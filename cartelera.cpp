#include "cartelera.h"

cartelera::cartelera()
{
    ifstream fileinput;
    fileinput.open("../Parcial/Data_Base/Cartelera.txt",ios::in);
    if(fileinput.fail()){
        cout<<"No se pudo abrir el archivo, verifique que el archivo si exista"<<endl;
        exit(1);//Si no se pudo abrir el archivo termina la ejecucion del programa
    }
    string clavem; //clave del mapa
    string linea;
    int id;
    getline(fileinput,clavem);
    while(!fileinput.eof()){   //Mientras no sea el final del archivo
            datoscartelera datos;
            id=atoi(clavem.c_str());
            getline(fileinput,linea);
            datos.idpelicula=atoi(linea.c_str());
            getline(fileinput,linea);
            datos.fecha=linea;
            getline(fileinput,linea);
            datos.hora=linea;
            getline(fileinput,linea);
            datos.idsala=atoi(linea.c_str());
            Cartelera[id]=datos;
            getline(fileinput,clavem);
        }
    fileinput.close();

}

void cartelera::Insert()
{
    int id,idpelicula;
    string fecha,hora,sala;
    cin.sync();
    id=Cartelera.size()+1;
    datoscartelera d;
    cout<<"Seleccione La pelicula para ingresar a cartelera: ";cin>>idpelicula;
    d.idpelicula=idpelicula;
    fecha=ValidarFecha();
    d.fecha=fecha;
    hora=ValidarHora();
    cin.sync();//Limpia el bufer de entrada
    cout<<"Ingrese sala: "<<endl;cin>>sala;
    Cartelera[id]=d;
    cout<<"La pelicula ha sido ingresada,"
          " por favor seleccione la opcion programar funcion"
          " para poner la pelicula en cartelera"<<endl;
    system("pause");
}

string cartelera::ValidarFecha()
{
    return " ";
}

string cartelera::ValidarHora()
{
    return  " ";
}
