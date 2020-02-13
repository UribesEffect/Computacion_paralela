#ifndef __MATRIX__HPP
#define __MATRIX__HPP
class MatrixOne;
MatrixOne operator *(MatrixOne &M1, MatrixOne &M2);
void Matrix_Helper(MatrixOne &M1, MatrixOne &M2, MatrixOne &AYUDA, int Matriz1_ini_y, int Matriz1_end_y);

class MatrixOne{
private:
    int *array;
    int filas;
    int columnas;

public:
    MatrixOne(int c, int f);
    ~MatrixOne();

    int get_dimx(){ return filas;}
    int get_dimy(){ return columnas;}
    int get(int x, int y){ return array[x * filas + y];}
    void set(int x, int y, int val){array[x * filas + y] = val;}

    MatrixOne& operator =(MatrixOne &M);
    void display();
};

#endif
