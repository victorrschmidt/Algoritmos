# -------------------------------------------------------------------
# BREADTH-FIRST SEARCH - MENOR CAMINHO EM UM GRAFO NÃO VALORADO
# -------------------------------------------------------------------

from collections import deque

# Número de vértices do grafo de exemplo
V = 13

# Lista de adjacências do grafo de exemplo
adj = [
    [6,7],  # 0->6, 0->7
    [7,4,12],  # 1->7, 1->4, 1->12
    [3,6,8],  # 2->3, 2->6, 2->8
    [5,6,2],  # ...
    [1,8],
    [3],
    [0,3,2],
    [0,1],
    [2,9,4],
    [8,10],
    [9,11],
    [10,12],
    [1,11]
]

# Função para calcular a distância entre o vértice
# 'origem' e os outros vértices do grafo
def bfs(origem: int) -> None:
    # Array para armazenar a distância entre
    # o vértice de origem e os outros vértices
    global dist
    # Definir a distância até os outros vértices como -1
    dist = [-1 for i in range(V)]

    # A distância entre a origem e a própria origem é 0
    dist[origem] = 0

    # Lista de vértices visitados
    # (todos os elementos inicializados como False)
    visitado = [False for i in range(V)]
    # Definir o vértice de origem como 'visitado'
    visitado[origem] = True

    # Fila para armazenar as adjacências de cada vértice processado
    fila = deque()
    # Adicionar o vértice de origem à fila
    fila.append(origem)

    # Iteração para cada vértice na fila
    while fila:
        # Pegar o último vértice e removê-lo da fila
        u = fila.popleft()

        # Iteração para cada vértice adjacente à u
        for v in adj[u]:
            # Se o vértice v ainda não foi visitado
            if not visitado[v]:
                # Definir o vértice como 'visitado'
                visitado[v] = True

                # Adicioná-lo à fila
                fila.append(v)

                # Definir a distância até esse vértice
                # (distância até o vértice u + 1)
                dist[v] = dist[u] + 1

bfs(0)
# dist = [0, 2, 2, 2, 3, 3, 1, 1, 3, 4, 5, 4, 3]

bfs(5)
# dist = [3, 5, 2, 1, 4, 0, 2, 4, 3, 4, 5, 6, 6]

bfs(8)
# dist = [3, 2, 1, 2, 1, 3, 2, 3, 0, 1, 2, 3, 3]
