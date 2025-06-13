#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

vector<int> nosConectadosDiretamente(int noFonte, vector<vector<long long int>>& grafo) {
    vector<int> nosConectados;
    for(long long unsigned int i = 0; i < grafo.size(); i++) {
        if(grafo[noFonte][i] != -1) {
            nosConectados.push_back(i);
        }
    }
    return nosConectados;
}

int menorCaminho(int s, int t, vector<vector<long long int>>& grafo, vector<pair<int, long long int>>& distanciasMinimas, vector<pair<int, int>>& arestasZeradas) {
    int n = grafo.size();
    // pq(distancia, vertice)
    priority_queue<pair<long long int, int>> pq;
    vector<int> distancia(n, -1);
    distancia[s] = 0;

    pq.push({0, s}); // adiciona a origem na fila de prioridade
    while(!pq.empty()) { // enquanto a fila de prioridade nao estiver vazia
        pair<long long int, int> atual = pq.top(); // no atual
        pq.pop();

        // nos conectados diretamente ao no atual
        vector<int> nosConectados = nosConectadosDiretamente(atual.second, grafo);

        for(long long unsigned int i = 0; i < nosConectados.size(); i++) {
            int vizinho = nosConectados[i];
            long long int peso = grafo[atual.second][vizinho];

            // se o vizinho nao foi visitado ou se a distancia atual e menor que a distancia armazenada 
            if(distancia[vizinho] == -1 || distancia[vizinho] > atual.first + peso) {
                // atualiza a distancia do vizinho
                distancia[vizinho] = atual.first + peso;
                // adiciona o vizinho na fila de prioridade
                pq.push({distancia[vizinho], vizinho});
                // atualiza a distancia minima
                distanciasMinimas[vizinho] = {atual.second, peso};

                if(peso == 0) {
                    // se o peso da aresta for 0, atualiza a aresta zerada
                    arestasZeradas.push_back({atual.second, vizinho});
                }

                // se o vizinho for o destino, retorna a distancia
                if(vizinho == t) {
                    return distancia[vizinho];
                }
            }
        }
    }

    // se o destino nao for alcancavel, retorna -1
    return -1;
}

int main() {
    int n, m;
    long long int L;
    int s, t; // vertices, arestas, comprimentoDesejado, origem, destino

    cin >> n >> m >> L >> s >> t;

    vector<vector<long long int>> grafo(n, vector<long long int>(n, -1));
    vector<pair<int, int>> arestasInseridas;

    for(int i = 0; i < m; i++) {
        int u, v; 
        long long int peso;
        cin >> u >> v >> peso;
        grafo[u][v] = peso;
        grafo[v][u] = peso; // grafo nao direcionad

        arestasInseridas.push_back({u, v});
    }

    vector<pair<int, long long int>> distanciasMinimas(n, {-1, LLONG_MAX});
    vector<pair<int, int>> arestasZeradas;

    int menor = menorCaminho(s, t, grafo, distanciasMinimas, arestasZeradas);

    if(menor > L) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        
        int numArestasZeradas = arestasZeradas.size();
        int diferenca = L - menor;
        int resto = diferenca % numArestasZeradas;
        int quociente = diferenca / numArestasZeradas;

        for(int i = 0; i < numArestasZeradas; i++) {
            grafo[arestasZeradas[i].first][arestasZeradas[i].second] = quociente;
            grafo[arestasZeradas[i].second][arestasZeradas[i].first] = quociente;
        }

        for(int i = 0; i < resto; i++) {
            grafo[arestasZeradas[i].first][arestasZeradas[i].second] += 1;
            grafo[arestasZeradas[i].second][arestasZeradas[i].first] += 1;
        }

        sort(arestasInseridas.begin(), arestasInseridas.end());

        for(int i = 0; i < arestasInseridas.size(); i++) {
            cout << arestasInseridas[i].first << " " << arestasInseridas[i].second << " " << grafo[arestasInseridas[i].first][arestasInseridas[i].second] << endl;
        }
    }

    return 0;
}