// Konrad Nowak
// Zadanie 1

#include <iostream>
#include <stdio.h>   
#include <stdlib.h> 

using namespace std;

//DRUGIE ROZWI�ZANIE - w stylu C
int main()
{
    //tablica wska�nik�w na typ char*
    char** arrayOfNames = (char**)malloc(n * sizeof(char*));

    int stringLength;

    for (int i = 0; i < n; i++)
    {
        cout << "Nazwisko: ";

        char* tab = (char*)malloc(30 * sizeof(char));
        //pobranie elementu z konsoli
        fgets(tab, 30, stdin);
        //zmierzenie d�ugo�ci elementu
        stringLength = strlen(tab);

        //przypisanie odpowiedniej ilo�ci pami�ci do tablicy char
        arrayOfNames[i] = (char*)malloc((stringLength + 1) * sizeof(char*));
        //przypisanie pobranej warto�ci
        *(arrayOfNames + i) = tab;

        tab = NULL;
        if (i == (n - 1))
        {
            free(tab);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Nazwisko " << i << " : " << arrayOfNames[i] << endl;
    }

    free(arrayOfNames);

    cout << "Program zako�czy� swoj� prac�" << endl;
}