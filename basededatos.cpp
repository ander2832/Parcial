#include "basededatos.h"

basededatos::basededatos()
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
            datossala d;
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
            datoasiento d;
            clave=atoi(linea.c_str());
            getline(fileinput,linea);
            d.clasificacion=linea;
            getline(fileinput,linea);
            d.costo=atoi(linea.c_str());
            datosasiento[clave]=d;
            getline(fileinput,linea);


        }
    fileinput.close();

    fileinput.open("../Parcial/Data_Base/Cartelera.txt",ios::in);
    if(fileinput.fail()){
        cout<<"No se pudo abrir el archivo, verifique que el archivo si exista"<<endl;
        exit(1);//Si no se pudo abrir el archivo termina la ejecucion del programa
    }
    //string clavem; //clave del mapa
    //string linea;
    int id;
    string clavecartelera;
    getline(fileinput,clavecartelera);
    while(!fileinput.eof()){   //Mientras no sea el final del archivo
            datoscartelera datos;
            id=atoi(clavecartelera.c_str());
            getline(fileinput,linea);
            datos.idpelicula=atoi(linea.c_str());
            getline(fileinput,linea);
            datos.fecha=linea;
            getline(fileinput,linea);
            datos.hora=linea;
            getline(fileinput,linea);
            datos.idsala=atoi(linea.c_str());
            Cartelera[id]=datos;
            getline(fileinput,clavecartelera);
        }
    fileinput.close();

    fileinput.open("../Parcial/Data_Base/Pelicula.txt",ios::in);
    if(fileinput.fail()){
        cout<<"No se pudo abrir el archivo, verifique que el archivo si exista"<<endl;
        exit(1);//Si no se pudo abrir el archivo termina la ejecucion del programa
    }
    string clavepelicula; //clave del mapa
    getline(fileinput,clavepelicula);
    while(!fileinput.eof()){
        int id=atoi(clavepelicula.c_str());
            datospelicula d;
            getline(fileinput,linea);
            d.nombre=linea;
            getline(fileinput,linea);
            d.genero=linea;
            getline(fileinput,linea);
            d.duracion=atoi(linea.c_str());
            getline(fileinput,linea);
            d.clase=atoi(linea.c_str());
            pelidatos[id]=d;
            getline(fileinput,clavepelicula);

        }
    fileinput.close();

    fileinput.open("../Parcial/Data_Base/Usuario.txt",ios::in);
    if(fileinput.fail()){
        cout<<"No se pudo abrir el archivo, verifique que el archivo si exista"<<endl;
        exit(1);//Si no se pudo abrir el archivo termina la ejecucion del programa
    }
    string cc; //clave del mapa
    int edad;
    getline(fileinput,cc);
    while(!fileinput.eof()){   //Mientras no sea el final del archivo
        //Leemos el archivo y lo guardamos en un mapa (clave: cedula, valor:datos del usuario)
            userdata datos;
            getline(fileinput,linea);
            datos.nombre=linea;
            getline(fileinput,linea);
            edad=atoi(linea.c_str());
            datos.edad=edad;
            getline(fileinput,linea);
            datos.clave=linea;
            Usuario[cc]=datos;
            getline(fileinput,cc);
        }
    fileinput.close();


    fileinput.open("../Parcial/Data_Base/Reserva.txt",ios::in);
    if(fileinput.fail()){
        cout<<"No se pudo abrir el archivo, verifique que el archivo si exista"<<endl;
        exit(1);//Si no se pudo abrir el archivo termina la ejecucion del programa
    }
    string c; //clave del mapa
    getline(fileinput,cc);
    while(!fileinput.eof()){   //Mientras no sea el final del archivo
        //Leemos el archivo y lo guardamos en un mapa (clave: cedula, valor:datos del usuario)
            datosreserva datos;
            getline(fileinput,linea);
            datos.idfuncion=atoi(linea.c_str());
            getline(fileinput,linea);
            datos.idusuario=linea;
            getline(fileinput,linea);
            datos.asientofila=atoi(linea.c_str());
            getline(fileinput,linea);
            datos.asientocolumna=atoi(linea.c_str());
            reserva[atoi(cc.c_str())]=datos;
            getline(fileinput,cc);
        }
    fileinput.close();


}

bool basededatos::salaisVoid()
{
    if(saladatos.size()==0){
        return true;
    }else{
        return false;
    }
}

void basededatos::Insertsala(int id, int filas, int columnas,int tipoasiento)
{

    if ( saladatos.find(id) == saladatos.end() ) {
        saladatos[id]={filas,columnas,tipoasiento};
        cout<<"La sala ha sido registrada"<<endl;

    } else{
      cout<<"La sala "<<id<<" ya se encuentra registrada"<<endl;
      system("pause");
    }
}

void basededatos::InsertAsiento()
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


void basededatos::PrintSalas()
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

void basededatos::PrintAsientos()
{
   for(auto i=begin(datosasiento);i!=end(datosasiento);i++){
        cout<<i->first<<" "<<i->second.clasificacion<<" $"<<i->second.costo<<endl;
   }
}

bool basededatos::Existsala(int id)
{
    if ( saladatos.find(id) == saladatos.end() ){
      return false;
    }else{
        return true;
    }
}

void basededatos::Guardarsala()
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

void basededatos::Guardarasiento()
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

void basededatos::CambiarPrecioAsiento()
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

void basededatos::Insertpeliculacartelera(int pelicula, int sala)
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

string basededatos::ValidarFecha()
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

string basededatos::ValidarHora()
{
    int hora,minuto;
    cout<<"Hora (24 horas): ";cin>>hora;
    while(hora<0 || hora>23){
        cout<<"Por favor ingrese una hora valida..."<<endl;
        cout<<"Hora (24 horas): ";cin>>hora;
    }
    cout<<"Minuto: ";cin>>minuto;
    while(minuto<0 || minuto>59){
        cout<<"Por favor ingrese un minuto valido.."<<endl;
        cout<<"Minuto: ";cin>>minuto;
    }
    string _hora=to_string(hora),_minuto=to_string(minuto);


    return _hora+':'+_minuto;

}

void basededatos::Guardarcartelera()
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





void basededatos::Guardarpelicula()
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

void basededatos::Insertpelicula()
{
    int id,duracion,clase;
    string nombre,genero;
    cin.sync();
    id=pelidatos.size()+1;
        datospelicula d;
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
        cout<<"Clase: ";cin>>clase;
        d.clase=clase;

        pelidatos[id]=d;
        cout<<"La pelicula ha sido ingresada,"
              "  seleccione la opcion programar funcion"
              " para poner la pelicula en cartelera"<<endl;
        system("pause");

}

int basededatos::Printpeliculas()
{
    int j=0;
    for(auto i=begin(pelidatos);i!=end(pelidatos);i++){
        cout<<i->first<<") "<<i->second.nombre<<" "<<i->second.genero<<" "<<i->second.duracion<<" min "<<i->second.clase<<"+"<<endl;
        j=j+1;
    }
    return j;
}




void basededatos::InsertUser()
{
    int edad;
    string cc,clave,nombre,_edad;
    cin.sync();
    cout<<"Cedula: ";cin>>cc;;
    if ( Usuario.find(cc) == Usuario.end() ) {

        cin.sync();//Limpia el bufer de entrada
        cout<<"Nombre: ";getline(cin,nombre);
        cin.sync();
        cout<<"Edad: ";getline(cin,_edad);
        cin.sync();
        cout<<"Clave: ";getline(cin,clave);

        edad=atoi(_edad.c_str());
        userdata datos={nombre,clave,edad};
        Usuario[cc]=datos;
        cout<<"\n\n El usuario ha sido registrado\n"<<endl;

    } else {
      cout<<"El Usuario ya esta Registrado"<<endl;
      system("pause");
    }

}

bool basededatos::Login()
{
    string ced,clave;
    cout<<"Cedula: ";cin>>ced;
    cout<<"Clave: ";cin>>clave;
    if (Usuario[ced].clave==clave) {
        cc=ced;
        return true;
    }else{
        cout<<"Usuario o contrasenia incorrecta"<<endl;
        system("pause");
        return false;

    }
}

void basededatos::Guardarusuario()
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

void basededatos::PrintHorarios(int pelicula)
{
    int p=false;// true si encuentra horarios
    cout<<" Fecha (ddmmaaaa)\n"<<endl;
    for(auto i=begin(Cartelera);i!=end(Cartelera);i++){
        if(i->second.idpelicula==pelicula){
            p=true;
            cout<<i->first<<") Fecha: "<<i->second.fecha<<" Hora: "<<i->second.hora<<" Sala: "<<i->second.idsala<<"  "<<datosasiento[saladatos[i->second.idsala].tipoasiento].clasificacion<<" $"<<datosasiento[saladatos[i->second.idsala].tipoasiento].costo<<endl;
        }

    }
    if(p==false){
        cout<<"Esta pelicula aun no tiene horarios disponibles"<<endl;
        system("pause");
    }
}

void basededatos::Newreserva(int funcion)
{

    int col = saladatos[Cartelera[funcion].idsala].columnas;
    int fil = saladatos[Cartelera[funcion].idsala].filas;
    bool **puntero_matriz;
    puntero_matriz=new bool *[fil];
    for (int i = 0 ; i <fil; i ++) {
        puntero_matriz[i]=new bool [col];
        for ( int j = 0 ; j <col; j ++) {
            *(*(puntero_matriz+i)+j)=false;
            for(auto k=begin(reserva);k!=end(reserva);k++){
                if(i+1==k->second.asientofila && j+1==k->second.asientocolumna && funcion==k->second.idfuncion){
                    *(*(puntero_matriz+i)+j)=true;
                    break;
                }
            }
        }
    }
    cout<<" (-) Asiento disponible,   (+) Asiento reservado "<<endl;
    cout<<"    ";
    char fi=65;
    for(int j=1; j<=col;j++){
        if(j<10){
          cout<<j<<"  ";
        }else{
          cout<<j<<" ";
        }
    }
    cout<<endl;
    for( int i = 0 ; i <fil; i ++) {
        cout<<fi<<"  ";
          for( int j = 0 ; j <col; j ++) {
                if (*(*(puntero_matriz+i)+j)== false ) {
                cout << " - " ;
                }else{
                   cout << " + " ;
                }
            }
            cout << endl;
            fi=fi+1;
        }
    int filareserva, columnareserva;
    char fila;
    cout<<"Ingrese Fila (Mayuscula): ";cin>>fila;
    cout<<"Ingrese columna: ";cin>>columnareserva;
    filareserva=fila-64;
    int i,j;
    i=filareserva-1;
    j=columnareserva-1;

    while(*(*(puntero_matriz+i)+j)==true){
          cout<<"Asiento no disponible"<<endl;
          cout<<"Ingrese Fila: ";cin>>fila;
          cout<<"Ingrese columna: ";cin>>columnareserva;
          filareserva=fila-64;
          i=filareserva-1;
          j=columnareserva-1;
    }
    int id=reserva.size()+1;
    datosreserva d;
    d.idfuncion=funcion;
    d.idusuario=cc;
    d.asientofila=filareserva;
    d.asientocolumna=columnareserva;
    reserva[id]=d;
    pagar(saladatos[Cartelera[funcion].idsala].tipoasiento);
    for(int i=0;i<fil;i++){
        delete[] puntero_matriz[i];
    }
    delete[] puntero_matriz;
}

bool basededatos::cartelerapelicula(int pelicula, int funcion)
{
    if(Cartelera[funcion].idpelicula==pelicula){
        return true;
    }
    else{
        return false;
    }
}

void basededatos::pagar(int asiento)
{
    int precio=datosasiento[asiento].costo;
    int dineroin,dineroout; //dinero ingresado y devuelta
    cout<<"Cuanto dinero va a ingresar: ";cin>>dineroin;
    while(dineroin<precio){
        cout<<"Dinero insuficiente"<<endl;
        cout<<"Ingrese dinero: ";cin>>dineroin;
    }
    dineroout=dineroin-precio;
    int dinero[10]={0,0,0,0,0,0,0,0,0,0};
    int billetes[10]={50000,20000,10000,5000,2000,1000,500,200,100,50};
    int i=0;
    int n;
    while(i<10){
       n=dineroout/billetes[i];
       dinero[i]=n;
       dineroout -= n*billetes[i];
       i +=1;
    }
    i=0;
    cout<<"Transaccion exitosa"<<endl;
    cout<<"Su devuelta es: "<<endl;
    while(i<10){
        if(1<5){
         cout<<dinero[i]<<" billetes de "<<billetes[i]<<endl;
        }else{
            cout<<dinero[i]<<" Monedas de "<<billetes[i]<<endl;
        }
        i +=1;
    }
    cout<<"Faltante: "<<dineroout<<endl;
    Guardarreserva();
}

void basededatos::Guardarreserva()
{
    ofstream file;
    file.open("../Parcial/Data_Base/Reserva.txt",ios::out);
    if(file.fail()){
        cout<<"No se pudo Guardar"<<endl;
        exit(1);//termina la ejecucion del programa
    }
    for(auto i=begin(reserva);i!=end(reserva);i++){
        file<<i->first<<"\n"<<i->second.idfuncion<<"\n"<<i->second.idusuario<<"\n"<<i->second.asientofila<<"\n"<<i->second.asientocolumna<<endl;

    }
    file.close();
}

void basededatos::PrintReporte()
{
    int totalventas=0;
    int venta;
    cout<<"Reporte de ventas: "<<endl;
    for(auto i=begin(reserva);i!=end(reserva);i++){
        venta=datosasiento[saladatos[Cartelera[i->second.idfuncion].idsala].tipoasiento].costo;
        totalventas=totalventas+venta;
        cout<<i->first<<" $"<<venta<<endl;
    }
    cout<<"\n Total Ventas: "<<totalventas<<endl;
}

bool basededatos::EdadPelicula(int pelicula)
{
    int edad=Usuario[cc].edad;
    if(edad<pelidatos[pelicula].clase){
        return false;// no puede ver la pelicula
    }else{
        return true;
    }

}
