//Konrad Nowak

/*
Proszę stworzyć w jednym pliku klasę Macierz2D, która będzie mogła przechowywać macierze kwadratowe o rozmiarach 3 na 3 z elementami typu float (float** m_dane). Ponadto w klasie należy:
Stworzyć konstruktory:
- Bez parametrów.
- Z jednym parametrem typu float.
- Przyjmujący jako argument tablicę dwuwymiarową elementów typu float.
- Przyjmujący jako argument listę inicjującą.
Przeciążyć operatory:
- przypisania =
- dodawania +
- dodawania z przypisaniem +=
- odejmowania -
- odejmowania z przypisaniem -=
- Post i pre zarówno inkrementacji jak i dekrementacji ++ --
- mnożenia * (przez liczbę całkowitą)
- mnożenia z przypisaniem *= (przez liczbę całkowitą)
- mnożenia * (macierzy)
- mnożenia z przypisaniem *= (macierzy)
- operatory strumieniowego wejścia i wyjścia >> << (wyświetlanie powinno być sformatowane)
Dodać metody realizujące:
- Ustawianie i zwracanie konkretnych elementów macierzy.
- Stworzenie macierzy jednostkowej.
- Transponowanie macierzy.

W przypadku tych operatorów, które mogą być przeciążone zarówno poza jak i w klasie mogą Państwo wybrać dowolnie.
Proszę również zaimplementować w main tablicę przechowującą trzy różne macierze typu Macierz2D. Proszę posortować tę tablicę za pomocą sortowania z biblioteki standardowej.
W main proszę umieścić przykładowe mnożenie macierzy łącznie z wypisaniem operandów i wyniku.
Należy zadbać o poprawną obsługę obiektów klasy Macierz2D.

*/

#include <iostream>
#include <string>

using namespace std;

class Matrix2D
{
private:
    const int numOfRows = 3;
    const int numOfCols = 3;
    float** data;



public:

    Matrix2D()
    {
        data = new float* [numOfRows];

        for (int i = 0; i < numOfRows; i++)
        {
            cout << "XD " << endl;
            data[i] = new float[numOfCols];
        }

        resetMatrix();
    }

    Matrix2D(float number)
    {
        data = new float* [numOfRows];

        for (int i = 0; i < numOfRows; i++)
        {
            cout << "XD " << endl;
            data[i] = new float[numOfCols];
        }

        fillMatrix(number);

    }




    ~Matrix2D()
    {
        for (int i = 0; i < numOfRows; i++)
        {
            delete[] data[i];
        }

        delete[] data;
    }


    //wypełnia całą macierz zerami
    void resetMatrix()
    {
        fillMatrix(0);
    }

    //wypełnia całą macierz jednym numerem
    void fillMatrix(float number)
    {
        for (int i = 0; i < numOfRows; i++)
        {
            for (int j = 0; j < numOfCols; j++)
            {
                data[i][j] = number;
            }
        }
    }


    void displayMatrix()
    {
        for (int i = 0; i < numOfRows; i++)
        {
            for (int j = 0; j < numOfCols; j++)
            {
                cout << data[i][j] << " ";
            }

            cout << endl;
        }
    }

    void swapElementsAt(int firstRow, int firstCol, int secondRow, int secondCol)
    {
        float temp = this->data[firstRow][firstCol];
        this->data[firstRow][firstCol] = this->data[secondRow][secondCol];
        this->data[secondRow][secondCol] = temp;
    }


    //ustawianie i zwracanie konkretnych elementów macierzy
    void setNumberAt(int whichRow, int whichCol, float number)
    {
        this->data[whichRow][whichCol] = number;
    }

    float getNumberAt(int whichRow, int whichCol) const
    {
        return this->data[whichRow][whichCol];
    }

    //tworzenie macierzy jednostkowej
    void setMatrixAsIdentityMatrix()
    {
        resetMatrix();

        this->data[0][0] = 1;
        this->data[1][1] = 1;
        this->data[2][2] = 1;
    }

    //transponowanie macierzy
    void transponseMatrix()
    {
        //w macierzy 3x3 wystarczą trzy zamiany, gdyż elementy na diagonali pozostaną takie same
        swapElementsAt(0, 1, 1, 0);
        swapElementsAt(2, 0, 0, 2);
        swapElementsAt(2, 1, 1, 2);
    }


    //przeciążenie operatorów

    Matrix2D& operator =(const Matrix2D m)
    {
        for (int i = 0; i < numOfRows; i++)
        {
            for(int j =0 ; j < numOfCols; j++)
            {
                this->data[i][j] = m.data[i][j];
            }
        }
        return *this;
    }

    Matrix2D operator +(const Matrix2D m) const
    {

    }

    Matrix2D& operator +=(const Matrix2D& m)
    {
        for (int i = 0; i < numOfRows; i++)
        {
            for (int j = 0; j < numOfCols; j++)
            {
                this->data[i][j] += m.data[i][j];
            }
        }
        return *this;
    }

    Matrix2D operator -(const Matrix2D& m)
    {

    }

    Matrix2D& operator -=(const Matrix2D& m)
    {
        for (int i = 0; i < numOfRows; i++)
        {
            for (int j = 0; j < numOfCols; j++)
            {
                this->data[i][j] -= m.data[i][j];
            }
        }
        return *this;
    }

    Matrix2D& operator ++()
    {

    }

    Matrix2D& operator --()
    {

    }

    Matrix2D& operator *(const Matrix2D& m) const
    {

    }

    Matrix2D& operator *=(const Matrix2D& m) const
    {

    }















};





int main()
{
    Matrix2D* base = new Matrix2D();

    base->displayMatrix();



    delete base;




    cout << "Hello World!\n";
}