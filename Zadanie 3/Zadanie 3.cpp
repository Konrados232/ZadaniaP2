// Konrad Nowak
// Zadanie 3
/*Proszę napisać program, który będzie pobierał adres IPv4 w postaci „kropkowo dziesiętnej” (np. 192.168.0.10) i maskę (np. 255.255.255.0) z konsoli i na tej podstawie generował adres podsieci. Program powinien też wyświetlić podany adres, maskę oraz adres podsieci w systemie dwójkowym, dziesiętnym i szesnastkowym.
Proszę zaimplementować walidację wprowadzanych danych.

* Walidację wprowadzanych danych napisać za pomocą wyrażeń regularnych.*/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool checkIfValidIP(string IPInput)
{
    /*regex cheat sheet
    | - lub
    [a-b] - przedział a-b
    [^x] - coś, co nie jest x
    {3} - dokładnie 3 razy
    \. - znak specjalny, kropka
    $ - koniec stringa
    */
    regex IPCheck("((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])\\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])$");

    if (regex_match(IPInput, IPCheck))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void changeIDToInt(string IPInput)
{

}


int main()
{
    //do polskich napisów
    setlocale(LC_ALL, "polish");

    string IPAdress;
    string mask;

    cin >> IPAdress;
    cin >> mask;

    if (checkIfValidIP(IPAdress) && checkIfValidIP(mask))
    {
        cout << "Obydwa adresy są poprawne." << endl;
    }
    else
    {
        cout << "Chociaż jeden z adresów jest niepoprawny." << endl;
    }
   





}