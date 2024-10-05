# -------------------------------------------------------------------
# DEPTH-FIRST SEARCH/FLOOD FILL - COMPONENTES CONEXOS EM UMA MATRIZ
# -------------------------------------------------------------------

# Quantidade de linhas da matriz de exemplo
L = 10
# Quantidade de colunas da matriz de exemplo
C = 12

# Matriz de exemplo
matriz = [
    ['#','.','.','#','#','#','.','#','#','.','#','#'],
    ['#','#','.','#','#','.','.','.','#','#','#','.'],
    ['.','#','#','.','.','#','.','.','.','.','.','#'],
    ['#','.','.','#','.','.','.','.','#','#','#','#'],
    ['.','#','.','#','.','#','.','.','#','.','.','#'],
    ['.','.','#','#','#','#','#','.','#','.','.','.'],
    ['.','.','#','.','.','#','.','.','#','.','.','#'],
    ['.','.','#','.','.','#','#','#','.','.','.','#'],
    ['.','#','.','#','.','.','.','#','#','.','#','.'],
    ['#','#','.','.','.','.','#','.','.','.','.','.']
]

# Variação de valores da posição i (linha)
vi = (-1,0,1,0)
# Variação de valores da posição j (coluna)
vj = (0,1,0,-1)

# Função recursiva de busca em profundidade
def flood_fill(i: int, j: int) -> None:
    # Alterar o valor da célula
    matriz[i][j] = 'V'

    # Iteração para cada célula adjacente
    # à célula que está sendo visitada
    for k in range(4):
        # Posição i (linha) da célula a ser visitada
        _i = i + vi[k]
        # Posição j (coluna) da célula a ser visitada
        _j = j + vj[k]

        # Se as posições i ou j da célula não estão na matriz
        # (saíram dos limites da matriz, menores que 0)
        if _i < 0 or _j < 0:
            continue

        # Se as posições i ou j da célula não estão na matriz
        # (saíram dos limites da matriz,
        # maiores que o tamanho da matriz)
        if _i >= L or _j >= C:
            continue

        # Se a célula não é um espaço em branco '.'
        if matriz[_i][_j] != '.':
            continue

        # Se qualquer uma das condições acima
        # for verdadeira, a iteração reinicia

        # Chamar a função para a célula adjacente
        flood_fill(_i, _j)

flood_fill(2, 6)

# matriz = [
#     ['#','.','.','#','#','#','V','#','#','.','#','#'],
#     ['#','#','.','#','#','V','V','V','#','#','#','.'],
#     ['.','#','#','V','V','#','V','V','V','V','V','#'],
#     ['#','.','.','#','V','V','V','V','#','#','#','#'],
#     ['.','#','.','#','V','#','V','V','#','.','.','#'],
#     ['.','.','#','#','#','#','#','V','#','.','.','.'],
#     ['.','.','#','.','.','#','V','V','#','.','.','#'],
#     ['.','.','#','.','.','#','#','#','.','.','.','#'],
#     ['.','#','.','#','.','.','.','#','#','.','#','.'],
#     ['#','#','.','.','.','.','#','.','.','.','.','.']
# ]
