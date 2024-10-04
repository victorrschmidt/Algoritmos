// ------------------------------------------------------------------
// PRIMALIDADE
// ------------------------------------------------------------------

#include <iostream>
using namespace std;

// Função para verificar se um número n é primo
bool primo(int n) {
    // Caso especial: um número para
    // ser primo precisa ser maior que 1.
    if (n < 2) {
        return false;
    }

    // Iteração de i no intervalo [2, √n]
    for (int i = 2; i*i <= n; i++) {
        // Se n é divisível por i
        if (n % i == 0) {
            // n não é primo
            return false;
        }
    }

    // Se n não é múltiplo de nenhum número
    // no intervalo [2, √n], n é primo.
    return true;
}
