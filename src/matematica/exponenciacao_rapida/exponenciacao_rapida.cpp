// --------------------------------------------------------------------------------
// EXPONENCIAÇÃO RÁPIDA
// --------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int potencia(int b, int e) {
    if (e == 0) return 1;  // Caso base: b^0 é igual a 1
    if (e & 1) return b * potencia(b, e - 1);  // Se o expoente for ímpar, retornar b * b^(e-1)
    int p = potencia(b, e / 2);  // Se o expoente for par, definir p = b^(e/2)
    return p*p;  // Retornar p*p = b^(e/2) * b^(e/2)
}

// ----------------------------------------
// UTILIZANDO MÓDULO
// ----------------------------------------

const int MOD = 42;

int potencia_mod(int b, int e) {
    if (e == 0) return 1;  // Caso base: b^0 é igual a 1
    if (e & 1) return b * potencia_mod(b, e - 1) % MOD;  // Se o expoente for ímpar, retornar b * b^(e-1) % mod
    int p = potencia_mod(b, e / 2);  // Se o expoente for par, definir p = b^(e/2)
    return p*p % MOD;  // Retornar p*p % mod = b^(e/2) * b^(e/2) % mod
}
