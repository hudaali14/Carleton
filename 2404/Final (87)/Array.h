#include <iostream>
using namespace std;
#include <cstdlib>

/*

ARRAY CLASS
PURPOSE: Class template specialization of a 2-dimensional array of T objects
COMPLEX OR CRITICAL MEMBERS:
    - Function operator[](int): Returns object specified in parameter subscript
    - Function getElements(): Returns elements

*/

template <class T>
class Array
{
    template <class V>
    friend ostream& operator<<(ostream&, const Array<V>&);

    public:
        Array(int=0, int=0);
        ~Array();
        T* operator[](int);
        T** getElements() { return elements; }

    private:
        int columns;
        int rows;
        T**  elements;
};


template <class T>
Array<T>::Array(int r, int c)
{
    rows = r;
    columns = c;
    elements = new T*[rows];
    for(int i = 0; i < rows; i++) {
        elements[i] = new T[columns];
    }
}

template <class T>
Array<T>::~Array()
{
    for(int i = 0; i < rows; i++) {
        delete [] elements[i];
    }
    delete [] elements;
}

template <class T>
T* Array<T>::operator[](int s)
{
    if (s<0 || s >= rows){
        cerr<<"Overflow"<<endl;
        exit(1);
    }
    return elements[s];
}

template <class T>
ostream& operator<<(ostream& output, const Array<T>& arr)
{
    for (int i=0; i<arr.rows; ++i){
        for (int j=0; j<arr.columns; ++j){
            output<<arr.elements[i][j];
        }
        output << endl;
    }
    return output;
}
