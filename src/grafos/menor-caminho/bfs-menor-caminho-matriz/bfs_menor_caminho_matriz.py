# -------------------------------------------------------------------
# BREADTH-FIRST SEARCH - MENOR CAMINHO EM UMA MATRIZ
# -------------------------------------------------------------------

from collections import deque

# Quantidade de linhas da matriz de exemplo
L = 6
# Quantidade de colunas da matriz de exemplo
C = 8

# Matriz de exemplo
matriz = [
    ['C','.','#','.','.','.','.','#'],
    ['.','.','.','.','#','#','#','.'],
    ['.','#','.','.','.','#','.','.'],
    ['#','.','.','#','.','#','F','#'],
    ['.','.','#','#','.','.','.','.'],
    ['#','.','.','.','.','.','.','#']
]

# Posição inicial i (linha)
ic = 0
# Posição inicial j (coluna)
jc = 0

def bfs() -> int:
    # Variação de valores da posição i (linha)
    vi = (-1,0,1,0)
    # Variação de valores da posição j (coluna)
    vj = (0,1,0,-1)

    # Matriz de células visitadas
    # (todas as células inicializadas como False).
    visitado = [[False for i in range(C)] for j in range(L)]
    # Definir a célula inicial como 'visitada'
    visitado[ic][jc] = True

    # Fila para verificar cada célula adjacente na matriz
    fila = deque()
    # Adicionar a célula inicial na fila ( (i, j) )
    fila.append((ic, jc))

    # Células restantes na camada de busca
    # (inicialmente só com a célula inicial).
    # Será utilizado para determinar o número
    # de células em cada camada de busca.
    c_restantes = 1

    # Contador de distância até a célula final
    distancia = 0

    # Iteração para cada célula na fila
    while fila:
        # Pegar a posição i (linha) e a posição j (coluna)
        # da célula e removê-las da fila.
        i, j = fila.popleft()

        # Se essa célula é a célula final
        if matriz[i][j] == 'F':
            # Retornar a distância
            return distancia

        # Iteração para cada célula adjacente à
        # célula que está sendo visitada
        for k in range(4):
            # Posição i (linha) da célula a ser visitada
            _i = i + vi[k]
            # Posição j (coluna) da célula a ser visitada
            _j = j + vj[k]

            # Se as posições i ou j da célula não estão na matriz
            # (saíram dos limites da matriz, menores que 0).
            if _i < 0 or _j < 0:
                continue

            # Se as posições i ou j da célula não estão na matriz
            # (saíram dos limites da matriz,
            # maiores que o tamanho da matriz).
            if _i >= L or _j >= C:
                continue

            # Se a célula já foi visitada
            if visitado[_i][_j]:
                continue

            # Se a célula é inacessível (pedra)
            if matriz[_i][_j] == '#':
                continue

            # Se qualquer uma das condições acima
            # for verdadeira, a iteração reinicia.

            # Adicionar a célula à fila
            fila.append((_i, _j))
            # Definir a célula como visitada
            visitado[_i][_j] = True

        # Diminuir o número de células na camada de busca
        c_restantes -= 1

        # Se foram verificadas todas as
        # células nessa camada de busca
        if c_restantes == 0:
            # A próxima camada de busca tem todas as
            # células na próxima camada (tamanho atual da fila).
            c_restantes = len(fila)

            # Como teremos que processar outra
            # camada de busca, a distância aumenta em 1.
            distancia += 1

    # Se nenhum valor de distância foi retornado,
    # não existe caminho possível entre a célula inicial e final.
    return -1

print(bfs())  # 11
