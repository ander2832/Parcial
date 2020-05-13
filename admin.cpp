#include "admin.h"

admin::admin()
{
    ifstream fileinput;
    fileinput.open("../Parcial/Data_Base/Sudo.txt",ios::in);
    if(fileinput.fail()){
        cout<<"No se pudo abrir el archivos "<<endl;
        exit(1);//Si no se pudo abrir el archivo termina la ejecucion del programa
    }
    string linea;
    getline(fileinput,linea);
    cc=linea;
    getline(fileinput,linea);
    clave=linea;
    fileinput.close();
}

void admin::cambiarclave()
{
    cin.sync();
    cout<<"Ingrese nueva clave: ";getline(cin,clave);
    cout<<"Su clave ha sido cambiada "<<endl;
    system("pause");

}

void admin::Guardar()
{
    ofstream file;
    file.open("../Parcial/Data_Base/Sudo.txt",ios::out);
    if(file.fail()){
        cout<<"No se pudo Guardar"<<endl;
        exit(1);//termina la ejecucion del programa
    }
    file<<cc<<endl;
    file<<clave<<endl;
    file.close();
}

bool admin::Login()
{
    string ced,pass;
    cout<<"Cedula: ";
    cin.sync();
    getline(cin,ced);
    cout<<"Clave: ";
    cin.sync();
    getline(cin,pass);
    if (ced==cc && pass==clave) {
        return true;
    }else{
        cout<<"Usuario o contrasenia incorrecta"<<endl;
        system("pause");
        return false;

    }
}
