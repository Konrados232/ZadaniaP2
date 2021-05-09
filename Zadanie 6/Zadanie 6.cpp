//Konrad Nowak

/*
Proszę, na podstawie slajdów, zaimplementować kompletny omawiany  w trakcie zajęć program.

Proszę napisać testowe wywołania weryfikujące omawiane aspekty programowania obiektowego.
*/


#include <iostream>
#include <string>

using namespace std;

class Statek;
class Kapitan;

class Kapitan
{
private:
    string imie;
    string nazwisko;
    int numer;
    bool cos;

    friend ostream& operator << (ostream& strumien, const Kapitan& statek);

public:

    Kapitan();
    Kapitan(string i, string n, int nu, bool c);
    ~Kapitan();

    void set_imie(string i);
    string get_imie() const;

    void set_nazwisko(string n);
    string get_nazwisko() const;

    void set_numer(int n);
    int get_numer() const;

    void set_cos(bool c);
    bool get_cos() const;
};

Kapitan::Kapitan()
{
    imie = "";
    nazwisko = "";
    numer = 0;
    cos = false;
}

Kapitan::Kapitan(string i, string n, int nu, bool c)
{
    imie = i;
    nazwisko = n;
    numer = nu;
    cos = c;
}

Kapitan::~Kapitan()
{

}

void Kapitan::set_imie(string i)
{
    imie = i;
}

string Kapitan::get_imie() const
{
    return imie;
}

void Kapitan::set_nazwisko(string n)
{
    nazwisko = n;
}

string Kapitan::get_nazwisko() const
{
    return nazwisko;
}

void Kapitan::set_numer(int n)
{
    numer = n;
}

int Kapitan::get_numer() const
{
    return numer;
}

void Kapitan::set_cos(bool c)
{
    cos = c;
}

bool Kapitan::get_cos() const
{
    return cos;
}

ostream& operator << (ostream& strumien, const Kapitan& kapitan)
{
    strumien << "Imie: " << kapitan.imie << ", nazwisko " << kapitan.nazwisko << ", numer " << kapitan.numer << ", cos " << kapitan.cos << " ";
    return strumien;
}

class Statek
{
private:
    Kapitan kapitan;
    string nazwa;

    int zaloga;
    mutable int liczba_wywolan_get_zaloga = 0;
    int* tab_i;

    int id;
    static int obecne_id;
    void set_id();

    friend ostream& operator<<(ostream& strumien, const Statek& statek);

public:
    Statek();
    Statek(Kapitan k, string n, int z);
    Statek(const Statek& inny);
    ~Statek();

    int get_zaloga() const;
    void set_zaloga(int z);

    const int* get_tab_i() const;
    void set_tab_i();

    void werbunek(int liczba);

    static int static_get_id();
    int get_id();
};


Statek::Statek()
{
    kapitan = Kapitan("John", "Sheridan", 10, false);
    nazwa = "White Star";
    zaloga = 25;
    tab_i = new int[3];
    set_tab_i();
}

Statek::Statek(Kapitan k, string n, int z)
{
    kapitan = k;
    nazwa = n;
    zaloga = z;
    tab_i = new int[3];
    set_tab_i();
}

Statek::Statek(const Statek& inny)
{
    kapitan = inny.kapitan;
    nazwa = inny.nazwa;
    zaloga = inny.zaloga;
    liczba_wywolan_get_zaloga = 0; //nowy obiekt, więc od nowa ilość wywołania

    //pamięć dynamiczna
    tab_i = new int[3];

    for (int i = 0; i < 3; i++)
    {
        tab_i[i] = inny.tab_i[i];
    }
}

Statek::~Statek()
{
    //zwolnienie pamięci dynamicznej
    delete tab_i;
}

int Statek::get_zaloga() const
{
    ++liczba_wywolan_get_zaloga;
    return zaloga;
}

void Statek::set_zaloga(int z)
{
    zaloga = z;
}

const int* Statek::get_tab_i() const
{
    return tab_i;
}

void Statek::set_tab_i()
{
    for (int i = 0; i < 3; i++)
    {
        tab_i[i] = 0;
    }
}

void Statek::werbunek(int liczba)
{
    zaloga += liczba;
}


void Statek::set_id()
{
    id = Statek::obecne_id++;
}

int Statek::static_get_id()
{
    return obecne_id;
}

int Statek::get_id()
{
    return id;
}

ostream& operator << (ostream & strumien, const Statek & statek)
{
    strumien << "Kapitan :" << statek.kapitan << ", nazwa: " << statek.nazwa << ", liczba zalogi" << statek.get_zaloga() << "Identyfikator : " << statek.id;
    return strumien;
}





int main()
{
    std::cout << "Hello World!\n";
}