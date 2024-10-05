# -------------------------------------------------------------------
# FIBONACCI TOP-DOWN
# -------------------------------------------------------------------

# Limite arbitrário de exemplo
N = 10

# Lista de memorização
dp = [0 for i in range(N+1)]

# Lista para verificar se um estado
# arbitrário da dp já foi calculado
calculado = [False for i in range(N+1)]

# Função recursiva para calcular os números de fibonacci de 1 até n
def fib(n: int) -> int:
    # Se o estado n da dp já foi calculado
    if calculado[n]:
        # Retornar o estado n da dp
        return dp[n]

    # Definir o estado n da dp como a soma dos estados n-2 e n-1
    dp[n] = fib(n-2) + fib(n-1)

    # Definir o estado n como 'calculado'
    calculado[n] = True

    # Retornar o estado n da dp
    return dp[n]

dp[1] = 0  # Caso base => fib(1) = 0
dp[2] = 1  # Caso base => fib(2) = 1
calculado[1] = True
calculado[2] = True

# Chamar a função para o último estado da dp (limite)
fib(N)

# dp[1...N] = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
