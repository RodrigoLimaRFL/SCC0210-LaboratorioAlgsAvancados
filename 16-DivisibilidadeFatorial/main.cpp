#include <iostream>
#include <map>
using namespace std;

bool ehPrimo(unsigned long long int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (unsigned long long int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

map<unsigned long long int, unsigned long long int> fatorar(unsigned long long int n) {
    map<unsigned long long int, unsigned long long int> fatores;
    for (unsigned long long int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            fatores[i]++;
            n /= i;
        }
    }
    if (n > 1)
        fatores[n]++;
    return fatores;
}

unsigned long long int contarFatorEmFatorial(unsigned long long int n, unsigned long long int p) {
    unsigned long long int count = 0;
    while (n > 0) {
        count += n / p;
        n /= p;
    }
    return count;
}

bool divideFatorial(unsigned long long int n, unsigned long long int divisor) {
    if (divisor == 0) return false;
    if (divisor == 1) return true;
    
    auto fatores = fatorar(divisor);

    for (auto [primo, expoente] : fatores) {
        unsigned long long int contagem = contarFatorEmFatorial(n, primo);
        if (contagem < expoente)
            return false;
    }
    return true;
}

int main() {
    unsigned long long int n, divisor;

    while (cin >> n >> divisor) {
        if (divideFatorial(n, divisor))
            cout << divisor << " divides " << n << "!" << endl;
        else
            cout << divisor << " does not divide " << n << "!" << endl;
    }

    return 0;
}
