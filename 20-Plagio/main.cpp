/*
 * Nome: Rodrigo de Freitas Lima
 * NUSP: 12547510
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> tabelaKMP(string& substringToSearch) {
    int m = substringToSearch.size();
    vector<int> tabela(m + 1);
    tabela[0] = -1;
    
    int pos = 1;
    int cnd = 0;

    while(pos < m) {
        if(substringToSearch[pos] == substringToSearch[cnd]) {
            tabela[pos] = tabela[cnd];
        } 
        else {
            tabela[pos] = cnd;
            while(cnd >= 0 && substringToSearch[pos] != substringToSearch[cnd]) {
                cnd = tabela[cnd];
            }
        }
        pos++;
        cnd++;
    }

    tabela[pos] = cnd;

    return tabela;
}

int numSubstrings(string& frase, string& substringToSearch, vector<int>& indices) {
    // Algoritmo kmp
    int count = 0;
    int n = frase.size();
    int m = substringToSearch.size();
    int numIndices = indices.size();

    int ptrSubstring = 0;
    int ptrFrase = 0;

    vector<int> tabela = tabelaKMP(substringToSearch);

    while(ptrFrase < n) {
        if(substringToSearch[ptrSubstring] == frase[ptrFrase]) {
            ptrSubstring++;
            ptrFrase++;

            if(ptrSubstring == m) { // Achou substring
                if(count < numIndices) {
                    indices[count] = ptrFrase - ptrSubstring;
                }
                count++;
                ptrSubstring = tabela[ptrSubstring];
            }
        }
        else {
            ptrSubstring = tabela[ptrSubstring];
            if(ptrSubstring < 0) {
                ptrFrase++;
                ptrSubstring++;
            }
        }
    }

    return count;
}

int main()
{
    string frase;
    string substringToSearch;

    getline(cin, frase);
    getline(cin, substringToSearch);

    vector<int> indices(100);

    int count = numSubstrings(frase, substringToSearch, indices);

    cout << count << endl;

    if(count < 100) {
        for(int i = 0; i < count; i++) {
            cout << indices[i] << endl;
        }
    }

    return 0;
}