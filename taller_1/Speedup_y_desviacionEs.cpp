#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(){

  //Lectura txt SERIAL.txt
  double suma_tiempos;
  double suma_tiempos_cuadrados;
  string linea;
  ifstream archivo;
  archivo.open("SERIAL.txt");
  if (archivo.is_open()) {
    vector<double> temporal;/*lo hago para ir guardando el tiempo y
    el tiempo al cuadrado en un vector de dos*/
    while (getline(archivo, linea)) {//mientras pueda leer lineas en mi archivo
      if (isdigit(linea[0])) {
        string auxiliar;
        for (size_t i = 0; i < linea.length() + 1 ; i++) {
          if (i == linea.length() || linea[i] == '\t') {
            double mi_numero;
            mi_numero = atof(auxiliar.c_str());//coge todo el numero
            temporal.push_back(mi_numero);
            auxiliar = "";
          }else{
            auxiliar += linea[i];
          }
        }//termina la lectura de una linea
        suma_tiempos += temporal[0];//sumando el antes  del tab
        suma_tiempos_cuadrados += temporal[1];//sumaando despues del tab
        auxiliar = {};//vacio hasta la otra linea
      }
    }
    archivo.close();
  }else{
    cout << "no se puede abrir el archivo\n";
  }
  cout << "///////////////////////////////\n";
  cout << "/////////SERIAL////////////////\n";
  cout << "///////////////////////////////\n";
  cout << "suma de todos los tiempo: " << suma_tiempos << "\n";
  cout << "suma de todos los tiempos cuadrados: " << suma_tiempos_cuadrados << "\n";
  double promedio_tiempos = suma_tiempos / 50;
  double promedio_tiempos_cuadrados = suma_tiempos_cuadrados / 50;
  cout << "promedio de los tiempos: " << promedio_tiempos << "\n";
  cout << "promedio de los tiempos cuadrados: " << promedio_tiempos_cuadrados << "\n";

  ////////////////////////
  //Lectura txt PARALLEL.txt
  double suma_tiempos_parallel;
  double suma_tiempos_cuadrados_parallel;
  string linea2;
  ifstream archivo_2;
  archivo_2.open("PARALLEL.txt");
  if (archivo_2.is_open()) {
    vector<double> temporal;/*lo hago para ir guardando el tiempo y
    el tiempo al cuadrado en un vector de dos*/
    while (getline(archivo_2, linea2)) {//mientras pueda leer lineas en mi archivo
      if (isdigit(linea2[0])) {
        string auxiliar;
        for (size_t i = 0; i < linea2.length() + 1 ; i++) {
          if (i == linea2.length() || linea2[i] == '\t') {
            double mi_numero;
            mi_numero = atof(auxiliar.c_str());//coge todo el numero
            temporal.push_back(mi_numero);
            auxiliar = "";
          }else{
            auxiliar += linea2[i];
          }
        }//termina la lectura de una linea
        suma_tiempos_parallel += temporal[0];//sumando el antes  del tab
        suma_tiempos_cuadrados_parallel += temporal[1];//sumaando despues del tab
        auxiliar = {};//vacio hasta la otra linea
      }
    }
    archivo_2.close();
  }else{
    cout << "no se puede abrir el archivo\n";
  }
  cout << "///////////////////////////////\n";
  cout << "/////////PARALLEL//////////////\n";
  cout << "///////////////////////////////\n";
  cout << "suma de todos los tiempo: " << suma_tiempos_parallel << "\n";
  cout << "suma de todos los tiempos cuadrados: " << suma_tiempos_cuadrados_parallel << "\n";
  double promedio_tiemposP = suma_tiempos_parallel / 50;
  double promedio_tiemposP_cuadrados = suma_tiempos_cuadrados_parallel / 50;
  cout << "promedio de los tiempos: " << promedio_tiemposP << "\n";
  cout << "promedio de los tiempos cuadrados: " << promedio_tiemposP_cuadrados << "\n";

  cout << "///////////////////////////////\n";
  cout << "///////////SpeedUP/////////////\n";
  cout << "///////////////////////////////\n";
  double Speedup = promedio_tiempos / promedio_tiemposP;
  double Speedup_cuadrados = promedio_tiempos_cuadrados / promedio_tiemposP_cuadrados;
  cout << "Speedup: " << Speedup << "\n";
  cout << "Speedup de tiempos cuadrados: " << Speedup_cuadrados << "\n";
  cout << "///////////////////////////////\n";
  cout << "//////DESVIACION ESTANDAR//////\n";
  cout << "///////////////////////////////\n";
  double Desviacion_estandar = sqrt(Speedup_cuadrados - (Speedup * Speedup));
  cout << "Desviacion Estandar: " << Desviacion_estandar << "\n";

}
