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

void sala::InsertAsiento()
{
    string clasificacion,costo;
    int id=datosasiento.size()+1;
    cin.sync();
    cout<<"Clasificacion del asiento: ";getline(cin,clasificacion);
    cout<<"Precio del asiento: ";getline(cin,costo);
    datosasiento[id]={clasificacion,atoi(costo.c_str())};
    cout<<"El tipo de asiento se ha registrado "<<endl;
    system("Pause");

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
        cout<<i->first<<" "<<i->second.clasificacion<<" $"<<i->second.costo<<endl;
   }
}

bool sala::Exist(int id)
{
    if ( saladatos.find(id) == saladatos.end() ){
      return false;
    }else{
        return true;
    }
}

void sala::Guardarsala()
{
    ofstream file;
    file.open("../Parcial/Data_Base/Sala.txt",ios::out);
    if(file.fail()){
        cout<<"No se pudo Guardar"<<endl;
        exit(1);//termina la ejecucion del programa
    }
    for(auto i=begin(saladatos);i!=end(saladatos);i++){
        file<<i->first<<"\n"<<i->second.filas<<"\n"<<i->second.columnas<<"\n"<<i->second.tipoasiento<<endl;

    }
    file.close();
}

void sala::Guardarasiento()
{
    ofstream file;
    file.open("../Parcial/Data_Base/Asiento.txt",ios::out);
    if(file.fail()){
        cout<<"No se pudo Guardar"<<endl;
        exit(1);//termina la ejecucion del programa
    }
    for(auto i=begin(datosasiento);i!=end(datosasiento);i++){
        file<<i->first<<"\n"<<i->second.clasificacion<<"\n"<<i->second.costo<<endl;

    }
    file.close();
}

void sala::CambiarPrecioAsiento()
{
   int id, precio;
   cout<<"Seleccione el asiento a modificar: ";cin>>id;
   while(datosasiento.find(id) == datosasiento.end()){
       cout<<"Asiento invalido"<<endl;
       cout<<"Seleccione el asiento a modificar: ";cin>>id;
   }
   cout<<"Precio nuevo: ";cin>>precio;
   datosasiento[id].costo=precio;
   cout<<"Precio Modificado.."<<endl;
   system("Pause");
}
