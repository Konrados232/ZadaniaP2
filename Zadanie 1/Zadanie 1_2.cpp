// Konrad Nowak
// Zadanie 1

#include <iostream>
#include <stdio.h>   
#include <stdlib.h> 

using namespace std;

//DRUGIE ROZWI¥ZANIE - w stylu C
int main()
{
    //tablica wskaŸników na typ char*
    char** arrayOfNames = (char**)malloc(n * sizeof(char*));

    int stringLength;

    for (int i = 0; i < n; i++)
    {
        cout << "Nazwisko: ";

        char* tab = (char*)malloc(30 * sizeof(char));
        //pobranie elementu z konsoli
        fgets(tab, 30, stdin);
        //zmierzenie d³ugoœci elementu
        stringLength = strlen(tab);

        //przypisanie odpowiedniej iloœci pamiêci do tablicy char
        arrayOfNames[i] = (char*)malloc((stringLength + 1) * sizeof(char*));
        //przypisanie pobranej wartoœci
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

    cout << "Program zakoñczy³ swoj¹ pracê" << endl;
}