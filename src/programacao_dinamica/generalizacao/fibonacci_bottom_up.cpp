// --------------------------------------------------------------------------------
// FIBONACCI BOTTOM-UP
// --------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int dp[100];  // Array de tabulação
int N = 10;  // Limite

int main() {
    dp[1] = 0;  // Caso base
    dp[2] = 1;  // Caso base

    for (int i = 3; i <= N; i++) {  // Iteração para cada estado da dp (com exceção dos casos base)
        dp[i] = dp[i-2] + dp[i-1];  // O i-ésimo número de fibonacci é a soma dos dois anteriores
    }

    // dp[1...N] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34}

    return 0;
}
