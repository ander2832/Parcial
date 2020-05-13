#include "sala.h"

sala::sala()
{
    ifstream fileinput;
    fileinput.open("../Parcial/Data_Base/Sala.txt",ios::in);
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
            d.filas=atoi(linea.c_str());
            getline(fileinput,linea);
            d.columnas=atoi(linea.c_str());
            getline(fileinput,linea);
            d.tipoasiento=atoi(linea.c_str());
            saladatos[clavem]=d;
            getline(fileinput,linea);


        }
    fileinput.close();


    fileinput.open("../Parcial/Data_Base/Asiento.txt",ios::in);
    if(fileinput.fail()){
        cout<<"No se pudo abrir el archivo, verifique que el archivo si exista"<<endl;
        exit(1);//Si no se pudo abrir el archivo termina la ejecucion del programa
    }
    int clave; //clave del mapa
    getline(fileinput,linea);
    while(!fileinput.eof()){   //Mientras no sea el final del archivo
            dato d;
            clave=atoi(linea.c_str());
            getline(fileinput,linea);
            d.clasificacion=linea;
            getline(fileinput,linea);
            d.costo=atoi(linea.c_str());
            datosasiento[clave]=d;
            getline(fileinput,linea);


        }
    fileinput.close();
}

bool sala::isVoid()
{
    if(saladatos.size()==0){
        return true;
    }else{
        return false;
    }
}

void sala::Insert(int id, int filas, int columnas,int tipoasiento)
{

    if ( saladatos.find(id) == saladatos.end() ) {
        saladatos[id]={filas,columnas,tipoasiento};
        cout<<"La sala ha sido registrada"<<endl;

    } else{
      cout<<"La sala "<<id<<" ya se encuentra registrada"<<endl;
      system("pause");
    }
}


void sala::PrintSalas()
{
   if(saladatos.size()!=0){
       for(auto i=begin(saladatos);i!=end(saladatos);i++){
        cout<<"sala "<<i->first<<" "<<datosasiento[i->second.tipoasiento].clasificacion<<endl;
        }
       }else{
       cout<<"No hay salas registradas"<<endl;
        system("pause");
    }
}

void sala::PrintAsientos()
{
   for(auto i=begin(datosasiento);i!=end(datosasiento);i++){
        cout<<i->first<<" "<<i->second.clasificacion<<" "<<i->second.costo<<endl;
    }
}
