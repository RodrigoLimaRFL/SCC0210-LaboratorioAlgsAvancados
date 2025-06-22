#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int MAX = 86;
    vector<unsigned long long> fib(MAX);

    // Inicialização da sequência com base na descrição correta
    fib[0] = 1;
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i < MAX; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    int n;
    while (cin >> n && n != 0) {
        cout << fib[n] << endl;
    }

    return 0;
}
