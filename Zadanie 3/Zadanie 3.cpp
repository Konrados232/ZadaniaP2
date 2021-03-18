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

void displayIP(int IPArray[4], int maskArray[4], int subnetMask[4])
{
    cout << "W systemie dwójkowym: " << endl;
    cout << "Adres IPv4: " << (bitset<8>)IPArray[0] << " " << (bitset<8>)IPArray[1] << " " << (bitset<8>)IPArray[2] << " " << (bitset<8>)IPArray[3] << endl;
    cout << "Maska : " << (bitset<8>)maskArray[0] << " " << (bitset<8>)maskArray[1] << " " << (bitset<8>)maskArray[2] << " " << (bitset<8>)maskArray[3] << endl;
    cout << "Maska podsieci: " << (bitset<8>)subnetMask[0] << " " << (bitset<8>)subnetMask[1] << " " << (bitset<8>)subnetMask[2] << " " << (bitset<8>)subnetMask[3] << endl;

    cout << "W systemie dziesiętnym: " << endl;
    cout << "Adres IPv4: " << IPArray[0] << "." << IPArray[1] << "." << IPArray[2] << "." << IPArray[3] << endl;
    cout << "Maska : " << maskArray[0] << "." << maskArray[1] << "." << maskArray[2] << "." << maskArray[3] << endl;
    cout << "Maska podsieci: " << subnetMask[0] << "." << subnetMask[1] << "." << subnetMask[2] << "." << subnetMask[3] << endl;

    //użycie funkcji printf, by wyświetlić w systemie szesnastkowym
    printf("W systemie szesnastkowym: \n");
    printf("Adres IPv4: %x %x %x %x \n", IPArray[0], IPArray[1], IPArray[2], IPArray[3]);
    printf("Maska: %x %x %x %x \n", maskArray[0], maskArray[1], maskArray[2], maskArray[3]);
    printf("Maska podsieci: %x %x %x %x \n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);
}

int main()
{
    //do polskich napisów
    setlocale(LC_ALL, "polish");

    string IPAdress;
    string mask;

    //przykładowe inputy: 192.168.1.145 i 255.255.255.128  <- daje wynik 192.168.1.128

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
    
    //wczytanie liczb z adresu
    int IPArray[4];
    int maskArray[4];

    changeIDToInt(IPAdress, IPArray);
    changeIDToInt(mask, maskArray);

    int subnetMaskArray[4];
    generateSubnet(IPArray, maskArray, subnetMaskArray);

    displayIP(IPArray, maskArray, subnetMaskArray);

}