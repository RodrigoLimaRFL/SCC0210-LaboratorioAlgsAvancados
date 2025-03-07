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
    int n; // numero de doces

    cin >> n;

    int k; // maximo de doces gratis

    cin >> k;

    vector<int> doces(n); // preco dos doces

    for (int i = 0; i < n; i++)
    {
        cin >> doces[i];
    }

    sort(doces.begin(), doces.end());

    int minValue = 0;
    int maxValue = 0;

    int left = 0;
    int right = n - 1;

    while(left <= right)
    {
        minValue += doces[left];
        left++;
        right -= k;
    }

    cout << minValue << " ";

    left = 0;
    right = n - 1;

    while(right >= left)
    {
        maxValue += doces[right];
        right--;
        left += k;
    }

    cout << maxValue << endl;

    return 0;
}