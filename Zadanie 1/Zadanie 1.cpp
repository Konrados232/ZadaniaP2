// Konrad Nowak
// Zadanie 1

#include <iostream>

using namespace std;

//PIERWSZE ROZWIĄZANIE - klasa string
int main()
{
    //do polskich znaków
    setlocale(LC_ALL, "polish");

    int n = 3; //ilość nazwisk

    string* lastNameArray = new string[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Nazwisko : ";
        cin >> lastNameArray[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Nazwisko " << i << " : ";
        cout << lastNameArray[i] << endl;
    }

    delete[] lastNameArray;

    cout << "Program zakończył swoją pracę" << endl;
}