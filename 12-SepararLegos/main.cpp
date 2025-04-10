/*
 * Nome: Rodrigo de Freitas Lima
 * NUSP: 12547510
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int custoMinimo(int comprimento, vector<int>& separacoes)
{
    int n = separacoes.size();
    separacoes.insert(separacoes.begin(), 0); // Adiciona o ponto 0 no vetor de separações
    separacoes.push_back(comprimento); // Adiciona o ponto final no vetor de separações

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0)); // Matriz de custo minimo pro corte entre i e j
    
    for(int tamanho = 2; tamanho <= n + 1; tamanho++) // Tamanho do intervalo
    {
        for(int i = 0; i <= n + 1 - tamanho; i++) // Ponto inicial do intervalo
        {
            int j = i + tamanho; // Ponto final do intervalo
            dp[i][j] = INT_MAX; // Inicializa o custo como infinito

            for(int k = i + 1; k < j; k++) // Ponto de corte
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + separacoes[j] - separacoes[i]); // Atualiza o custo minimo
            }
        }
    }

    return dp[0][n + 1]; // Retorna o custo minimo para cortar o Lego
}

int main()
{
    int l; // Comprimento do Lego
    int n; // Número de separações

    vector<int> resultados;

    cin >> l;

    while(l != 0)
    {
        cin >> n; // Número de separações
        vector<int> separacoes(n); // Vetor para armazenar as separações

        for(int i = 0; i < n; i++)
        {
            cin >> separacoes[i]; // Lê as separações
        }

        int resultado = custoMinimo(l, separacoes); // Chama a função para calcular o custo minimo

        resultados.push_back(resultado); // Armazena o resultado

        cin >> l;
    }

    for(int i = 0; i < resultados.size(); i++)
    {
        cout << "O custo mínimo de separação é " << resultados[i] << "." << endl; // Imprime os resultados
    }

    return 0;
}