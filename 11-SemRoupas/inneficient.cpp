/*
 * Nome: Rodrigo de Freitas Lima
 * NUSP: 12547510
*/

#include <iostream>
#include <vector>

using namespace std;

int solucao(int dinheiroDisponivel, vector<vector<int>> precos, int categoriaAtual, int valorAtual)
{
    if(categoriaAtual == precos.size()) // Se todas as categorias foram processadas
    {
        return valorAtual; // Retorna o valor atual
    }

    int maiorValorPossivel = -1; // Armazena o maior valor encontrado

    for (int i = 0; i < precos[categoriaAtual].size(); i++)
    {
        int novoValor = valorAtual + precos[categoriaAtual][i]; // Calcula o novo valor
        int novoDinheiroDisponivel = dinheiroDisponivel - precos[categoriaAtual][i]; // Calcula o novo dinheiro disponível

        /*
        cout << "Categoria: " << categoriaAtual << " Indice: " << i << endl;
        cout << "Novo valor: " << novoValor << endl;
        cout << "Novo dinheiro disponível: " << novoDinheiroDisponivel << endl;
        */

        if (novoDinheiroDisponivel >= 0) // Permite gastar todo o dinheiro
        {
            int resultado = solucao(novoDinheiroDisponivel, precos, categoriaAtual + 1, novoValor);

            // Atualiza o maior valor encontrado
            maiorValorPossivel = max(maiorValorPossivel, resultado);
        }
    }

    return maiorValorPossivel; 
}

int main()
{
    int numeroDeCasosDeTeste;

    cin >> numeroDeCasosDeTeste;

    for(int i = 0; i < numeroDeCasosDeTeste; i++)
    {
        int dinheiroDisponivel;
        int numeroDeCategorias;

        cin >> dinheiroDisponivel >> numeroDeCategorias;

        vector<vector<int>> precos(numeroDeCategorias); // Cria um vetor de vetores para armazenar os preços

        for(int i = 0; i < numeroDeCategorias; i++)
        {
            int tamCategoria;

            cin >> tamCategoria;

            precos[i].resize(tamCategoria);

            for(int j = 0; j < tamCategoria; j++)
            {
                cin >> precos[i][j]; // Lê os preços de cada categoria
            }
        }

        int solucaoFinal = solucao(dinheiroDisponivel, precos, 0, 0); // Chama a função de solução

        if(solucaoFinal <= 0) // Se a solução final é -1
        {
            cout << "no solution" << endl; // Imprime 0
        }
        else // Se a solução final não é -1
        {
            cout << solucaoFinal << endl; // Imprime a solução final
        }
    }

    return 0;
}