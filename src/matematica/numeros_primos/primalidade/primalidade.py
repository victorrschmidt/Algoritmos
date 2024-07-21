# --------------------------------------------------------------------------------
# PRIMALIDADE
# --------------------------------------------------------------------------------

def primo(n: int) -> bool:
    if n < 2:  # Caso especial: um número para ser primo precisa ser maior que 1
        return False

    i = 2

    while i*i <= n:  # Iteração para cada número no intervalo [2, √n]
        if n % i == 0:  # Se n é divisível por i
            return False  # O número não é primo
        i += 1

    return True  # O número é primo
