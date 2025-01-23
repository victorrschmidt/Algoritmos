# Limite arbitrário de exemplo
N = 10

# Lista de tabulação
dp = [0 for i in range(N)]

dp[0] = 0  # Caso base: fib(0) = 0
dp[1] = 1  # Caso base: fib(1) = 1

# Iteração para cada estado da dp (com exceção dos casos base)
for i in range(2, N):
    # O i-ésimo estado da dp (i-ésimo número de fibonacci)
    # é a soma dos dois estados anteriores.
    dp[i] = dp[i-2] + dp[i-1]

# dp[] = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
