// --------------------------------------------------------------------------------
// PRIMALIDADE
// --------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

bool primo(int n) {
    if (n < 2) {  // Caso especial: um número para ser primo precisa ser maior que 1
        return false;
    }

    for (int i = 2; i*i <= n; i++) {  // Iteração para cada número no intervalo [2, √n]
        if (n % i == 0) {  // Se n é divisível por i
            return false;  // O número não é primo
        }
    }

    return true;  // O número é primo
}
