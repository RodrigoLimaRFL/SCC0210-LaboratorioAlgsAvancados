#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int valor;
    Node *proximo;
};

Node* criarNo(int valor)
{
    Node* novoNo = new Node();
    novoNo->valor = valor;
    novoNo->proximo = nullptr;
    return novoNo;
}

class ListaEncadeada
{
    public:
        Node* cabeca;

        ListaEncadeada()
        {
            cabeca = nullptr;
        }

        void inserir(int valor)
        {
            Node* novoNo = criarNo(valor);
            novoNo->proximo = cabeca;
            cabeca = novoNo;
        }

        void inserirLista(ListaEncadeada& lista)
        {
            Node* atual = lista.cabeca;
            while(atual != nullptr)
            {
                inserir(atual->valor);
                atual = atual->proximo;
            }
        }

        void imprimir()
        {
            Node* atual = cabeca;
            while(atual != nullptr)
            {
                cout << atual->valor << " ";
                atual = atual->proximo;
            }
            cout << endl;
        }
};

bool ehPrimo(int n)
{
    if(n < 2)
        return false;

    if(n == 2)
        return true;

    if(n % 2 == 0)
        return false;

    for(int i = 3; i * i <= n; i+=2)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    vector<ListaEncadeada> listaPrimos(101);

    bool ehPrimoLista[101];

    for(int i = 0; i <= 100; i++)
    {
        ehPrimoLista[i] = ehPrimo(i);
    }

    while(true)
    {
        cin >> n;

        if(n == 0)
            break;

        for(int i = 0; i <= n; i++)
        {
            if(listaPrimos[i].cabeca != nullptr)
            {
                continue;
            }

            if(ehPrimoLista[i])
            {
                listaPrimos[i].inserir(i);
            }
            else
            {
                int valorDividido = i;

                for(int j = (i / 2) + 1; j > 1; j--)
                {
                    if(valorDividido % j == 0)
                    {
                        valorDividido /= j;
                        listaPrimos[i].inserir(valorDividido);
                        listaPrimos[i].inserirLista(listaPrimos[j]);
                        break;
                    }
                }
            }
        }

        vector<int> quantidadePrimos(101, 0);

        for (int i = 0; i <= n; i++)
        {
            Node* atual = listaPrimos[i].cabeca;
            while(atual != nullptr)
            {
                quantidadePrimos[atual->valor]++;
                atual = atual->proximo;
            }
        }

        cout << n << "! = ";

        if(n == 1)
        {
            cout << "0";
        }
        else
        {
            for(int i = 0; i <= n; i++)
            {
                if(quantidadePrimos[i] > 0)
                {
                    cout << quantidadePrimos[i] << " ";
                }
            }
        }
        
        cout << endl;
    }
    return 0;
}