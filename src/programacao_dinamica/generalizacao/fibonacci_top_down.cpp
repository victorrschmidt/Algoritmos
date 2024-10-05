// ------------------------------------------------------------------
// FIBONACCI TOP-DOWN
// ------------------------------------------------------------------

#include <iostream>
#include <vector>
using namespace std;

// Limite arbitrário de exemplo
int N = 10;

// Array de memorização
vector<int> dp(N+1);

// Array para verificar se um estado
// arbitrário da dp já foi calculado
vector<bool> calculado(N+1);

// Função recursiva para calcular os números de fibonacci de 1 até n
int fib(int n) {
    // Se o estado n da dp já foi calculado
    if (calculado[n]) {
        // Retornar o estado n da dp
        return dp[n];
    }

    // Definir o estado n da dp como a soma dos estados n-2 e n-1
    dp[n] = fib(n-2) + fib(n-1);

    // Definir o estado n como 'calculado'
    calculado[n] = true;

    // Retornar o estado n da dp
    return dp[n];
}

int main() {
    dp[1] = 0;  // Caso base => fib(1) = 0
    dp[2] = 1;  // Caso base => fib(2) = 1
    calculado[1] = true;
    calculado[2] = true;

    fib(N);  // Chamar a função para o último estado da dp (limite)

    // dp[1...N] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34}

    return 0;
}
