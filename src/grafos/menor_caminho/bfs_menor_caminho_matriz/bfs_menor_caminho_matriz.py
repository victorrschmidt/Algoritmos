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

pos_l = 0  # Posição inicial Y (linha)
pos_c = 0  # Posição inicial X (coluna)

def bfs() -> int:
    dl = (-1,0,1,0)  # Valores a serem somados na posição Y (linha)
    dc = (0,1,0,-1)  # Valores a serem somados na posição X (coluna)

    visitado = [[False for i in range(C)] for j in range(L)]  # Matriz de células visitadas (todas as células inicializadas como False)
    visitado[pos_l][pos_c] = True  # Definir a célula inicial como visitada

    fila = deque()  # Fila para verificar cada célula adjacente na matriz
    fila.append([pos_l, pos_c])  # Adicionar a célula inicial na fila ( [eixo X, eixo Y] )

    c_restantes = 1  # Células restantes na camada de busca (inicialmente só com a célula inicial). Será utilizado para determinar o número de células em cada camada de busca
    distancia = 0  # Contador de distância até a célula final

    while fila:  # Iteração para cada célula na fila
        l, c = fila.popleft()  # Pegar a posição Y (linha) da célula e a posição X (coluna) da célula
        # Remover a célula da fila

        if matriz[l][c] == 'F':  # Se essa célula é a célula final
            return distancia  # Retornar a distância entre a célula inicial e final

        for i in range(4):  # Iteração para cada célula adjacente à célula que está sendo visitada
            nova_l = l + dl[i]  # Posição Y (linha) da célula a ser visitada
            nova_c = c + dc[i]  # Posição X (coluna) da célula a ser visitada

            if nova_l < 0 or nova_c < 0:  # Se as posições Y ou X da célula não estão na matriz (saíram dos limites da matriz, menores que 0)
                continue
            if nova_l >= L or nova_c >= C:  # Se as posições Y ou X da célula não estão na matriz (saíram dos limites da matriz, maiores que o tamanho da matriz)
                continue
            if visitado[nova_l][nova_c]:  # Se a célula já foi visitada
                continue
            if matriz[nova_l][nova_c] == '#':  # Se a célula é inacessível (pedra)
                continue

            # Se qualquer uma das condições acima for verdadeira, a iteração reinicia

            fila.append([nova_l, nova_c])  # Adicionar a célula à fila
            visitado[nova_l][nova_c] = True  # Agora visitamos essa célula

        c_restantes -= 1  # Diminuir o número de células na camada de busca

        if c_restantes == 0:  # Se foram verificadas todas as células nessa camada de busca
            c_restantes = len(fila)  # A próxima camada de busca tem todas as células na próxima camada (tamanho atual da fila)
            distancia += 1  # Como teremos que verificar outra camada de busca, a distância aumenta em 1

    return -1  # Não existe caminho possível entre a célula inicial e final

print(bfs())  # 11
