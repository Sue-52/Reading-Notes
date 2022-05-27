#include <iostream>
#include <string>
#include <cctype>

int isvowels(char);

int main_seventh()
{
    using namespace std;

    string word;
    int i = 0;
    int j = 0;
    int k = 0;

    cout << "Enter words (q to quit):\n";

    while (cin >> word && word != "q")
    {
        if (isalpha(word[0]))
        {
            if (isvowels(word[0]))
                i++;
            else
                j++;
        }
        else
            k++;
    }

    cout << i << " words beginning with vowels\n";
    cout << j << " words beginning with consonants\n";
    cout << k << " others";

    return 0;
}

int isvowels(char a)
{
    a = tolower(a);
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
        return 1;
    else
        return 0;
}