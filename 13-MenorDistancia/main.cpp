/*
 * Nome: Rodrigo de Freitas Lima
 * NUSP: 12547510
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int solucao(int bitmask, int posicao, int numSujeiras, vector<vector<int>>& dp, vector<vector<int>>& distancias) {
    // Se todas as sujeiras foram visitadas, retorna a distância até a posição inicial
    if(bitmask == (1 << numSujeiras) - 1) {
        return distancias[posicao][0];
    }
    
    // Se esse estado já foi calculado, retorna o valor memorizado
    if(dp[bitmask][posicao] != -1) {
        return dp[bitmask][posicao];
    }
    
    int menorCaminho = INT_MAX;
    
    // Tenta visitar cada sujeira não visitada
    for (int i = 0; i < numSujeiras; i++) {
        // Se a sujeira ainda não foi visitada
        if(!(bitmask & (1 << i))) {
            int novoBitmask = bitmask | (1 << i);
            // A posição i+1 nos arrays de distância corresponde à sujeira i
            // porque a posição 0 é reservada para a posição inicial
            int distancia = distancias[posicao][i+1] + solucao(novoBitmask, i+1, numSujeiras, dp, distancias);
            menorCaminho = min(menorCaminho, distancia);
        }
    }
    
    // Memoriza e retorna o resultado
    dp[bitmask][posicao] = menorCaminho;
    return menorCaminho;
}

int main() {
    int n; // Número de casos de teste
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        pair<int, int> tamanho; // Tamanho do mapa (linhas, colunas)
        cin >> tamanho.first >> tamanho.second;
        
        pair<int, int> posInicial; // Posição inicial do robô aspirador
        cin >> posInicial.first >> posInicial.second;
        
        int numSujeiras; // Número de sujeiras a serem limpas
        cin >> numSujeiras;
        
        vector<pair<int, int>> sujeiras(numSujeiras + 1); // Vetor para armazenar as posições das sujeiras
        sujeiras[0] = posInicial; // Adiciona a posição inicial como a primeira posição
        
        for(int j = 1; j < numSujeiras + 1; j++) {
            cin >> sujeiras[j].first >> sujeiras[j].second; // Lê as posições das sujeiras
        }
        
        // Matriz de memoização
        // dp[i][j] = menor caminho para a posição j, com o bitmask i representando as sujeiras visitadas
        vector<vector<int>> dp(1 << numSujeiras, vector<int>(numSujeiras + 1, -1));
        
        // Matriz de distâncias entre posições (posição inicial + sujeiras)
        vector<vector<int>> distancias(numSujeiras + 1, vector<int>(numSujeiras + 1, 0));
        
        // Calcula as distâncias Manhattan entre todas as posições
        for(int j = 0; j < numSujeiras + 1; j++) {
            for(int k = 0; k < numSujeiras + 1; k++) {
                distancias[j][k] = abs(sujeiras[j].first - sujeiras[k].first) + 
                                  abs(sujeiras[j].second - sujeiras[k].second);
            }
        }
        
        // Chama a função de solução
        // bitmask = 0 (nenhuma sujeira visitada), posicao = 0 (posição inicial)
        int resultado = solucao(0, 0, numSujeiras, dp, distancias);
        
        cout << "A menor rota tem tamanho " << resultado << "." << endl;
    }
    
    return 0;
}