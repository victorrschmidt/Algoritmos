# -------------------------------------------------------------------
# DEPTH-FIRST SEARCH - COMPONENTES CONEXOS EM UM GRAFO
# -------------------------------------------------------------------

# Número de vértices do grafo de exemplo
V = 12

# Lista de adjacências do grafo de exemplo
adj = [
    [5,8,4],  # 0->5, 0->8, 0->4
    [7,11],  # 1->7, 1->11
    [6],  # 2->6
    [],  # ...
    [0,8],
    [0],
    [2,9],
    [1,11],
    [0,4],
    [10,6],
    [9],
    [1,7]
]

# Contador que define o número do grupo de cada vértice
id = 0

# Lista para identificar o grupo ao qual cada vértice pertence
componente = [-1 for i in range(V)]

# Lista de vértices visitados
# (todos os elementos inicializados como False)
visitado = [False for i in range(V)]

# Função recursiva de busca em profundidade
def dfs(u: int) -> None:
    # Definir o vértice u como 'visitado'
    visitado[u] = True

    # Identificar o id do vértice na lista.
    # O grupo ao qual esse vértice pertence é o id atual.
    componente[u] = id

    # Iteração para cada vértice adjacente à u
    for v in adj[u]:
        # Se o vértice v ainda não foi visitado
        if not visitado[v]:
            # Chamar a função dfs para v
            dfs(v)

# Função para identificar cada um dos vértices do grafo
def encontrar_componentes() -> None:
    # Iteração para cada vértice no grafo
    for i in range(V):
        # Se o vértice i ainda não foi visitado
        if not visitado[i]:
            # Chamar a função dfs para i
            dfs(i)

            # Incrementar o id (número de grupos).
            # Todos os vértices conexos à i já foram
            # visitados/processados
            global id
            id += 1


encontrar_componentes()

# componente = [0, 1, 2, 3, 0, 0, 2, 1, 0, 2, 2, 1]
# id = 4 = n° de componentes conexos no grafo
