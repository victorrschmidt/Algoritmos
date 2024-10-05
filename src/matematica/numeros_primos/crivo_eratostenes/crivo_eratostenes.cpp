// ------------------------------------------------------------------
// CRIVO DE ERATÓSTENES
// ------------------------------------------------------------------

#include <iostream>
#include <vector>
using namespace std;

// Função para gerar o array de primos de 0 até n
vector<bool> crivo(int n) {
    // Array de primos (todos os elementos inicializados como true)
    vector<bool> primos(n+1, true);

    // Casos especiais: 0 e 1 não são números primos
    primos[0] = primos[1] = false;

    // Iteração de p no intervalo [2, √n]
    for (int p = 2; p*p <= n; p++) {
        // Se p não é primo
        if (!primos[p]) {
            // Continuar a iteração
            continue;
        }

        // Iteração de i (múltiplos de p) no intervalo [p*p, n]
        for (int i = p*p; i <= n; i += p) {
            // Definir i como não primo
            primos[i] = false;
        }
    }

    // Retornar o array
    return primos;
}
