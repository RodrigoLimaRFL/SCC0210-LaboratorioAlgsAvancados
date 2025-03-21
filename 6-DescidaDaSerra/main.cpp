/*
 * Nome: Rodrigo de Freitas Lima
 * NUSP: 12547510
*/

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    string line; // Linha de entrada
    float tamanhoMinTanque = 0;
    vector<pair<float, float>> gastoCombustivel; // <distancia, consumo>
    int totalVazamentos = 0; // Contador de vazamentos
    int consumo = -1; // consumo atual

    while (getline(cin, line)) {
        // Remove carriage return if present (helps with file redirection)
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }

        istringstream iss(line);
        int d;

        // Le a distância inicial
        if (!(iss >> d)) {
            continue; // Skip invalid lines
        }

        string evento;
        // Le o restante da linha como uma string completa
        getline(iss, evento);
        
        // Remove espaços a esquerda
        evento.erase(0, evento.find_first_not_of(" "));
        // Remove espaços extras no final
        if (!evento.empty()) {
            evento.erase(evento.find_last_not_of(" ") + 1);
        }

        // Parsing de eventos usando string::find para maior robustez
        if (evento.find("Consumo de combustível") == 0) {
            // Extrair o número após "Consumo de combustível"
            size_t pos = evento.find_last_of(" ");
            if (pos != string::npos) {
                istringstream numStream(evento.substr(pos + 1));
                if (numStream >> consumo) {
                    if (d == 0 && consumo == 0) { // Encerra o programa se a distancia e o consumo forem 0
                        break;
                    }
                    pair<float, float> par = make_pair(d, consumo / 100.0 + totalVazamentos);
                    gastoCombustivel.push_back(par);
                } else {
                    consumo = -1; // Entrada invalida
                }
            }
        } else if (evento == "Vazamento") {
            totalVazamentos++;
            pair<float, float> par = make_pair(d, consumo / 100.0 + totalVazamentos);
            gastoCombustivel.push_back(par);
        } else if (evento == "Mecânico") {
            totalVazamentos = 0;
            pair<float, float> par = make_pair(d, consumo / 100.0);
            gastoCombustivel.push_back(par);
        } else if (evento == "Posto de gasolina") {
            float tamanhoTanque = 0;
            pair<float, float> par = make_pair(d, consumo / 100.0 + totalVazamentos);
            gastoCombustivel.push_back(par);

            for(int i = 0; i < gastoCombustivel.size() - 1; i++) {
                // tanque = somatorio[i = 0, n-1](consumo * distancia entre pontos)
                tamanhoTanque += gastoCombustivel[i].second * (gastoCombustivel[i + 1].first - gastoCombustivel[i].first);
            }

            tamanhoMinTanque = max(tamanhoMinTanque, tamanhoTanque);

            gastoCombustivel.clear();
            gastoCombustivel.push_back(par);
        } else if (evento == "Destino") {
            float tamanhoTanque = 0;
            pair<float, float> par = make_pair(d, consumo / 100.0 + totalVazamentos);
            gastoCombustivel.push_back(par);

            for(int i = 0; i < gastoCombustivel.size() - 1; i++) {
                // tanque = somatorio[i = 0, n-1](consumo * distancia entre pontos)
                tamanhoTanque += gastoCombustivel[i].second * (gastoCombustivel[i + 1].first - gastoCombustivel[i].first);
            }

            tamanhoMinTanque = max(tamanhoMinTanque, tamanhoTanque);

            // imprime ate 3 casas decimais
            cout << fixed << setprecision(3) << tamanhoMinTanque << endl;
            cout.flush(); // Ensure output is flushed

            gastoCombustivel.clear();
            totalVazamentos = 0;
            consumo = -1;
            tamanhoMinTanque = 0;
        }
    }

    return 0;
}