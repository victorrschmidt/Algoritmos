# --------------------------------------------------------------------------------
# DEPTH-FIRST SEARCH - COMPONENTES CONEXOS EM UM GRAFO
# --------------------------------------------------------------------------------

V = 12  # Número de vértices do grafo de exemplo

adj = [  # Lista de adjacências do grafo de exemplo
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

id = 0  # Número que define o número do grupo de cada vértice
componente = [None for i in range(V)]  # Lista para identificar o grupo ao qual cada vértice pertence
visitado = [False for i in range(V)]  # Lista de vértices visitados (todos os elementos inicializados como False)

# Função dfs
def dfs(u: int) -> None:
    visitado[u] = True  # Definir o vértice u como 'visitado'
    componente[u] = id  # Identificar o id do vértice na lista (o grupo ao qual esse vértice pertence é o id atual)

    for v in adj[u]:  # Iteração para cada vértice adjacente à u
        if not visitado[v]:  # Se o vértice v ainda não foi visitado
            dfs(v)  # Chamar a função dfs para v

# Função para identificar os vértices
def encontrarComponentes() -> None:
    for i in range(V):  # Iteração para cada vértice no grafo
        if not visitado[i]:  # Se o vértice ainda não foi visitado
            global id
            id += 1  # Aumentar o id (número de grupos)
            dfs(i)  # Chamar a função dfs para esse vértice

encontrarComponentes()

# componente = [1, 2, 3, 4, 1, 1, 3, 2, 1, 3, 3, 2]
# id = 4 (4 grupos)
