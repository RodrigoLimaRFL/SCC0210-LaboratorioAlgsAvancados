#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// Mapa de caracteres e seus reflexos
map<char, char> reflexo = {
    {'A','A'}, {'E','3'}, {'H','H'}, {'I','I'}, {'J','L'}, {'L','J'},
    {'M','M'}, {'O','O'}, {'S','2'}, {'T','T'}, {'U','U'}, {'V','V'},
    {'W','W'}, {'X','X'}, {'Y','Y'}, {'Z','5'}, {'1','1'}, {'2','S'},
    {'3','E'}, {'5','Z'}, {'8','8'}
};

// Verifica se é palíndromo regular
bool ehPalindromo(const string &s) {
    int n = s.size();
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n - 1 - i])
            return false;
    }
    return true;
}

// Verifica se é string refletida
bool ehRefletida(const string &s) {
    int n = s.size();
    for (int i = 0; i <= n/2; i++) {
        char c1 = s[i];
        char c2 = s[n - 1 - i];
        if (reflexo.find(c1) == reflexo.end() || reflexo[c1] != c2)
            return false;
    }
    return true;
}

int main() {
    string linha;
    while (getline(cin, linha)) {
        bool palindromo = ehPalindromo(linha);
        bool refletida = ehRefletida(linha);

        cout << linha << " -- ";

        if (palindromo && refletida) {
            cout << "is a mirrored palindrome.";
        } else if (palindromo) {
            cout << "is a regular palindrome.";
        } else if (refletida) {
            cout << "is a mirrored string.";
        } else {
            cout << "is not a palindrome.";
        }

        cout << endl << endl;
    }

    return 0;
}
