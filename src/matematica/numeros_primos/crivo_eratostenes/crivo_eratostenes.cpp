// --------------------------------------------------------------------------------
// CRIVO DE ERATÓSTENES
// --------------------------------------------------------------------------------

/*
Complexidade: O(n*log(log(n)))

- Onde n é o número limite a ser considerado
*/

#include <bits/stdc++.h>
using namespace std;

vector<bool> crivo(int n) {
    vector<bool> primos(n+1);
    fill(primos.begin(), primos.end(), true);

    primos[0] = primos[1] = false;  // Casos especiais: 0 e 1 não são primos

    int p = 2;

    while (p * p <= n) {
        if (primos[p]) {
            for (int i = p * p; i <= n; i += p) {
                primos[i] = false;
            }
        }

        p++;
    }

    return primos;
}

int main() {
    vector<bool> v = crivo(15);

    // [false, false, true, true, false, true, false, true, false, false, false, true, false, true, false, false]
    //    0      1      2     3     4      5     6      7     8      9     10     11    12     13    14     15

    return 0;
}