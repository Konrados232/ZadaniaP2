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
            data[i] = new float[numOfCols];
        }

        resetMatrix();
    }

    Matrix2D(float number)
    {
        data = new float* [numOfRows];

        for (int i = 0; i < numOfRows; i++)
        {
        
            data[i] = new float[numOfCols];
        }

        fillMatrix(number);
    }

    Matrix2D(float** newData)
    {
        data = new float* [numOfRows];

        for (int i = 0; i < numOfRows; i++)
        {
            data[i] = new float[numOfCols];
        }


        for (int i = 0; i < numOfRows; i++)
        {
            for (int j = 0; j < numOfCols; j++)
            {
                data[i][j] = newData[i][j];
            }
        }
    }

    Matrix2D(float one, float two, float three, float four, float five, float six, float seven, float eight, float nine)
    {
        data = new float* [numOfRows];

        for (int i = 0; i < numOfRows; i++)
        {
            data[i] = new float[numOfCols];
        }

        data[0][0] = one;
        data[0][1] = two;
        data[0][2] = three;
        data[1][0] = four;
        data[1][1] = five;
        data[1][2] = six;
        data[2][0] = seven;
        data[2][1] = eight;
        data[2][2] = nine;
    }

    Matrix2D(const Matrix2D& m)
    {
        data = new float* [numOfRows];

        for (int i = 0; i < numOfRows; i++)
        {
            data[i] = new float[numOfCols];
        }


        for (int i = 0; i < numOfRows; i++)
        {
            for (int j = 0; j < numOfCols; j++)
            {
                data[i][j] = m.data[i][j];
            }
        }
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


    float getNumOfRows() const
    {
        return numOfRows;
    }

    float getNumOfCols() const
    {
        return numOfCols;
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

    //obliczanie wyznacznika
    float getDeterminant() const
    {
        float det = data[0][2] * data[1][1] * data[2][0] + data[0][0] * data[1][2] * data[2][1] + data[0][1] * data[1][0] * data[2][2];
        return det;
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
        return Matrix2D(this->data[0][0] + m.data[0][0], this->data[0][1] + m.data[0][1], this->data[0][2] + m.data[0][2],
            this->data[1][0] + m.data[1][0], this->data[1][1] + m.data[1][1], this->data[1][2] + m.data[1][2],
            this->data[2][0] + m.data[2][0], this->data[2][1] + m.data[2][1], this->data[2][2] + m.data[2][2]);
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
        return Matrix2D(this->data[0][0] - m.data[0][0], this->data[0][1] - m.data[0][1], this->data[0][2] - m.data[0][2],
            this->data[1][0] - m.data[1][0], this->data[1][1] - m.data[1][1], this->data[1][2] - m.data[1][2],
            this->data[2][0] - m.data[2][0], this->data[2][1] - m.data[2][1], this->data[2][2] - m.data[2][2]);
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

    //preinkrementacja

    Matrix2D& operator ++()
    {
        for (int i = 0; i < numOfRows; i++)
        {
            for (int j = 0; j < numOfCols; j++)
            {
                this->data[i][j] += 1;
            }
        }

        return *this;
    }

    Matrix2D& operator --()
    {
        for (int i = 0; i < numOfRows; i++)
        {
            for (int j = 0; j < numOfCols; j++)
            {
                this->data[i][j] -= 1;
            }
        }

        return *this;
    }

    //postinkrementacja

    Matrix2D operator++(int)
    {
        Matrix2D temp = *this;

        for (int i = 0; i < numOfRows; i++)
        {
            for (int j = 0; j < numOfCols; j++)
            {
                this->data[i][j] += 1;
            }
        }

        return temp;
    }

    Matrix2D operator--(int)
    {
        Matrix2D temp = *this;

        for (int i = 0; i < numOfRows; i++)
        {
            for (int j = 0; j < numOfCols; j++)
            {
                this->data[i][j] -= 1;
            }
        }

        return temp;
    }


    Matrix2D operator *(const Matrix2D& m)
    {
        float finalResult[3][3] = { 0 };

        for (int i = 0; i < numOfRows; i++)
        {
            for (int j = 0; j < numOfCols; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    finalResult[i][j] += this->data[i][k] * m.data[k][j];
                }
            }
        }

        return Matrix2D(finalResult[0][0], finalResult[0][1], finalResult[0][2],
            finalResult[1][0], finalResult[1][1], finalResult[1][2],
            finalResult[2][0], finalResult[2][1], finalResult[2][2]);
    }

    Matrix2D& operator *=(const Matrix2D& m)
    {
        this->resetMatrix();

        for (int i = 0; i < numOfRows; i++)
        {
            for (int j = 0; j < numOfCols; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    this->data[i][j] += this->data[i][k] * m.data[k][j];
                }
            }
        }
        
        return *this;
    }

    friend istream& operator >>(istream& input, Matrix2D& m);
    friend ostream& operator <<(ostream& output, const Matrix2D& m);
    

    bool operator <(const Matrix2D& m) const
    {
        int first = this->getDeterminant();
        int second = m.getDeterminant();

        if (first < second)
        {
            return true
        }
        else
        {
            return false;
        }
    }

    bool operator >(const Matrix2D& m) const
    {
        int first = this->getDeterminant();
        int second = m.getDeterminant();

        if (first > second)
        {
            return true
        }
        else
        {
            return false;
        }
    }
};


//mnożenie przez liczbę całkowitą

Matrix2D operator *(const Matrix2D& m, const int& a)
{
    return Matrix2D(m.getNumberAt(0,0) * a, m.getNumberAt(0, 1) * a, m.getNumberAt(0, 2) * a,
        m.getNumberAt(1, 0) * a, m.getNumberAt(1, 1) * a, m.getNumberAt(1, 2) * a, 
        m.getNumberAt(2, 0) * a, m.getNumberAt(2, 1) * a, m.getNumberAt(2, 2) * a);
}

Matrix2D operator *(const int& a, const Matrix2D& m)
{
    return Matrix2D(m.getNumberAt(0, 0) * a, m.getNumberAt(0, 1) * a, m.getNumberAt(0, 2) * a,
        m.getNumberAt(1, 0) * a, m.getNumberAt(1, 1) * a, m.getNumberAt(1, 2) * a,
        m.getNumberAt(2, 0) * a, m.getNumberAt(2, 1) * a, m.getNumberAt(2, 2) * a);
}


Matrix2D& operator *=(Matrix2D& m, const int& a)
{
    for (int i = 0; i < m.getNumOfRows(); i++)
    {
        for (int j = 0; j < m.getNumOfCols(); j++)
        {
            m.setNumberAt(i, j, m.getNumberAt(i, j) * a);
        }
    }
    return m;
}

ostream& operator <<(ostream& output, const Matrix2D& m)
{
    output << m.data[0][0] << " " << m.data[0][1] << " " << m.data[0][2] << endl
        << m.data[1][0] << " " << m.data[1][1] << " " << m.data[1][2] << endl
        << m.data[2][0] << " " << m.data[2][1] << " " << m.data[2][2] << endl;

    return output;
}

istream& operator >> (istream& input, Matrix2D& m)
{
    input >> m.data[0][0] >> m.data[0][1] >> m.data[0][2]
        >> m.data[1][0] >> m.data[1][1] >> m.data[1][2]
        >> m.data[2][0] >> m.data[2][1] >> m.data[2][2];

    return input;
}

int main()
{
    setlocale(LC_ALL, "polish");

    srand((unsigned)time(0));

    float** tempData = new float* [3];
    for (int i = 0; i < 3; i++)
    {
        tempData[i] = new float[3];
    }

    //losowo generowane liczby
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tempData[i][j] = 1 + (rand() % 20);
        }
    }

    

    Matrix2D* base = new Matrix2D();
    Matrix2D* base2 = new Matrix2D(4);
    Matrix2D* base3 = new Matrix2D(tempData);
    Matrix2D* base4 = new Matrix2D(8);

    cout << *base;
    cout << *base2;
    cout << *base3;
    cout << *base4;

    Matrix2D* main = new Matrix2D();

    *main = *base2;
    cout << *main;

    *main += *base3;
    cout << *main;

    *main -= *base4;
    cout << *main;

    *main *= *base;
    cout << *main;

    (*main)++;
    cout << *main;
    
    (*main)--;
    cout << *main;

    *main = (*main + *base2);
    cout << *main;

    *main = (*main - *base3);
    cout << *main;

    *main = (*main * *base2);
    cout << *main;

    *main = 3 * *main;
    cout << *main;

    *main = *main + 10;
    cout << *main;

    

    //Matrix2D main2;

    //cin >> main2;

    //cout << main2;






    delete base;
    delete base2;
    delete base3;
    delete base4;
    delete main;


    for (int i = 0; i < 3; i++)
    {
        delete[] tempData[i];
    }

    delete[] tempData;



    int ll;
}