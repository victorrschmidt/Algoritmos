# Função para encontrar a posição do número x na lista.
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
            # Retornar a posição m
            return m

        # Se o valor do meio for menor que x
        if v[m] < x:
            # Reduzir o intervalo para [m+1, r]
            l = m + 1
        # Caso contrário
        else:
            # Reduzir o intervalo para [l, m-1]
            r = m - 1

    # Se nenhum valor para m foi retornado, x não está na lista
    return -1
