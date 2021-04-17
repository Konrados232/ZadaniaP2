// Konrad Nowak
// Zadanie 4
/* Proszę napisać program z wyrażeniem regularnym, które będzie szukać wszystkich wyrazów nie zaczynających się na wielką lub małą literę E i zawierających małą literę a. Program ma wypisywać wyniki. */

#include <iostream>
#include <string>
#include <regex>
#include <algorithm>

using namespace std;



int main()
{
    string text = "  ewa    Ewa    eaaaw edfdfd   ewwwww   eeaaawwww   ffffwwwwwwraaaafafafaEwafaf   ";

    regex mainRegex("[^a-zA-Z][E|e]{1}[a-zA-Z]*[a]{1}[a-zA-Z]*");

    smatch match;

    while (regex_search(text, match, mainRegex))
    {

        cout << match[0] << endl;
        /*
        for (int i = 0; i < match.size(); i++)
        {
            cout << match[i];
        }
        */
        cout << endl;

        text = match.suffix();
    }

}