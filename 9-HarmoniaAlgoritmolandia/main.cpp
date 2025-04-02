/*
 * Nome: Rodrigo de Freitas Lima
 * NUSP: 12547510
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int potencia(int base, int exp) {
    int resultado = 1;
    for (int i = 0; i < exp; i++) {
        resultado *= base;
    }
    return resultado;
}

bool verificarDigitos(int numero, vector<bool>& digitos) {
    for(int i = 0; i < 5; i++)
    {
        int digitoN = numero % 10;
        numero /= 10; // divide o número pela potência
        if (digitos[digitoN]) {
            return false; // dígito já foi utilizado
        }
        digitos[digitoN] = true; // marca o dígito como utilizado
    }

    return true; // todos os dígitos são únicos
}

int main()
{
    int n; // num objetivo
    vector<bool> digitos(10, false); // vetor que armazena os digitos de 0 a 9
    vector<int> digitosRestantes(5);

    while (cin >> n && n != 0) {
        bool encontrou = false; // flag para verificar se o número foi encontrado

        fill(digitos.begin(), digitos.end(), false); // reinicia o vetor de dígitos

        int max = 99999 / n; // valor máximo para o denominador

        for(int denominador = 1234; denominador <= max; denominador++)
        {
            fill(digitos.begin(), digitos.end(), false);
            if(!verificarDigitos(denominador, digitos)) // verifica se o número já foi utilizado
            {
                continue; // se já foi utilizado, pula para o próximo número
            }

            int numerador = denominador * n; // calcula o numerador desejado
            
            if(verificarDigitos(numerador, digitos)) // verifica se o numerador desejado é válido
            {
                cout << numerador << " / " << denominador << " = " << n << endl; // imprime o denominador e o numerador
                encontrou = true; // marca que encontrou uma solução
            }
        }

        if (!encontrou) {
            cout << "Não há soluções para " << n << "." << endl; // se não encontrou, imprime mensagem
        }

        cout << endl; // imprime uma linha em branco
    }

    return 0;
}