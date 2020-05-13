#include "tipoasiento.h"

tipoasiento::tipoasiento()
{
    ifstream fileinput;
    fileinput.open("../Parcial/Data_Base/Asiento.txt",ios::in);
    if(fileinput.fail()){
        cout<<"No se pudo abrir el archivo, verifique que el archivo si exista"<<endl;
        exit(1);//Si no se pudo abrir el archivo termina la ejecucion del programa
    }
    int clavem; //clave del mapa
    string linea;
    getline(fileinput,linea);
    while(!fileinput.eof()){   //Mientras no sea el final del archivo
            datos d;
            clavem=atoi(linea.c_str());
            getline(fileinput,linea);
            d.clasificacion=linea;
            getline(fileinput,linea);
            d.costo=atoi(linea.c_str());
            datosasiento[clavem]=d;
            getline(fileinput,linea);


        }
    fileinput.close();
}

void tipoasiento::PrintAsientos()
{
    for(auto i=begin(datosasiento);i!=end(datosasiento);i++){
        cout<<i->first<<" "<<i->second.clasificacion<<" "<<i->second.costo<<endl;
    }
}

string tipoasiento::consultarAsiento(int id)
{
    return datosasiento[id].clasificacion;
}


