#include <iostream>
#include <cstdio>
#include <sys/time.h>
using namespace std;

void Matriz_por_Vector_serial(const int *matriz,const int *vector, int fila,int columna, int *respuesta ){
  for (int i = 0; i < columna; i++) {
    int cons = 0;
    for (int j = 0; j < fila; j++) {
      cons += matriz[i + columna + j] * vector[j];
    }
    respuesta[i] = cons;
  }
}

double gettime(){
  struct timeval tp;
  gettimeofday(&tp, nullptr);
  return tp.tv_sec + tp.tv_usec/(double)1.0e6;
}

void Display_Matriz(int * matrix, int fila, int columna){
  for (int i = 0; i < (fila * columna); i++) {
    cout << " " << matrix[i];
    if ((i+1) % fila == 0) {
      cout << "\n";
    }
  }
  cout << endl;
}

void Display_Vector(int * vector, int columna){
  for (int i = 0; i < columna; i++) {
    cout << " " << vector[i] << endl;
  }
  cout << endl;
}

int main() {
  int fila = 10000;
  int columna = 10000;

  double tstart = gettime();

  int * matriz = new int[fila * columna];
  for (int i = 0; i < (fila * columna); i++) {
    matriz[i] = 1;
  }

  int * vector = new int[columna];
  for (int i = 0; i < columna; i++) {
    vector[i] = 2;
  }

  int * respuesta = new int[columna];
  Matriz_por_Vector_serial(matriz, vector, fila, columna, respuesta);

  double tstop = gettime();


  // cout << "matriz " << "(" << fila << "*" << columna << ") : \n";
  // Display_Matriz(matriz, fila, columna);
  // cout << "vector " << "(1" << "*" << columna << ") : \n";
  // Display_Vector(vector, columna);


  cout << "Time: " << tstop-tstart << endl;

   // cout << "matriz * vector" << "(1" << "*" << columna << ") : \n";;
   // Display_Vector(respuesta, columna);

  delete[] matriz;
  delete[] vector;
  delete[] respuesta;
  return 0;
}
