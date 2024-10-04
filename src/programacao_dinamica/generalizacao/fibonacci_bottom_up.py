# -------------------------------------------------------------------
# FIBONACCI BOTTOM-UP
# -------------------------------------------------------------------

# Limite arbitrário de exemplo
N = 10

# Lista de tabulação
dp = [0 for i in range(N+1)]

dp[1] = 0  # Caso base => fib(1) = 0
dp[2] = 1  # Caso base => fib(2) = 1

# Iteração para cada estado da dp (com exceção dos casos base)
for i in range(3, N+1):
    # O i-ésimo estado da dp (i-ésimo número de fibonacci)
    # é a soma dos dois estados anteriores.
    dp[i] = dp[i-2] + dp[i-1]

# dp[1...N] = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
