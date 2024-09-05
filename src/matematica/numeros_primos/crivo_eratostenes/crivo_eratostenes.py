# --------------------------------------------------------------------------------
# CRIVO DE ERATÓSTENES
# --------------------------------------------------------------------------------

def crivo(n: int) -> list[bool]:
    primos = [True for i in range(n+1)]  # Lista de primos (todos os elementos inicializados como True)

    primos[0] = primos[1] = False  # Casos especiais: 0 e 1 não são números primos

    p = 2

    while p*p <= n:  # Iteração de p no intervalo [2, √n]
        if primos[p]:  # Se o número é primo
            for i in range(p*p, n+1, p):  # Iteração de i (múltiplos de p) no intervalo [p*p, n]
                primos[i] = False  # Definir o número como não primo
        p += 1

    return primos  # Retornar a lista

print(crivo(14))

# [False, False, True, True, False, True, False, True, False, False, False, True, False, True, False]
#    0      1      2     3     4      5     6      7     8      9     10     11    12     13    14
#                primo primo        primo        primo                      primo        primo
