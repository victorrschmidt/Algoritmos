// ------------------------------------------------------------------
// FIBONACCI BOTTOM-UP
// ------------------------------------------------------------------

#include <iostream>
#include <vector>
using namespace std;

// Limite arbitrário de exemplo
int N = 10;

// Array de tabulação
vector<int> dp(N+1);

int main() {
    dp[1] = 0;  // Caso base => fib(1) = 0
    dp[2] = 1;  // Caso base => fib(2) = 1

    // Iteração para cada estado da dp (com exceção dos casos base)
    for (int i = 3; i <= N; i++) {
        // O i-ésimo estado da dp (i-ésimo número de fibonacci)
        // é a soma dos dois estados anteriores.
        dp[i] = dp[i-2] + dp[i-1];
    }

    // dp[1...N] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34}

    return 0;
}
