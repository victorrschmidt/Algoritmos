#include <iostream>
#include <vector>
using namespace std;

// Limite arbitrário de exemplo
int N = 10;

// Array de memorização
vector<int> dp(N);

// Array para verificar se um estado
// arbitrário da dp já foi calculado.
vector<bool> calculado(N);

// Função recursiva para calcular os números de fibonacci de 0 até N-1
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
    dp[0] = 0;  // Caso base: fib(0) = 0
    dp[1] = 1;  // Caso base: fib(1) = 1
    calculado[0] = true;
    calculado[1] = true;

    // Chamar a função para o último estado da dp (limite)
    fib(N-1);

    // dp[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34}

    return 0;
}
