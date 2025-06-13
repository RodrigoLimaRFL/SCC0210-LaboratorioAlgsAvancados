/*
 * Nome: Rodrigo de Freitas Lima
 * NUSP: 12547510
*/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

float detDoisPorDois(pair<int, int> p1, pair<int, int> p2)
{
    return (p1.first * p2.second) - (p1.second * p2.first);
}

float area(vector<pair<int, int>> pontos)
{
    float resultado = 0;

    int n = pontos.size();

    for(int i = 0; i < n; i++)
    {
        int j = (i + 1) % n; 
        resultado += detDoisPorDois(pontos[i], pontos[j]);
    }

    return abs(resultado) / 2.0;
}

int main()
{
    int t;

    cin >> t; 

    for(int i = 0; i < t; i++)
    {
        int n;

        cin >> n;

        vector<pair<int, int>> pontos;

        for(int j = 0; j < n; j++)
        {
            int x, y;
            cin >> x >> y;
            pontos.push_back(make_pair(x, y));
        }

        float resultado = area(pontos);

        cout << fixed << setprecision(1) << resultado << endl;
    }

    return 0;
}