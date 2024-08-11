// --------------------------------------------------------------------------------
// CRIVO DE ERATÓSTENES
// --------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

vector<bool> crivo(int n) {
    vector<bool> primos(n+1, true);  // Array de primos (todos os elementos inicializados como true)

    primos[0] = primos[1] = false;  // Casos especiais: 0 e 1 não são primos

    for (int p = 2; p*p <= n; p++) {  // Iteração de p no intervalo [2, √n]
        if (!primos[p]) {  // Se o número não é primo
            continue;  // Continuar a iteração
        }

        for (int i = p*p; i <= n; i += p) {  // Iteração de i (múltiplos de p) no intervalo [p*p, n]
            primos[i] = false;  // Definir o número como não primo
        }
    }

    return primos;  // Retornar o array
}

int main() {
    vector<bool> v = crivo(14);

    // {false, false, true, true, false, true, false, true, false, false, false, true, false, true, false}
    //    0      1      2     3     4      5     6      7     8      9     10     11    12     13    14
    //                primo primo        primo        primo                      primo        primo

    return 0;
}
