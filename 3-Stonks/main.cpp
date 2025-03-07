/*
 * Nome: Rodrigo de Freitas Lima
 * NUSP: 12547510
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; // Quantidade de dias
    cin >> n;

    vector<int> prices(n); // Vetor de precos
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    int k; // Orcamento

    cin >> k;

    vector<pair<int, int>> pricesWithMaxActions(n); // Vetor de precos com acoes maximas

    for(int i = 0; i < n; i++){
        pricesWithMaxActions[i] = {prices[i], i + 1};
    }

    sort(pricesWithMaxActions.begin(), pricesWithMaxActions.end());

    int totalActions = 0; // Total de acoes compradas
    for(int i = 0; i < n; i++){
        int maxActions = pricesWithMaxActions[i].second;
        int price = pricesWithMaxActions[i].first;

        int maxAffordable = k / price;

        totalActions += min(maxActions, maxAffordable);

        k -= price * min(maxActions, maxAffordable);

        if(k <= 0){
            break;
        }
    }

    cout << totalActions << endl;

    return 0;
}