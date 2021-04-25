// Konrad Nowak
// Zadanie 5
/* Proszę zaimplementować klasę Dziennik, której obiekt będzie przechowywał informację o aktualnym poziomie: SEVERE (najwyższy poziom),  WARNING,  INFO,  CONFIG,  FINE,  FINER,  FINEST (najniższy poziom). Powinna być zapewniona możliwość zmiany poziomu. W zależności od aktualnego poziomu powinny być wypisywane tylko te komunikaty, które są na tym poziomie lub wyższym. Proszę uwzględnić wybór, czy komunikaty mają być wypisywane w konsoli, czy zapisywane w pliku. Odpowiednie metody (mogą nazywać się analogicznie do poziomów) mają oprócz informacji o poziomie przekazywać podaną w trakcie ich wywołania wiadomość.

Proszę w programie zaimplementować testowe wywołania. */

#include <iostream>
#include <string>
#include <fstream>
#include <locale>

using namespace std;

string upperCaseString(string word)
{
    string toReturn = word;
    for (int i = 0; i < toReturn.length(); i++)
    {
        toReturn[i] = toupper(toReturn[i]);
    }

    return toReturn;
}


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
    
    int findLevel(string lvl)
    {
        for (int i = 0; i < levelCount; i++)
        {
            if (upperCaseString(lvl) == levelList[i])
            {
                return i;
            }
        }

        return -1;
    }

    string messageNote = "Przekazana wiadomość to ";
    string errorNoteOne = "Obecny poziom to ";
    string errorNoteTwo = ", więc dany komunikat nie może być pokazany";
    
    string getLevel(int lvl)
    {
        string toReturn = "poziom to " + levelList[lvl];
        return toReturn;
    }

    void levelDisplay(int whichLevel, string message, bool writeToFile, string fileName)
    {
        if (whichLevel >= level)
        {
            if (writeToFile == false)
            {
                cout << "Wywołany " + getLevel(whichLevel) << endl;
                cout << messageNote << message << endl;
            }
            else
            {
                cout << "Zapisano wiadomość do pliku " << fileName << endl;
                //dopisywanie do pliku
                fstream noteFile;
                noteFile.open(fileName, ios_base::app);
                noteFile << "Wywołany " + getLevel(0) << endl;
                noteFile << messageNote << message << endl;
                noteFile.close();
            }

        }
        else
        {
            cout << errorNoteOne << levelList[level] << errorNoteTwo << endl;
        }
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


    void displayCurrentLevel()
    {
        cout << "Obecny " << getLevel(level)  << endl;
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

    //funkcja pozwala na mieszanie małych i dużych liter
    void setLevel(string lvl)
    {
        if (findLevel(lvl) != -1)
        {
            level = findLevel(lvl);
        }
        else
        {
            cout << "Podany poziom nie istnieje!" << endl;
        }
    }

    void increaseLevel()
    {
        if (level >= 0 && level < (levelCount - 1))
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
        if (level > 0 && level <= (levelCount - 1))
        {
            level--;
        }
        else
        {
            cout << "Nie można zmienić poziom poza zakres!" << endl;
        }
    }
    
    void severe(string message, bool writeToFile, string fileName)
    {
        levelDisplay(6, message, writeToFile, fileName);
    }

    void warning(string message, bool writeToFile, string fileName)
    {
        levelDisplay(5, message, writeToFile, fileName);
    }

    void info(string message, bool writeToFile, string fileName)
    {
        levelDisplay(4, message, writeToFile, fileName);
    }

    void config(string message, bool writeToFile, string fileName)
    {
        levelDisplay(3, message, writeToFile, fileName);
    }

    void fine(string message, bool writeToFile, string fileName)
    {
        levelDisplay(2, message, writeToFile, fileName);
    }

    void finer(string message, bool writeToFile, string fileName)
    {
        levelDisplay(1, message, writeToFile, fileName);
    }

    void finest(string message, bool writeToFile, string fileName)
    {
        levelDisplay(0, message, writeToFile, fileName);
    }

};

int main()
{
    setlocale(LC_ALL, "polish");

    Dziennik note = Dziennik(5);
    string notePath = "NoteFile.txt";

    //przykładowe działanie
    note.displayCurrentLevel();
    note.increaseLevel();
    note.increaseLevel();
    note.displayCurrentLevel();

    for (int i = 0; i < 7; i++)
    {
        note.decreaseLevel();
    }

    note.displayCurrentLevel();

    note.setLevel(3);
    note.displayCurrentLevel();

    note.setLevel("SEVERE");
    note.displayCurrentLevel();

    note.warning("Text", false, "");
    note.displayCurrentLevel();

    note.setLevel(1);
    note.severe("Level warning", false, "");
    note.displayCurrentLevel();
    
    note.setLevel("FINER");
    note.finest("Not good", true, notePath);

    note.config("Moderate", true, notePath);

    note.displayCurrentLevel();

}