/*
 * Nome: Rodrigo de Freitas Lima
 * NUSP: 12547510
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> binomialComModulo(int tamanho, int mod)
{
    // Calcula os binomiais C(n, k) pelo método de Pascal
    vector<vector<int>> binomial(tamanho + 1, vector<int>(tamanho + 1, 0));
    binomial[0][0] = 1; // C(0, 0) = 1

    for (int i = 1; i <= tamanho; i++)
    {
        binomial[i][0] = 1; // C(i, 0) = 1
        for (int j = 1; j <= i; j++)
        {
            // C(i, j) = C(i-1, j-1) + C(i-1, j)
            // C(i, j) % mod = (C(i-1, j-1) % mod + C(i-1, j) % mod) % mod
            binomial[i][j] = (binomial[i - 1][j - 1] + binomial[i - 1][j]) % mod;
        }
    }

    return binomial;
}

int main()
{
    vector<pair<int, int>> casosDeTeste;
    int numCasosDeTeste = 0;

    while (true)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        casosDeTeste.push_back({a, b});
        numCasosDeTeste++;
    }

    int maxNK = 0;

    for (int i = 0; i < numCasosDeTeste; i++)
    {
        maxNK = max(maxNK, casosDeTeste[i].first + casosDeTeste[i].second);
    }

    int mod = 1000000;
    vector<vector<int>> binomial = binomialComModulo(maxNK, mod);

    for (int i = 0; i < numCasosDeTeste; i++)
    {
        int n = casosDeTeste[i].first;
        int k = casosDeTeste[i].second;

        cout << binomial[n + k - 1][k - 1] << endl;
    }

    return 0;
}