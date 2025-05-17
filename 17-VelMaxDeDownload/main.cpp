#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

const long long int MAXN = 505;
vector<long long int> graph[MAXN];
long long int capacity[MAXN][MAXN]; // Capacidade original
long long int flow[MAXN][MAXN];     // Fluxo atual
long long int parent[MAXN];         // Armazenar caminho de aumento

// Encontra um caminho de aumento usando BFS
bool bfs(long long int source, long long int sink) {
    fill(parent, parent + MAXN, -1);
    queue<long long int> q;
    q.push(source);
    parent[source] = -2; // Marcar fonte como visitada
    
    while (!q.empty()) {
        long long int current = q.front();
        q.pop();
        
        for (long long int next : graph[current]) {
            // Se o nó não foi visitado e há capacidade residual
            if (parent[next] == -1 && capacity[current][next] - flow[current][next] > 0) {
                parent[next] = current;
                if (next == sink) return true; // Caminho encontrado
                q.push(next);
            }
        }
    }
    
    return false; // Nenhum caminho encontrado
}

// Algoritmo de Edmonds-Karp para encontrar o fluxo máximo
long long int edmonds_karp(long long int source, long long int sink) {
    long long int max_flow = 0;
    
    // Inicializa fluxo em todas as arestas como 0
    for (long long int i = 0; i < MAXN; i++) {
        for (long long int j = 0; j < MAXN; j++) {
            flow[i][j] = 0;
        }
    }
    
    // Enquanto existe um caminho de aumento
    while (bfs(source, sink)) {
        // Encontra o fluxo máximo que podemos enviar neste caminho
        long long int path_flow = LLONG_MAX; // Usar LLONG_MAX ao invés de INT_MAX para evitar overflow
        for (long long int v = sink; v != source; v = parent[v]) {
            long long int u = parent[v];
            path_flow = min(path_flow, capacity[u][v] - flow[u][v]);
        }
        
        // Atualiza o fluxo
        for (long long int v = sink; v != source; v = parent[v]) {
            long long int u = parent[v];
            flow[u][v] += path_flow;
            flow[v][u] -= path_flow; // Fluxo reverso
        }
        
        max_flow += path_flow;
    }
    
    return max_flow;
}

int main() {
    long long int n, m;
    cin >> n >> m;
    
    // Limpa matrizes
    for (long long int i = 0; i < MAXN; i++) {
        for (long long int j = 0; j < MAXN; j++) {
            capacity[i][j] = 0;
        }
    }
    
    for (long long int i = 0; i < m; i++) {
        long long int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(b);
        graph[b].push_back(a); // Adiciona aresta reversa para o algoritmo
        capacity[a][b] += c;   // Use += para somar capacidades em caso de múltiplas arestas entre os mesmos nós
    }
    
    long long int max_flow = edmonds_karp(1, n);
    cout << max_flow << endl;
    
    return 0;
}