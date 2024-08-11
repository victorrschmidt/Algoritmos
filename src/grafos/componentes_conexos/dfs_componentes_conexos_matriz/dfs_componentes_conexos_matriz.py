# --------------------------------------------------------------------------------
# DEPTH-FIRST SEARCH/FLOOD FILL - COMPONENTES CONEXOS EM UMA MATRIZ
# --------------------------------------------------------------------------------

L = 10  # Quantidade de linhas da matriz de exemplo
C = 12  # Quantidade de colunas da matriz de exemplo

matriz = [  # Matriz de exemplo
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

vi = (-1,0,1,0)  # Variação de valores da posição i (linha)
vj = (0,1,0,-1)  # Variação de valores da posição j (coluna)

def floodFill(i: int, j: int) -> None:
    matriz[i][j] = 'V'  # Alterar o valor da célula

    for k in range(4):  # Iteração para cada célula adjacente à célula que está sendo visitada
        i_ = i + vi[k]  # Posição i (linha) da célula a ser visitada
        j_ = j + vj[k]  # Posição j (coluna) da célula a ser visitada

        if i_ < 0 or j_ < 0:  # Se as posições i ou j da célula não estão na matriz (saíram dos limites da matriz, menores que 0)
            continue
        if i_ >= L or j_ >= C:  # Se as posições i ou j da célula não estão na matriz (saíram dos limites da matriz, maiores que o tamanho da matriz)
            continue
        if matriz[i_][j_] != '.':  # Se a célula não é um espaço em branco '.'
            continue

        # Se qualquer uma das condições acima for verdadeira, a iteração reinicia

        floodFill(i_, j_)  # Chamar a função Flood fill para a célula adjacente

floodFill(2, 6)

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
