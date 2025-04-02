/*
 * Nome: Rodrigo de Freitas Lima
 * NUSP: 12547510
*/

#include <iostream>
#include <vector>

using namespace std;

bool verificarPosicao(int x, int y, vector<int>& tabuleiroColunas)
{
    for(int i = 0; i < y; i++)
    {
        if(tabuleiroColunas[i] == x || abs(tabuleiroColunas[i] - x) == abs(i - y))
        {
            return false; // se a rainha já está na mesma coluna ou na mesma diagonal
        }
    }

    return true;
}

void resolverOitoRainhas(vector<int> &tabuleiroColunas, int coluna, int colunaFixa, int linhaFixa, vector<vector<int>> &solucoes)
{
    if(coluna == 8)
    {
        // se todas as rainhas foram colocadas, salva a solução
        solucoes.push_back(tabuleiroColunas);
        return;
    }

    if(coluna == colunaFixa)
    {
        if(verificarPosicao(linhaFixa, coluna, tabuleiroColunas))
        {
            tabuleiroColunas[coluna] = linhaFixa; // marca a linha ocupada pela rainha
            resolverOitoRainhas(tabuleiroColunas, coluna + 1, colunaFixa, linhaFixa, solucoes);
        }
    }
    else
    {
        // tenta colocar a rainha em cada linha da coluna
        for(int i = 0; i < 8; i++)
        {
            if(verificarPosicao(i, coluna, tabuleiroColunas))
            {
                tabuleiroColunas[coluna] = i; // marca a linha ocupada pela rainha
                resolverOitoRainhas(tabuleiroColunas, coluna + 1, colunaFixa, linhaFixa, solucoes);
                tabuleiroColunas[coluna] = -1; // desmarca a linha ocupada pela rainha
            }
        }
    }
}

int main()
{
    int n; // numero de casos
    vector<int> tabuleiroColunas(8, -1); // vetor que armazena as linhas ocupadas por cada coluna
    vector<vector<int>> solucoes; // vetor que armazena as soluções encontradas

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        tabuleiroColunas[y - 1] = x - 1; // marca a coluna ocupada pela rainha
        
        resolverOitoRainhas(tabuleiroColunas, 0, y - 1, x - 1, solucoes);

        // imprime as soluções encontradas
        for(int j = 0; j < solucoes.size(); j++)
        {
            cout << j + 1 << " ";
            for(int k = 0; k < 8; k++)
            {
                cout << solucoes[j][k] + 1 << " ";
            }
            cout << endl;
        }

        cout << endl;

        solucoes.clear(); // limpa as soluções encontradas
        tabuleiroColunas.assign(8, -1); // reinicia o vetor de colunas
    }
    

    return 0;
}