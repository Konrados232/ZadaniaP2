// Konrad Nowak
// Zadanie 2

#include <iostream>
#include <string>

using namespace std;

//standardowe struktury
struct Cheese
{
    string type;
};

struct Sandwich
{
    string name;
    int days;

    Cheese* cheese;
};

void writeSandwich(Sandwich* s)
{
    cout << "Nazwa: " << s->name << endl;
    cout << "Dni: " << s->days << endl;
    cout << "Typ sera: " << (s->cheese)->type << endl;
}

//struktury ze smart pointerami
struct Ham
{
    string type;
    int quality;
};

struct Roll
{
    string name;
    int days;

    shared_ptr<Ham> ham;
};

void writeRoll(Roll* r)
{
    cout << "Nazwa: " << r->name << endl;
    cout << "Dni: " << r->days << endl;
    cout << "Typ szynki: " << (r->ham)->type << endl;
    cout << "Jakość: " << (r->ham)->quality << endl;
}

int main()
{
    //do polskich napisów
    setlocale(LC_ALL, "polish");

    //PIERWSZE ROZWIĄZANIE - standardowe stuktury
    Sandwich* freshSandwich = new Sandwich;
    //nadanie wartości dwoma sposobami
    (*freshSandwich).name = "Kanapka z serem";
    freshSandwich->days = 2;

    Cheese* goudaCheese = new Cheese;
    goudaCheese->type = "gouda";

    Cheese cheddarCheese;
    cheddarCheese.type = "cheddar";

    //podpięcie wskaźnika
    freshSandwich->cheese = goudaCheese;

    writeSandwich(freshSandwich);

    //przepięcie wskaźnika - z Cheese* na Cheese
    freshSandwich->cheese = &cheddarCheese;

    writeSandwich(freshSandwich);

    //zwolnienie pamięci
    freshSandwich->cheese = nullptr;
    delete freshSandwich;
    delete goudaCheese;

    //DRUGIE ROZWIĄZANIE - struktury ze smart pointerami
    Roll* freshRoll = new Roll;
    freshRoll->name = "Bułka z szynką";
    freshRoll->days = 4;

    Roll* freshRollWithRaisins = new Roll;
    freshRollWithRaisins->name = "Bułka z szynką i rodzynkami";
    freshRollWithRaisins->days = 5;

    shared_ptr<Ham> firstHam(new Ham);
    firstHam->type = "świeża";
    firstHam->quality = 5;

    freshRoll->ham = firstHam;
    freshRollWithRaisins->ham = firstHam;

    writeRoll(freshRoll);
    writeRoll(freshRollWithRaisins);

    //wyczyszczenie pamięci - o firstHam nie musimy się martwić
    delete freshRoll;
    delete freshRollWithRaisins;
}