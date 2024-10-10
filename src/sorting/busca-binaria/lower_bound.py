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
