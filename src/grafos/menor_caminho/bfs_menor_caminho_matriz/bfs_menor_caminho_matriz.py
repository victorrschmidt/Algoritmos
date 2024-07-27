# --------------------------------------------------------------------------------
# BREADTH FIRST SEARCH - MENOR CAMINHO EM UMA MATRIZ
# --------------------------------------------------------------------------------

from collections import deque

L = 6  # Quantidade de linhas da matriz de exemplo
C = 8  # Quantidade de colunas da matriz de exemplo

matriz = [  # Matriz de exemplo
    ['C','.','#','.','.','.','.','#'],
    ['.','.','.','.','#','#','#','.'],
    ['.','#','.','.','.','#','.','.'],
    ['#','.','.','#','.','#','F','#'],
    ['.','.','#','#','.','.','.','.'],
    ['#','.','.','.','.','.','.','#']
]

i0 = 0  # Posição inicial i (linha)
j0 = 0  # Posição inicial j (coluna)

def bfs() -> int:
    vi = (-1,0,1,0)  # Variação de valores da posição i (linha)
    jv = (0,1,0,-1)  # Variação de valores da posição j (coluna)

    visitado = [[False for i in range(C)] for j in range(L)]  # Matriz de células visitadas (todas as células inicializadas como False)
    visitado[i0][j0] = True  # Definir a célula inicial como visitada

    fila = deque()  # Fila para verificar cada célula adjacente na matriz
    fila.append((i0, j0))  # Adicionar a célula inicial na fila ( (i, j) )

    c_restantes = 1  # Células restantes na camada de busca (inicialmente só com a célula inicial). Será utilizado para determinar o número de células em cada camada de busca
    distancia = 0  # Contador de distância até a célula final

    while fila:  # Iteração para cada célula na fila
        i, j = fila.popleft()  # Pegar a posição i (linha) da célula e a posição j (coluna) da célula
        # Remover a célula da fila

        if matriz[i][j] == 'F':  # Se essa célula é a célula final
            return distancia  # Retornar a distância

        for k in range(4):  # Iteração para cada célula adjacente à célula que está sendo visitada
            iv = i + vi[k]  # Posição i (linha) da célula a ser visitada
            jv = j + vj[k]  # Posição j (coluna) da célula a ser visitada

            if iv < 0 or jv < 0:  # Se as posições i ou j da célula não estão na matriz (saíram dos limites da matriz, menores que 0)
                continue
            if iv >= L or jv >= C:  # Se as posições i ou j da célula não estão na matriz (saíram dos limites da matriz, maiores que o tamanho da matriz)
                continue
            if visitado[iv][jv]:  # Se a célula já foi visitada
                continue
            if matriz[iv][jv] == '#':  # Se a célula é inacessível (pedra)
                continue

            # Se qualquer uma das condições acima for verdadeira, a iteração reinicia

            fila.append((iv, jv))  # Adicionar a célula à fila
            visitado[iv][jv] = True  # Agora visitamos essa célula

        c_restantes -= 1  # Diminuir o número de células na camada de busca

        if c_restantes == 0:  # Se foram verificadas todas as células nessa camada de busca
            c_restantes = len(fila)  # A próxima camada de busca tem todas as células na próxima camada (tamanho atual da fila)
            distancia += 1  # Como teremos que verificar outra camada de busca, a distância aumenta em 1

    return -1  # Não existe caminho possível entre a célula inicial e final

print(bfs())  # 11
