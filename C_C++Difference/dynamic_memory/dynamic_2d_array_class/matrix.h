#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
    int **matrix;
    int iRows;
    int iCols;
    public:
    //manager methods : methods which manage creation and destruction of objects
    Matrix(const int rows, const int cols);//allocate 
    Matrix(const Matrix& existingMatrix);//copy constructor
    ~Matrix();//de-allocate
    
    //mutator methods - which change the state
    void Accept();
    //Accessor methods - which return the state
    void Display();
    //General Methods - all other methods
    Matrix Add(const Matrix &m2);
    Matrix Sub(const Matrix &m2);
    Matrix Multiply(const Matrix &m2);
};
#endif
