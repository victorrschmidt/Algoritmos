// --------------------------------------------------------------------------------
// FIBONACCI TOP-DOWN
// --------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int dp[100];  // Array de memorização
bool ok[100];  // Array para verificar se um estado arbitrário da dp já foi calculado
int N = 10;  // Limite

// Função recursiva
int fib(int n) {
    if (ok[n]) {  // Se o estado n da dp já foi calculado
        return dp[n];  // Retornar o estado n da dp
    }

    ok[n] = true;  // Definir o estado n como 'calculado'
    dp[n] = fib(n-2) + fib(n-1);  // Definir o estado n da dp como a soma dos estados n-2 e n-1
    return dp[n];  // Retornar o estado n da dp
}

int main() {
    dp[1] = 0;  // Caso base
    ok[1] = true;
    dp[2] = 1;  // Caso base
    ok[2] = true;

    fib(N);  // Chamar a função para o último estado da dp (limite)

    // dp[1...N] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34}

    return 0;
}
