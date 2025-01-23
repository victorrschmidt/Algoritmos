#include <iostream>
#include <vector>
using namespace std;

// Limite arbitrário de exemplo
int N = 10;

// Array de tabulação
vector<int> dp(N);

int main() {
    dp[0] = 0;  // Caso base: fib(0) = 0
    dp[1] = 1;  // Caso base: fib(1) = 1

    // Iteração para cada estado da dp (com exceção dos casos base)
    for (int i = 2; i < N; i++) {
        // O i-ésimo estado da dp (i-ésimo número de fibonacci)
        // é a soma dos dois estados anteriores.
        dp[i] = dp[i-2] + dp[i-1];
    }

    // dp[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34}

    return 0;
}
