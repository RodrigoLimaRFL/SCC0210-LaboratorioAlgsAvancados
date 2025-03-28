#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; // numero de posicoes pre determinadas

    cin >> n;

    vector<pair<int, int>> posicoes(n); // linha x coluna

    for (int i = 0; i < n; i++)
    {
        cin >> posicoes[i].first >> posicoes[i].second;
    }
    
    vector<vector<int>> tabuleiro(8, vector<int>(8, 0));

    return 0;
}