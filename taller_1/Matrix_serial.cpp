
#include "Matrix.hpp"
#include <iostream>
#include <thread>
using namespace std;

MatrixOne::MatrixOne(int c, int f){
    filas = f;
    columnas = c;
    array = new int[filas * columnas];
    for(int i = 0; i < (filas * columnas); i++){
        array[i] = 1;
    }
}

MatrixOne::~MatrixOne(){
    delete[] array;
}

MatrixOne& MatrixOne::operator =(MatrixOne &M){//sobrecargando operador =
    int Newdimx = M.get_dimx();
    int Newdimy = M.get_dimy();
    array = new int[Newdimx * Newdimy];
    int count = 0;
    for(int i = 0; i < Newdimy; i++){//metiendo los valores de la matiz a la nueva
        for(int j = 0; j < Newdimx; j++){
              int value = M.get(j, i);
              array[count] = value;
              count++;
        }
    }

    return *this;//retorno a ella misma
}

MatrixOne operator * (MatrixOne &M1, MatrixOne &M2){
    int help_x = M1.get_dimy();
    int help_y = M2.get_dimx();
    MatrixOne prueba(help_x, help_y);
    for(int i = 0; i <  M1.get_dimy(); i++){

        for(int j = 0; j < M2.get_dimx(); j++){
            int value = 0;

            for(int k = 0; k < M2.get_dimy(); k++){
                value += M1.get(i, k) * M2.get(k, j);

                if(k + 1 == M2.get_dimy()){
                    prueba.set(i, j, value);
                }
            }
        }
    }

    return prueba;
}


void MatrixOne::display(){
    cout << "inicio" << '\n';
    for(int i = 0; i < filas * columnas; i++){
        cout << " " << array[i];
        if((i+1) % filas == 0){
            cout << "\n";
        }
    }
    cout << "fin\n";
}
