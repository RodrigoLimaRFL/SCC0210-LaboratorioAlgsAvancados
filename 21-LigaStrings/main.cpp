/*
 * Nome: Rodrigo de Freitas Lima
 * NUSP: 12547510
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string bestMoves(string& s)
{
    int n = s.size();
    string result = s;

    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0) // menor
        {
            if(result[i] == 'a')
                result[i] = 'b';
            else
                result[i] = 'a';
        }
        else // maior
        {
            if(result[i] == 'z')
                result[i] = 'y';
            else
                result[i] = 'z';
        }
    }

    return result;
}

int main() {
    int n;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string s;
        
        cin >> s;

        string result = bestMoves(s);

        cout << result << endl;
    }

    return 0;
}