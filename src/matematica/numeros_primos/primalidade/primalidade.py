# -------------------------------------------------------------------
# PRIMALIDADE
# -------------------------------------------------------------------

# Função para verificar se um número n é primo
def primo(n: int) -> bool:
    # Caso especial: um número para
    # ser primo precisa ser maior que 1.
    if n < 2:
        return False

    # Iteração de i no intervalo [2, √n]
    i = 2
    while i*i <= n:
        # Se n é divisível por i
        if n % i == 0:
            # n não é primo
            return False
        i += 1

    # Se n não é múltiplo de nenhum número
    # no intervalo [2, √n], n é primo.
    return True
