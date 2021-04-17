// Konrad Nowak
// Zadanie 4
/* Proszę napisać program z wyrażeniem regularnym, które będzie szukać wszystkich wyrazów nie zaczynających się na wielką lub małą literę E i zawierających małą literę a. Program ma wypisywać wyniki. */

#include <iostream>
#include <string>
#include <regex>
#include <algorithm>

using namespace std;

void displayFoundExpression(smatch match)
{
    string expression = match.str(0);

    expression = expression.substr(1, expression.size() - 1);

    cout << expression << endl;
}

void searchForExpression(string text, regex mainRegex)
{
    smatch match;
    while (regex_search(text, match, mainRegex))
    {
        displayFoundExpression(match);

        text = match.suffix();
    }
}


int main()
{
    setlocale(LC_ALL, "polish");

    //wyrażenie regularne znajduje wyraz, który poprzedza np. spacja lub przecinek, ale to zostaje uwzględnione w wypisywaniu
    regex mainRegex("[^a-zA-Z](([a-df-zA-DF-Z][a-zA-Z]*[a]{1}[a-zA-Z]*)|[a]{1})");

    //przykładowy tekst
    //string text = "  ewa    Ewa    eaaaw edfdfd   ewwwww  ,a   a.. eeaaawwww   ,ffffwwwwwwraaaafafafaEwafaf Falafel, woda Ekologia eko";

    int howMany = 3;
    string text;

    cout << "Wprowadź " << howMany << " wyrażenia: " << endl;

    for (int i = 0; i < howMany; i++)
    {
        getline(cin, text);
        
        searchForExpression(text, mainRegex);
    }
}