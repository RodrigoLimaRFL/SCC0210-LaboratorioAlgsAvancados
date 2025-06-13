#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    int n;

    while(cin >> n)
    {
        if(n == 0)
            break;

        vector<pair<int, int>> pontos(n);
        int menorX = INT_MAX;
        int menorY = INT_MAX;
        int maiorX = INT_MIN;
        int maiorY = INT_MIN;

        for(int i = 0; i < n; i++)
        {
            cin >> pontos[i].first >> pontos[i].second;

            if(pontos[i].first < menorX)
                menorX = pontos[i].first;

            if(pontos[i].second < menorY)
                menorY = pontos[i].second;

            if(pontos[i].first > maiorX)
                maiorX = pontos[i].first;

            if(pontos[i].second > maiorY)
                maiorY = pontos[i].second;
        }

        pair<int, int> ponto;

        cin >> ponto.first >> ponto.second;

        if(ponto.first < menorX || ponto.first > maiorX)
        {
            cout << "F" << endl;
            continue;
        }

        if(ponto.second < menorY || ponto.second > maiorY)
        {
            cout << "F" << endl;
            continue;
        }

        int numInterseccoesVerticais = 0;

        for(int i = 0; i < n; i++) // Ponto externo na esquerda
        {
            int j = (i + 1) % n;

            int primeiroX = pontos[i].first;
            int primeiroY = pontos[i].second;
            int segundoX = pontos[j].first;
            int segundoY = pontos[j].second;

            if(primeiroX != segundoX) // Reta horizontal
            {
                continue;
            }

            if(primeiroX > ponto.first) // Reta vertical a direita do ponto
            {
                continue;
            }

            if(primeiroY > ponto.second && segundoY > ponto.second) // Reta vertical acima do ponto
            {
                continue;
            }
            else if(primeiroY < ponto.second && segundoY < ponto.second) // Reta vertical abaixo do ponto
            {
                continue;
            }

            numInterseccoesVerticais++;
        }

        if(numInterseccoesVerticais % 2 == 0)
        {
            cout << "F" << endl;
        }
        else
        {
            cout << "T" << endl;
        }
    }

    return 0;
}