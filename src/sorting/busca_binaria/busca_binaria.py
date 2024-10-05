# -------------------------------------------------------------------
# BUSCA BINÁRIA
# -------------------------------------------------------------------

# Função para calcular a posição do número x na lista.
# Se o número x não estiver presente, é retornado o número -1.
# Obs: Se x aparecer mais de uma vez na lista,
# a posição irá variar de acordo com o tamanho da mesma.
def busca_binaria(v: list[int], x: int) -> int:
    # Primeira posição da lista
    l = 0
    # Última posição da lista
    r = len(v) - 1

    # Iteração no intervalo [l, r] atual
    while l <= r:
        # Posição do meio do intervalo
        m = (l + r) // 2

        # Se o valor do meio for igual a x
        if v[m] == x:
            # Retornar m
            return m

        # Se o valor do meio for menor que x
        if v[m] < x:
            # Reduzir o intervalo para [m+1, r]
            l = m + 1
        # Caso contrário
        else:
            # Reduzir o intervalo para [l, m-1]
            r = m - 1

    # Se um valor para m não foi retornado, x não está na lista
    return -1

# Função para calcular a posição do primeiro número >= x na lista.
# Se o número x não estiver presente, é retornado o número -1.
def lower_bound(v: list[int], x: int) -> int:
    # Primeira posição da lista
    l = 0
    # Última posição da lista
    r = len(v) - 1

    # Posição do lower bound, inicialmente não encontrada,
    # portanto inicializada como o número -1.
    pos = -1

    # Iteração no intervalo [l, r] atual
    while l <= r:
        # Posição do meio do intervalo
        m = (l + r) // 2

        # Se o valor do meio for maior ou igual a x
        if v[m] >= x:
            # Atualizar a posição do lower bound
            pos = m
            # Reduzir o intervalo para [l, m-1]
            r = m - 1
        # Caso contrário
        else:
            # Reduzir o intervalo para [m+1, r]
            l = m + 1

    # Retornar a posição do lower bound
    return pos

# Função para calcular a posição do primeiro número > x na lista.
# Se o número x não estiver presente, é retornado o número -1.
def upper_bound(v: list[int], x: int) -> int:
    # Primeira posição da lista
    l = 0
    # Última posição da lista
    r = len(v) - 1

    # Posição do upper bound, inicialmente não encontrada,
    # portanto inicializada como o número -1.
    pos = -1

    # Iteração no intervalo [l, r] atual
    while l <= r:
        # Posição do meio do intervalo
        m = (l + r) // 2

        # Se o valor do meio for maior que x
        if v[m] > x:
            # Atualizar a posição do upper bound
            pos = m
            # Reduzir o intervalo para [l, m-1]
            r = m - 1
        # Caso contrário
        else:
            # Reduzir o intervalo para [m+1, r]
            l = m + 1

    # Retornar a posição do upper bound
    return pos
