# --------------------------------------------------------------------------------
# FIBONACCI BOTTOM-UP
# --------------------------------------------------------------------------------

dp = [0 for i in range(100)]  # Lista de tabulação
N = 10  # Limite

dp[1] = 0  # Caso base
dp[2] = 1  # Caso base

for i in range(3, N+1):  # Iteração para cada estado da dp (com exceção dos casos base)
    dp[i] = dp[i-2] + dp[i-1]  # O i-ésimo número de fibonacci é a soma dos dois anteriores

# dp[1...N] = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
