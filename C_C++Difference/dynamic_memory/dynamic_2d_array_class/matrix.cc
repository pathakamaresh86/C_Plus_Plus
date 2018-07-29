#include "matrix.h"
#include <iostream>

/*Initialization List Purposes :
 i) Performing true initialization
 ii) Initializing const & reference members
 iii) Invoking base class constructor
 The order of execution of initalization list happens in the order of declaration of members inside class irrespective of order in which it is written
 */

Matrix::Matrix(const int rows, const int cols) 
    : iRows(rows), iCols(cols), matrix(0) //initialization list
{
    /* Assignment
    iRows = rows;
    iCols = cols;
    */
    matrix = new int*[rows];
    for(int i = 0 ; i < rows ; i++)
        matrix[i] = new int[cols];
}//allocate 
/*
    Default Compiler Provided Methods :
    i) Default constructor (no arguments constructor i.e which can be invoked without any arguments). Compiler provides this iff user has nor provided any constructor.
    ii) Default Copy Constructor : Copy constructor is a method which gets invoked implicitly on creation of new object from existing object.
    Possible scenarios :
        - Matrix m3(m1) : explicitly creating new object from existing
        - Add(m1) : passing object as an argument to a function using pass by value method
        - return m1 : returning object from method using pass by value

    Compiler Provided Copy Constructor Performs Shallow copy.
    When to write user-defined Copy Constructor ?
    - when object refers to some resources which are dynamically allocated or referring to some other memory areas.
 */
Matrix::Matrix(const Matrix& existingMatrix)
    : iRows(existingMatrix.iRows), iCols(existingMatrix.iCols)
{
    //this : constant reference to calling object
    this->matrix = new int*[iRows];
    for(int i = 0 ; i < iRows ; i++)
        this->matrix[i] = new int[iCols];

    for(int i = 0 ; i < iRows ; i++)
        for(int j = 0 ; j < iCols ; j++)
            this->matrix[i][j] = existingMatrix.matrix[i][j];
}//copy constructor
Matrix::~Matrix()
{
    if(matrix)
    {
        for(int i = 0 ; i < iRows  ; i++)
            delete[] matrix[i];

        delete[] matrix;
    }
}//de-allocate
    
//Please implement all the below methods
void Matrix::Accept(){}
void Matrix::Display(){}
Matrix Matrix::Add(const Matrix &m2){}
Matrix Matrix::Sub(const Matrix &m2){}
Matrix Matrix::Multiply(const Matrix &m2){}
