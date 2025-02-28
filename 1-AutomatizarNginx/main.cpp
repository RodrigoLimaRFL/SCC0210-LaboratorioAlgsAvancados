/*
 * Nome: Rodrigo de Freitas Lima
 * NUSP: 12547510
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, m; // n = número de servidores, m = número de comandos
    cin >> n >> m;
    
    unordered_map<string, string> servidores;

    // Lendo os servidores e seus IPs
    for (int i = 0; i < n; i++) {
        string nome, ip;
        cin >> nome >> ip;

        if(nome.size() > 10 || nome.size() < 1) {
            cerr << "O nome do servidor deve ter entre 1 e 10 caracteres." << endl;
            return 1;
        }

        servidores[ip] = nome;
    }

    vector<string> comandosECaminhos;

    for (int i = 0; i < m; i++) {
        string comando, ip_completo;
        cin >> comando >> ip_completo;
        
        // Remover o ponto e vírgula do IP
        string ip = ip_completo.substr(0, ip_completo.size() - 1);

        comandosECaminhos.push_back(comando + " " + ip_completo + " #" + servidores[ip]);
    }

    for (int i = 0; i < m; i++) {
        cout << comandosECaminhos[i] << endl;
    }

    return 0;
}
