#include <iostream>
#include <vector>

using namespace std;

int resolver(int categoria, int dinheiroDisponivel, vector<vector<int>> precos, vector<vector<int>> memo)
{
    if(dinheiroDisponivel < 0) // Se o dinheiro disponível for negativo, retorna -1
    {
        return -1;
    }

    if(categoria == precos.size()) // Se todas as categorias foram processadas
    {
        return 0; // Retorna o valor atual
    }

    if(memo[categoria][dinheiroDisponivel] != -1) // Se já foi calculado, retorna o valor memoizado
    {
        return memo[categoria][dinheiroDisponivel];
    }

    int maiorValorPossivel = -1; // Armazena o maior valor encontrado

    for (int i = 0; i < precos[categoria].size(); i++)
    {
        int novoDinheiroDisponivel = dinheiroDisponivel - precos[categoria][i]; // Calcula o novo dinheiro disponível

        /*
        cout << "Categoria: " << categoria << " Indice: " << i << endl;
        cout << "Novo dinheiro disponível: " << novoDinheiroDisponivel << endl << endl;
        */

        if (novoDinheiroDisponivel >= 0) // Permite gastar todo o dinheiro
        {
            int resultado = resolver(categoria + 1, novoDinheiroDisponivel, precos, memo);

            // Atualiza o maior valor encontrado
            if(resultado != -1) // Se o resultado não for -1
            {
                maiorValorPossivel = max(maiorValorPossivel, resultado + precos[categoria][i]); // Adiciona o preço do item atual
            }
        }
    }

    memo[categoria][dinheiroDisponivel] = maiorValorPossivel; // Memoiza o resultado
    return maiorValorPossivel;
}

int main()
{
    int numCasosTeste;

    cin >> numCasosTeste;

    for(int i = 0; i < numCasosTeste; i++)
    {
        int dinheiroDisponivel;
        int numeroDeCategorias;

        cin >> dinheiroDisponivel >> numeroDeCategorias;

        vector<vector<int>> memo(numeroDeCategorias, vector<int>(dinheiroDisponivel + 1, -1)); // Vetor de memoização
        vector<vector<int>> precos(numeroDeCategorias); // Cria um vetor de vetores para armazenar os preços

        for(int i = 0; i < numeroDeCategorias; i++)
        {
            int tamCategoria;

            cin >> tamCategoria;

            precos[i].resize(tamCategoria); // Redimensiona o vetor da categoria

            for(int j = 0; j < tamCategoria; j++)
            {
                cin >> precos[i][j]; // Lê os preços
            }
        }

        int resultado = resolver(0, dinheiroDisponivel, precos, memo); // Chama a função de resolução

        if(resultado <= 0)
        {
            cout << "no solution" << endl;
        }
        else
        {
            cout << resultado << endl; // Imprime o resultado
        }
    }
    return 0;
}