// Konrad Nowak
// Zadanie 3
/*Proszę napisać program, który będzie pobierał adres IPv4 w postaci „kropkowo dziesiętnej” (np. 192.168.0.10) i maskę (np. 255.255.255.0) z konsoli i na tej podstawie generował adres podsieci. Program powinien też wyświetlić podany adres, maskę oraz adres podsieci w systemie dwójkowym, dziesiętnym i szesnastkowym.
Proszę zaimplementować walidację wprowadzanych danych.

* Walidację wprowadzanych danych napisać za pomocą wyrażeń regularnych.*/

#include <iostream>
#include <string>
#include <regex>
#include <bitset>

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

void changeIDToInt(string IPInput, int* tab)
{
    string tempString;

    int j = 0;
    for (int i = 0; i < 4; i++)
    {
        tempString = "";
        while (j <= IPInput.length() && IPInput[j] != '.')
        {
            tempString += IPInput[j];
            j++;
        }
        j++;
        
        //zamiana stringa na inta
        *(tab + i) = stoi(tempString);
    }
}

void generateSubnet(int* IPArray, int* maskArray, int* subnetMask)
{
    for (int i = 0; i < 4; i++)
    {
        bitset<8> IPBits(*(IPArray + i));
        bitset<8> maskBits(*(maskArray + i));

        bitset<8> subnetBits = (IPBits & maskBits);

        *(subnetMask + i) = subnetBits.to_ulong();
    }
}

int main()
{
    //do polskich napisów
    setlocale(LC_ALL, "polish");

    string IPAdress = "192.168.1.145";
    string mask = "255.255.255.128";

    //cin >> IPAdress;
    //cin >> mask;

    if (checkIfValidIP(IPAdress) && checkIfValidIP(mask))
    {
        cout << "Obydwa adresy są poprawne." << endl;
    }
    else
    {
        cout << "Chociaż jeden z adresów jest niepoprawny." << endl;
    }
    
    //wczytanie liczb z adresu
    int IPArray[4];
    int maskArray[4];

    changeIDToInt(IPAdress, IPArray);
    changeIDToInt(mask, maskArray);

    int subnetMaskArray[4];

    generateSubnet(IPArray, maskArray, subnetMaskArray);

    //display

}