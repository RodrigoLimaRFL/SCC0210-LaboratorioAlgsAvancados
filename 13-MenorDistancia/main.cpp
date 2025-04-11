#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        pair<int, int> tamanho;

        cin >> tamanho.first >> tamanho.second;

        pair<int, int> posInicial;

        cin >> posInicial.first >> posInicial.second;

        int numSujeiras;

        cin >> numSujeiras;

        vector<pair<int, int>> sujeiras(numSujeiras);

        for(int j = 0; j < numSujeiras; j++)
        {
            cin >> sujeiras[j].first >> sujeiras[j].second;
        }

        vector<vector<int>> dp(numSujeiras + 1, vector<int>(numSujeiras + 1, -1)); // Distancia entre sujeiras 
        dp[posInicial.first][posInicial.second] = 0; // Inicializa a posicao inicial com 0
    }

    return 0;
}