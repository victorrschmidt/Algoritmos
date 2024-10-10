#include <iostream>
using namespace std;

// Função recursiva para calcular b**e % m
int potencia_mod(int b, int e, int m) {
    // Caso base: b**0 é igual a 1
    if (e == 0) {
        return 1;
    }

    // Se o expoente for ímpar
    if (e & 1) {
        // Retornar b * b**(e-1) % m
        return b * potencia_mod(b, e - 1, m) % m;
    }

    // Se o expoente for par, definir p = b**(e/2)
    int p = potencia_mod(b, e / 2, m);

    // Retornar p*p % m = b**(e/2) * b**(e/2) % m
    return p*p % m;
}

int main() {

    return 0;
}
