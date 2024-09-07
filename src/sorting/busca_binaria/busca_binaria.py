# --------------------------------------------------------------------------------
# BUSCA BINÁRIA
# --------------------------------------------------------------------------------

v = [1, 4, 8, 8, 9, 11, 11, 12]  # Lista de exemplo

# Posição do número x na lista, ou -1 (caso x não estiver na lista)
# Obs: Se x aparecer mais de uma vez na lista, a posição irá variar de acordo com o tamanho da mesma
def busca_binaria(x: int) -> int:
    l = 0  # Primeira posição da lista
    r = len(v) - 1  # Última posição da lista

    while l <= r:  # Iteração no intervalo
        m = (l + r) // 2

        if v[m] == x:  # Se o valor for igual a x
            return m  # Retornar m
        if v[m] < x:  # Se o valor for menor que x
            l = m + 1  # Reduzir o intervalo para [m+1, r]
        else:  # Caso contrário
            r = m - 1  # Reduzir o intervalo para [l, m-1]

    return -1  # x não está na lista

# Posição do primeiro número >= x na lista, ou -1 (caso nenhum número na lista satisfazer essa condição)
def lower_bound(x: int) -> int:
    l = 0  # Primeira posição da lista
    r = len(v) - 1  # Última posição da lista
    pos = -1  # Posição do lower bound

    while l <= r:  # Iteração no intervalo
        m = (l + r) // 2

        if v[m] >= x:  # Se o valor for maior ou igual a x
            pos = m  # Atualizar a posição do lower bound
            r = m - 1  # Reduzir o intervalo para [l, m-1]
        else:  # Caso contrário
            l = m + 1  # Reduzir o intervalo para [m+1, r]

    return pos  # Retornar a posição do lower bound (-1 indica que não existe um lower bound de x na lista)

# Posição do primeiro número > x na lista, ou -1 (caso nenhum número na lista satisfazer essa condição)
def upper_bound(x: int) -> int:
    l = 0  # Primeira posição da lista
    r = len(v) - 1  # Última posição da lista
    pos = -1  # Posição do upper bound

    while l <= r:  # Iteração no intervalo
        m = (l + r) // 2

        if v[m] > x:  # Se o valor for maior que x
            pos = m  # Atualizar a posição do upper bound
            r = m - 1  # Reduzir o intervalo para [l, m-1]
        else:  # Caso contrário
            l = m + 1  # Reduzir o intervalo para [m+1, r]

    return pos  # Retornar a posição do upper bound (-1 indica que não existe um upper bound de x na lista)

print(busca_binaria(9))  # 4
print(busca_binaria(7))  # -1
print(lower_bound(8))  # 2
print(lower_bound(3))  # 1
print(upper_bound(15))  # -1
print(upper_bound(4))  # 2
