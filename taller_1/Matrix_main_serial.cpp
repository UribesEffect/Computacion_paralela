#include "Matrix.hpp"
#include <iostream>
#include <cstdio>
#include <sys/time.h>
#include <fstream>
using namespace std;

double gettime(){
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return tp.tv_sec + tp.tv_usec/(double)1.0e6;
}

int main(){

    int filas = 1000;
    int columnas = 1000;

    // cout << "/////////////////////" << '\n';
    MatrixOne first_matriz(columnas, filas);
    // cout << "///primera matriz///" << '\n';
    // first_matriz.display();

    // cout << "/////////////////////" << '\n';
    // cout << "///segunda matriz///" << '\n';
    MatrixOne second_matriz(columnas, filas);
    second_matriz = first_matriz;
    // second_matriz.display();

    // cout << "////////////////////////" << '\n';
    // cout << "///primera * segunda///" << '\n';
    ofstream archivo;
    archivo.open("SERIAL.txt");
    archivo << "TIEMPOS MULTIPLICACION DE MATRICES SERIAL\n";
    archivo << "tiempo total" << "\t" << "tiempo total al cuadrado\n";

    for (int i = 0; i < 50; i++) {

      double tstart = gettime();
      MatrixOne first_x_second = first_matriz*second_matriz;
      double tstop = gettime();

      double t_total = tstop - tstart;
      double t_total_cuadrado = t_total*t_total;

      archivo << t_total << "\t" << t_total_cuadrado << "\n";
    }


    return 0;
}
