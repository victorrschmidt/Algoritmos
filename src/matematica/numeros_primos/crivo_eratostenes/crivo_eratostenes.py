# -------------------------------------------------------------------
# CRIVO DE ERATÓSTENES
# -------------------------------------------------------------------

# Função para gerar a lista de primos de 0 até n
def crivo(n: int) -> list[bool]:
    # Lista de números (todos os elementos inicializados como True).
    # Cada posição p é um valor booleano que determina se o número
    # p é primo (True) ou não (False).
    primos = [True for i in range(n+1)]

    # Casos especiais: 0 e 1 não são números primos
    primos[0] = primos[1] = False

    # Iteração de p no intervalo [2, √n]
    p = 2
    while p*p <= n:
        # Se p é primo
        if primos[p]:
            # Iteração de i (múltiplos de p) no intervalo [p*p, n]
            for i in range(p*p, n+1, p):
                # Definir i como não primo
                primos[i] = False
        p += 1

    # Retornar a lista
    return primos
