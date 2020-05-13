#include "usuario.h"


usuario::usuario(){
    ifstream fileinput;
    fileinput.open("../Parcial/Data_Base/Usuario.txt",ios::in);
    if(fileinput.fail()){
        cout<<"No se pudo abrir el archivo, verifique que el archivo si exista"<<endl;
        exit(1);//Si no se pudo abrir el archivo termina la ejecucion del programa
    }
    string clavem; //clave del mapa
    string linea;
    int edad;
    while(true){   //Mientras no sea el final del archivo
        //Leemos el archivo y lo guardamos en un mapa (clave: cedula, valor:datos del usuario)
        getline(fileinput,clavem);
            userdata datos;
            getline(fileinput,linea);
            datos.nombre=linea;
            getline(fileinput,linea);
            edad=atoi(linea.c_str());
            datos.edad=edad;
            getline(fileinput,linea);
            datos.clave=linea;
            if(fileinput.eof()){ //si el archivo termino se sale del ciclo
                break;
            }
            Usuario[clavem]=datos;
        }
    fileinput.close();

}

void usuario::InsertUser()
{
    string cc,nombre,clave;
    int edad;
    cout<<"Cedula: ";cin>>cc;
    if ( Usuario.find(cc) == Usuario.end() ) {
        cout<<"Nombre: ";cin>>nombre;
        cout<<"Edad: ";cin>>edad;
        cout<<"Clave: ";cin>>clave;
        userdata datos={nombre,clave,edad};
        Usuario[cc]=datos;
        cout<<"\n\n El usuario ha sido registrado\n"<<endl;

    } else {
      cout<<"El Usuario ya esta Registrado"<<endl;
      system("pause");
    }

}

bool usuario::Login()
{
    string cc,clave;
    cout<<"Cedula: ";cin>>cc;
    cout<<"Clave: ";cin>>clave;
    if (Usuario[cc].clave==clave) {
        return true;
    }else{
        cout<<"Usuario o contrasenia incorrecta"<<endl;
        system("pause");
        return false;

    }

}

void usuario::Guardar()
{
    ofstream file;
    file.open("../Parcial/Data_Base/Usuario.txt",ios::out);
    if(file.fail()){
        cout<<"No se pudo Guardar"<<endl;
        exit(1);//termina la ejecucion del programa
    }
    for(auto i=begin(Usuario);i!=end(Usuario);i++){
        file<<i->first<<"\n"<<i->second.nombre<<"\n"<<i->second.edad<<"\n"<<i->second.clave<<endl;

    }
    file.close();
}
