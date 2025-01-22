# Função para encontrar a posição do primeiro número > x na lista.
# Se nenhum valor satisfazer essa condição, é retornado o número -1.
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
