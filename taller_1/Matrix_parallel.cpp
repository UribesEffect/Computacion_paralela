
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

MatrixOne& MatrixOne::operator = (MatrixOne &M){//sobrecargando operador =
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
    int Nthr = thread:: hardware_concurrency();
    int size = M1.get_dimy();
    int chunk_size = size / Nthr;

    int ayuda_x = M2.get_dimx();
    int ayuda_y = M1.get_dimy();

    MatrixOne AYUDA(ayuda_x, ayuda_y);
    thread thr1(Matrix_Helper, ref(M1), ref(M2), ref(AYUDA), 0, chunk_size+1);
    thread thr2(Matrix_Helper, ref(M1), ref(M2), ref(AYUDA), chunk_size+1, 2*chunk_size+1);
    thread thr3(Matrix_Helper, ref(M1), ref(M2), ref(AYUDA), 2*chunk_size+1, 3*chunk_size+1);
    thread thr4(Matrix_Helper, ref(M1), ref(M2), ref(AYUDA), 3*chunk_size+1, 4*chunk_size+1);
    thread thr5(Matrix_Helper, ref(M1), ref(M2), ref(AYUDA), 4*chunk_size+1, 5*chunk_size+1);
    thread thr6(Matrix_Helper, ref(M1), ref(M2), ref(AYUDA), 5*chunk_size+1, 6*chunk_size+1);
    thread thr7(Matrix_Helper, ref(M1), ref(M2), ref(AYUDA), 6*chunk_size+1, 7*chunk_size+1);

    Matrix_Helper( M1, M2, AYUDA, 7*chunk_size+1, M1.get_dimy());

    thr1.join();
    thr2.join();
    thr3.join();
    thr4.join();
    thr5.join();
    thr6.join();
    thr7.join();

    return AYUDA;
}

void Matrix_Helper(MatrixOne &M1, MatrixOne &M2, MatrixOne &AYUDA, int Matriz1_ini_y, int Matriz1_end_y){
  for(int i = Matriz1_ini_y; i <  Matriz1_end_y; i++){

      for(int j = 0; j < M2.get_dimx(); j++){
          int value = 0;

          for(int k = 0; k < M2.get_dimy(); k++){
              value += M1.get(i, k) * M2.get(k, j);

              if(k + 1 == M2.get_dimy()){
                  AYUDA.set(i, j, value);
              }
          }
      }
   }
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
