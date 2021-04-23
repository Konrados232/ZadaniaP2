// Konrad Nowak
// Zadanie 5
/* Proszę zaimplementować klasę Dziennik, której obiekt będzie przechowywał informację o aktualnym poziomie: SEVERE (najwyższy poziom),  WARNING,  INFO,  CONFIG,  FINE,  FINER,  FINEST (najniższy poziom). Powinna być zapewniona możliwość zmiany poziomu. W zależności od aktualnego poziomu powinny być wypisywane tylko te komunikaty, które są na tym poziomie lub wyższym. Proszę uwzględnić wybór, czy komunikaty mają być wypisywane w konsoli, czy zapisywane w pliku. Odpowiednie metody (mogą nazywać się analogicznie do poziomów) mają oprócz informacji o poziomie przekazywać podaną w trakcie ich wywołania wiadomość.

Proszę w programie zaimplementować testowe wywołania. */

#include <iostream>
#include <string>

using namespace std;

class Dziennik
{
private:
    static const int levelCount = 7;
    string levelList[levelCount];

    string levelName;
    int level;

    void makeLevelList()
    {
        levelList[0] = "FINEST";
        levelList[1] = "FINER";
        levelList[2] = "FINE";
        levelList[3] = "CONFIG";
        levelList[4] = "INFO";
        levelList[5] = "WARNING";
        levelList[6] = "SEVERE";
    }

    
public:

    Dziennik()
    {
        makeLevelList();
        level = 0;
        levelName = levelList[0];
    }

    Dziennik(int lvl)
    {
        makeLevelList();
        level = lvl;
        levelName = levelList[level];
    }

    ~Dziennik()
    {
        delete levelList;
    }


    void displayLevel()
    {
        cout << "Current level is " << levelList[level] << endl;
    }
    
    void setLevel(int lvl)
    {
        if (lvl >= 0 && lvl <= levelCount)
        {
            level = lvl;
        }
        else
        {
            cout << "Nie można zmienić poziom poza zakres!" << endl;
        }
    }

    void increaseLevel()
    {
        if (level >= 0 && level < levelCount)
        {
            level++;
        }
        else
        {
            cout << "Nie można zmienić poziom poza zakres!" << endl;
        }
    }

    void decreaseLevel()
    {
        if (level > 0 && level <= levelCount)
        {
            level--;
        }
        else
        {
            cout << "Nie można zmienić poziom poza zakres!" << endl;
        }
    }


};

int main()
{

    Dziennik note = Dziennik(5);
    note.XD();

}
