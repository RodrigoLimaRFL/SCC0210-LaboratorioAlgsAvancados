#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Pedido {
    int quantidade;
    int prazo;
    
    Pedido(int q, int d) : quantidade(q), prazo(d) {}
};

// Algoritmo usando priority queue para otimização
int resolverComPriorityQueue(vector<Pedido>& pedidos) {
    // Ordena por prazo
    sort(pedidos.begin(), pedidos.end(), [](const Pedido& a, const Pedido& b) {
        return a.prazo < b.prazo;
    });
    
    priority_queue<int> pq; // max heap para quantidades
    long long tempoTotal = 0;
    
    for (const auto& pedido : pedidos) {
        if (tempoTotal + pedido.quantidade <= pedido.prazo) {
            // Pode adicionar este pedido
            pq.push(pedido.quantidade);
            tempoTotal += pedido.quantidade;
        } else if (!pq.empty() && pq.top() > pedido.quantidade) {
            // Remove o pedido com maior quantidade e adiciona o atual
            tempoTotal -= pq.top();
            pq.pop();
            pq.push(pedido.quantidade);
            tempoTotal += pedido.quantidade;
        }
    }
    
    return pq.size();
}

// Algoritmo guloso simples para comparação
int resolverGuloso(vector<Pedido>& pedidos) {
    sort(pedidos.begin(), pedidos.end(), [](const Pedido& a, const Pedido& b) {
        return a.prazo < b.prazo;
    });
    
    long long tempo = 0;
    int aceitos = 0;
    
    for (const auto& p : pedidos) {
        if (tempo + p.quantidade <= p.prazo) {
            tempo += p.quantidade;
            aceitos++;
        }
    }
    
    return aceitos;
}

// Algoritmo que ordena por quantidade primeiro
int resolverPorQuantidade(vector<Pedido>& pedidos) {
    sort(pedidos.begin(), pedidos.end(), [](const Pedido& a, const Pedido& b) {
        if (a.quantidade == b.quantidade) {
            return a.prazo < b.prazo;
        }
        return a.quantidade < b.quantidade;
    });
    
    long long tempo = 0;
    int aceitos = 0;
    
    for (const auto& p : pedidos) {
        if (tempo + p.quantidade <= p.prazo) {
            tempo += p.quantidade;
            aceitos++;
        }
    }
    
    return aceitos;
}

// Algoritmo que considera a "urgência" (prazo/quantidade)
int resolverPorUrgencia(vector<Pedido>& pedidos) {
    sort(pedidos.begin(), pedidos.end(), [](const Pedido& a, const Pedido& b) {
        double urgenciaA = (double)a.prazo / a.quantidade;
        double urgenciaB = (double)b.prazo / b.quantidade;
        if (abs(urgenciaA - urgenciaB) < 1e-9) {
            return a.prazo < b.prazo;
        }
        return urgenciaA < urgenciaB;
    });
    
    long long tempo = 0;
    int aceitos = 0;
    
    for (const auto& p : pedidos) {
        if (tempo + p.quantidade <= p.prazo) {
            tempo += p.quantidade;
            aceitos++;
        }
    }
    
    return aceitos;
}

// Força bruta para casos pequenos
int resolverForcaBruta(vector<Pedido>& pedidos) {
    if (pedidos.size() > 22) {
        return resolverComPriorityQueue(pedidos);
    }
    
    int n = pedidos.size();
    int maxAceitos = 0;
    
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<Pedido> selecionados;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                selecionados.push_back(pedidos[i]);
            }
        }
        
        sort(selecionados.begin(), selecionados.end(), [](const Pedido& a, const Pedido& b) {
            return a.prazo < b.prazo;
        });
        
        long long tempo = 0;
        bool viavel = true;
        
        for (const auto& p : selecionados) {
            tempo += p.quantidade;
            if (tempo > p.prazo) {
                viavel = false;
                break;
            }
        }
        
        if (viavel) {
            maxAceitos = max(maxAceitos, (int)selecionados.size());
        }
    }
    
    return maxAceitos;
}

int resolverCronograma(vector<Pedido>& pedidos) {
    int resultado1 = resolverGuloso(pedidos);
    int resultado2 = resolverComPriorityQueue(pedidos);
    int resultado3 = resolverPorQuantidade(pedidos);
    int resultado4 = resolverPorUrgencia(pedidos);
    
    int melhor = max({resultado1, resultado2, resultado3, resultado4});
    
    // Para casos pequenos, usa força bruta
    if (pedidos.size() <= 22) {
        int resultado5 = resolverForcaBruta(pedidos);
        melhor = max(melhor, resultado5);
    }
    
    return melhor;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int numCasos;
    cin >> numCasos;
    
    for (int caso = 0; caso < numCasos; caso++) {
        if (caso > 0) {
            cout << "\n";
        }
        
        int n;
        cin >> n;
        
        vector<Pedido> pedidos;
        pedidos.reserve(n);
        
        for (int i = 0; i < n; i++) {
            int q, d;
            cin >> q >> d;
            pedidos.emplace_back(q, d);
        }
        
        int resultado = resolverCronograma(pedidos);
        cout << resultado << "\n";
    }
    
    return 0;
}