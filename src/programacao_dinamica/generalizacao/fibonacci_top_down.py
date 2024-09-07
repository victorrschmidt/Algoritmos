# --------------------------------------------------------------------------------
# FIBONACCI TOP-DOWN
# --------------------------------------------------------------------------------

dp = [0 for i in range(100)]  # Lista de memorização
ok = [False for i in range(100)]  # Lista para verificar se um estado arbitrário da dp já foi calculado
N = 10  # Limite

# Função recursiva
def fib(n: int) -> int:
    if ok[n]:  # Se o estado n da dp já foi calculado
        return dp[n]  # Retornar o estado n da dp

    ok[n] = True  # Definir o estado n como 'calculado'
    dp[n] = fib(n-2) + fib(n-1)  # Definir o estado n da dp como a soma dos estados n-2 e n-1
    return dp[n]  # Retornar o estado n da dp

dp[1] = 0  # Caso base
ok[1] = True
dp[2] = 1  # Caso base
ok[2] = True

fib(N)  # Chamar a função para o último estado da dp (limite)

# dp[1...N] = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
