#include "sala.h"

Sala::Sala(int _fil, int _col){
    // Inicializamos la matriz con todos los asientos disponibles
    col=_col;
    fil=_fil;
    vector<bool> fila;  //Creamos una fila de tamaño col
    for(int i=0; i<col; i++){
        fila.push_back(false);
    }
    for(int i=0; i<fil; i++){
        matriz.push_back(fila);
    }

}

void Sala::PrintAsientos(){  //Imprime todos los asientos (- es disponible y + es reservado)
    for(int i=0;i<fil;i++){
        for(int j=0; j< col;j++){
            if(matriz[i][j]==0){
            cout <<"- ";
            }else{
               cout <<"+ ";
            }
        }
        cout << endl;
    }
}
