# --------------------------------------------------------------------------------
# DEPTH FIRST SEARCH E FLOOD FILL - COMPONENTES CONEXOS EM UMA MATRIZ
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

dl = (-1,0,1,0)  # Valores a serem somados na posição Y (linha)
dc = (0,1,0,-1)  # Valores a serem somados na posição X (coluna)

def floodFill(l: int, c: int) -> None:
    matriz[l][c] = 'V'  # Alterar o valor da célula

    for i in range(4):  # Iteração para cada célula adjacente à célula que está sendo visitada
        nova_l = l + dl[i]  # Posição Y (linha) da célula a ser visitada
        nova_c = c + dc[i]  # Posição X (coluna) da célula a ser visitada

        if nova_l < 0 or nova_c < 0:  # Se as posições Y ou X da célula não estão na matriz (saíram dos limites da matriz, menores que 0)
            continue
        if nova_l >= L or nova_c >= C:  # Se as posições Y ou X da célula não estão na matriz (saíram dos limites da matriz, maiores que o tamanho da matriz)
            continue
        if matriz[nova_l][nova_c] != '.':  # Se a célula não é um espaço em branco '.'
            continue

        # Se qualquer uma das condições acima for verdadeira, a iteração reinicia

        floodFill(nova_l, nova_c)  # Chamar a função Flood fill para a célula adjacente

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
