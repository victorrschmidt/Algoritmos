# --------------------------------------------------------------------------------
# DEPTH FIRST SEARCH - COMPONENTES CONEXOS EM UM GRAFO
# --------------------------------------------------------------------------------

V = 12  # Número de vértices do grafo de exemplo

adj = [  # Lista de adjacências do grafo de exemplo
    [5,8,4],  # 0 se liga com 5, 8 e 4
    [7,11],  # 1 se liga com 7 e 11
    [6],  # 2 se liga com 6
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

id = 0  # Define o número do grupo de cada vértice
componente = [None for i in range(V)]  # Lista para identificar o grupo ao qual cada vértice pertence
visitado = [False for i in range(V)]  # Lista de vértices visitados (todos os elementos inicializados como False)

# Função dfs
def dfs(v: int) -> None:
    visitado[v] = True  # O vértice passado na função agora é visitado
    componente[v] = id  # Identificar o id do vértice na lista (o grupo ao qual esse vértice pertence é o id atual)

    for u in adj[v]:  # Iteração para cada vértice adjacente à v
        if not visitado[u]:  # Se o vértice u ainda não foi visitado
            dfs(u)  # Chamar a função dfs para u

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
