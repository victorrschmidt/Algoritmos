# --------------------------------------------------------------------------------
# BUSCA BINÁRIA
# --------------------------------------------------------------------------------

v = [1, 4, 8, 8, 9, 11, 11, 12]

# Posição do número x na lista, ou -1 (caso x não estiver na lista)
# Obs: Se x aparecer mais de uma vez na lista, a posição irá variar de acordo com o tamanho da mesma
def busca_binaria(x: int) -> int:
    l = 0
    r = len(v) - 1

    while l <= r:
        m = (l + r) // 2

        if v[m] == x:
            return m
        if v[m] < x:
            l = m + 1
        else:
            r = m - 1

    return -1

# Posição do primeiro número >= x na lista, ou -1 (caso nenhum número na lista satisfazer essa condição)
def lower_bound(x: int) -> int:
    l = 0
    r = len(v) - 1
    pos = -1

    while l <= r:
        m = (l + r) // 2

        if v[m] >= x:
            pos = m
            r = m - 1
        else:
            l = m + 1

    return pos

# Posição do primeiro número > x na lista, ou -1 (caso nenhum número na lista satisfazer essa condição)
def upper_bound(x: int) -> int:
    l = 0
    r = len(v) - 1
    pos = -1

    while l <= r:
        m = (l + r) // 2

        if v[m] > x:
            pos = m
            r = m - 1
        else:
            l = m + 1

    return pos

print(busca_binaria(9))  # 4
print(busca_binaria(7))  # -1
print(lower_bound(8))  # 2
print(lower_bound(3))  # 1
print(upper_bound(15))  # -1
print(upper_bound(4))  # 2
