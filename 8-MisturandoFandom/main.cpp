/*
 * Nome: Rodrigo de Freitas Lima
 * NUSP: 12547510
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

int fact(int n)
{
    if(n == 0)
    {
        return 1;
    }

    return n * fact(n - 1);
}

int main()
{
    int n; // numero de fas
    int m; // numero de restricoes
    vector<array<int, 3>> restricoes;
    int numeroPermutacoes = 0;

    while(true)
    {
        cin >> n;
        cin >> m;

        if(n == 0 && m == 0) // caso de parada
        {
            break;
        }
        
        for(int i = 0; i < m; i++) // le restricoes
        {
            int a, b, c;
            cin >> a >> b >> c;

            if(a < 0 || b >= n || abs(c) >= n)
            {
                cerr << "restricao invalida" << endl;
                return 1;
            }

            restricoes.push_back({a, b, c});
        }

        vector<int> fas(n, 0); // vetor de fas

        for(int i = 0; i < n; i++) // le fas
        {
            fas[i] = i;
        }

        if(m == 0) // caso sem restricoes
        {
            numeroPermutacoes = fact(n);
        }
        else
        {
            do
            {
                bool valido = true;

                for(int i = 0; i < m; i++)
                {
                    int a = restricoes[i][0];
                    int b = restricoes[i][1];
                    int c = restricoes[i][2];

                    int posA = find(fas.begin(), fas.end(), a) - fas.begin();
                    int posB = find(fas.begin(), fas.end(), b) - fas.begin();

                    if(c > 0)
                    {
                        if(abs(posA - posB) > c)
                        {
                            valido = false;
                            break;
                        }
                    }
                    else
                    {
                        if(abs(posA - posB) < abs(c))
                        {
                            valido = false;
                            break;
                        }
                    }
                }

                if(valido)
                {
                    numeroPermutacoes++;
                }
            }
            while(next_permutation(fas.begin(), fas.end()));
        }
        
        cout << numeroPermutacoes << endl;
        numeroPermutacoes = 0;
        restricoes.clear();
    }
    
    return 0;
}