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

void cartelera::Insert(int pelicula, int sala)
{
    int id;
    id=Cartelera.size()+1;
    datoscartelera d;
    d.idpelicula=pelicula;
    string fecha=ValidarFecha(), hora=ValidarHora();
    d.fecha=fecha;
    d.hora=hora;
    d.idsala=sala;
    string h="";
    int size=hora.length();
    for(int i=0;i<size;i++){
        if(hora[i]==':'){
            break;
        }else{
           h=h+hora[i];
        }
    }
    bool funcion;   //true si hay un cruce de horarios
    string hour;
    for(auto i=begin(Cartelera);i!=end(Cartelera);i++){
        hour="";
        hora=i->second.hora;
        size=hora.length();
        for(int j=0;j<size;j++){
            if(hour[j]==':'){
                break;
            }else{
               hour=hour+hora[j];
            }
        }
        if(i->second.idsala==sala  && i->second.fecha==fecha && (atoi(h.c_str())<2+atoi(hour.c_str())  || atoi(h.c_str())>2+atoi(hour.c_str()) )){
           funcion=true;
        }
    }
    if(funcion != true){
        Cartelera[id]=d;
        cout<<endl<<"La funcion ha sido programada \n"<<endl;
        system("pause");
    }else{
        cout<<"\nHay un cruce de horarios con otra pelicula\n"
              " Selecciona otra sala u otro horario \n"<<endl;
        system("pause");
    }

}

string cartelera::ValidarFecha()
{
    int dia,mes,anio;
    cout<<"Dia: ";cin>>dia;
    while(dia<1 || dia>31){
        cout<<"Por favor ingrese un dia valido.."<<endl;
        cout<<"Dia: ";cin>>dia;
    }
    cout<<"Mes: ";cin>>mes;
    while(mes<1 || mes>12){
        cout<<"Por favor ingrese un mes valido.."<<endl;
        cout<<"Mes: ";cin>>mes;
    }
    cout<<"Anio: ";cin>>anio;
    while(anio<2020){
        cout<<"Por favor ingrese un anio valido.."<<endl;
        cout<<"Anio: ";cin>>anio;
    }
    string _dia=to_string(dia),_mes=to_string(mes),_anio=to_string(anio);
    if(_dia.length()==1){
        _dia='0'+_dia;
    }
    if(_mes.length()==1){
        _mes='0'+_mes;
    }


    return _dia+_mes+_anio;
}

string cartelera::ValidarHora()
{
    int hora,minuto;
    cout<<"Hora (24 horas): ";cin>>hora;
    while(hora<0 || hora>23){
        cout<<"Por favor ingrese una hora valida..."<<endl;
        cout<<"Hora (24 horas): ";cin>>hora;
    }
    cout<<"Minuto: ";cin>>minuto;
    while(minuto<1 || minuto>59){
        cout<<"Por favor ingrese un minuto valido.."<<endl;
        cout<<"Minuto: ";cin>>minuto;
    }
    string _hora=to_string(hora),_minuto=to_string(minuto);


    return _hora+':'+_minuto;

}

void cartelera::Guardar()
{
    ofstream file;
    file.open("../Parcial/Data_Base/Cartelera.txt",ios::out);
    if(file.fail()){
        cout<<"No se pudo Guardar"<<endl;
        exit(1);//termina la ejecucion del programa
    }
    for(auto i=begin(Cartelera);i!=end(Cartelera);i++){
        file<<i->first<<"\n"<<i->second.idpelicula<<"\n"<<i->second.fecha<<"\n"<<i->second.hora<<"\n"<<i->second.idsala<<endl;

    }
    file.close();
}
