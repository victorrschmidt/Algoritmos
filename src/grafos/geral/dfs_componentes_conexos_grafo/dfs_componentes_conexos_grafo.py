# --------------------------------------------------------------------------------
# DEPTH FIRST SEARCH - COMPONENTES CONEXOS EM UM GRAFO
# --------------------------------------------------------------------------------

'''
Complexidade: O(V+E)

- Onde V e E são, respectivamente, a quantidade de vértices e arestas do grafo.

A ideia do algoritmo é visitar um vértice adjacente ao vértice de origem, 
depois visitar um vértice adjacente a esse e assim sucessivamente, fazendo
uma busca em profundidade até chegarmos em um "beco sem saída". Quando não
houver mais vértices para visitar, iremos voltar ao vértice que estava sendo 
visitado anteriormente (backtracking) e procurar outro vértice para visitar.

O algoritmo utiliza recursividade, onde a função chama a si mesma conforme
visitamos outros vértices, colocando as chamadas mais antigas em uma prioridade
menor, priorizando as chamadas mais recentes.

Quando todos os vértices possíveis forem visitados dessa forma, podemos afirmar 
que todos pertencem ao mesmo grupo, pois conseguimos chegar até eles de alguma 
forma a partir do vértice de origem. Para determinar quais são os vértices que 
pertencem a esse grupo, temos uma lista de inteiros componente[] de tamanho V, 
onde para cada visita iremos armazenar o número do grupo do vértice v em componente[v].

Para grafos desconexos temos mais de um grupo e, caso nem todos os vértices
tenham sido visitados, iniciaremos outra busca em profundidade a partir do primeiro
vértice não visitado na ordem (considerando que os vértices são numerados de 0 até V-1),
assim determinando o grupo ao qual todos os vértices do grafo pertencem.

O grafo utilizado de exemplo está no mesmo diretório deste arquivo.
'''

VERT = 12  # Número de vértices do grafo de exemplo

grafo = [  # Lista de adjacências do grafo de exemplo
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
componente = [None for i in range(VERT)]  # Lista para identificar o grupo ao qual cada vértice pertence
visitado = [False for i in range(VERT)]  # Lista de vértices visitados (todos os elementos inicializados como 'False')

# Função dfs
def dfs(v):
    visitado[v] = True  # O vértice passado na função agora é visitado
    componente[v] = id  # Identificar o id do vértice na lista (o grupo ao qual esse vértice pertence é o id atual)

    for u in grafo[v]:  # Iteração para cada vértice adjacente à 'v'
        if not visitado[u]:  # Se o vértice 'u' não foi visitado
            dfs(u)  # Chamar a função dfs para 'u'
        
# Função para identificar os vértices
def encontrarComponentes():
    for i in range(VERT):  # Iteração para cada vértice no grafo
        if not visitado[i]:  # Se o vértice não foi visitado
            global id  # Python moment
            id += 1  # Aumentar o id (número de grupos)
            dfs(i)  # Chamar a função dfs para esse vértice
        
encontrarComponentes()

# componente = [1, 2, 3, 4, 1, 1, 3, 2, 1, 3, 3, 2]
# id = 4 (4 grupos)