# --------------------------------------------------------------------------------
# BREADTH FIRST SEARCH - MENOR CAMINHO EM UM GRAFO NÃO VALORADO
# --------------------------------------------------------------------------------

# Complexidade: O(V+E)
#
# - Onde V e E são, respectivamente, a quantidade de vértices e arestas do grafo.

# A ideia do algoritmo é visitar todos os vértices adjacentes ao vértice de origem,
# depois visitar todos os vértices adjacentes a esses e assim sucessivamente.
# Cada camada de busca corresponde a um movimento - a distância mínima possível
# entre o vértice que está sendo visitado e o vértice de origem.

# Assim, é possível determinar a menor distância entre o vértice de origem e 
# todos os outros vértices do grafo (considerando que cada aresta tem peso 1). 
# A distância do vértice de origem até cada um dos vértices será armazenada 
# na lista dist[]. Como inicialmente não sabemos a distância até cada vértice,
# iremos definir todas as distâncias como -1. Conforme fazemos a travessia 
# no grafo, armazenamos a distância até o vértice u em dist[u] (onde u é o número do vértice).

# No final, teremos a lista definida com todas as distâncias e, as distâncias 
# que estiverem ainda como -1 indicam que aquele vértice não é conexo 
# com o vértice de origem. Assim, podemos verificar a menor distância entre 
# o vértice de origem e qualquer outro vértice do grafo.

# O grafo utilizado de exemplo está no mesmo diretório deste arquivo.


VERT = 13  # Número de vértices do grafo de exemplo

grafo = [  # Lista de adjacências do grafo de exemplo
    [6,7],  # 0 se liga com 6 e 7
    [7,4,12],  # 1 se liga com 7, 4 e 12
    [3,6,8],  # 2 se liga com 3, 6 e 8
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

# Função bfs
def bfs(origem):
    global dist  # Lista para armazenar a distância do vértice de origem até os outros vértices
    dist = [-1 for i in range(VERT)]  # Definimos a distância até os outros vértices como -1
    dist[origem] = 0  # A distância da origem até a própria origem é 0

    visitado = [False for i in range(VERT)]  # Lista de vértices visitados (todos os elementos inicializados como 'False')
    visitado[origem] = True  # Definir o vértice de origem como 'visitado'

    fila = []  # Fila para verificar as adjacências de cada vértice explorado
    fila.append(origem)  # Adicionar o vértice de origem à fila

    v_restantes = 1  # Vértices restantes na camada de busca (inicialmente só com o vértice de origem). Será utilizado para determinar o número de vértices em cada camada de busca
    distancia = 1  # Distância até os outros vértices, inicialmente 1 (1° camada de busca)

    while len(fila):  # Iteração para cada vértice na fila
        v = fila[0]  # Pegar o último vértice
        fila.pop(0)  # Removê-lo da fila

        for u in grafo[v]:  # Iteração para cada vértice adjacente à 'v'
            if not visitado[u]:  # Se o vértice u não foi visitado
                visitado[u] = True  # Agora visitamos esse vértice
                fila.append(u)  # Adicioná-lo à fila
                dist[u] = distancia  # Definir a distância até esse vértice
            
        
        v_restantes -= 1  # Diminuir o número de vértices na camada de busca
        
        if v_restantes == 0:  # Se foram analisados todos os vértices nessa camada de busca
            v_restantes = len(fila)  # A próxima camada de busca tem todos os vértices na próxima camada (tamanho atual da fila)
            distancia += 1  # Como teremos que analisar outra camada de busca, a distância aumenta em 1
        


bfs(0)  # dist = [0, 2, 2, 2, 3, 3, 1, 1, 3, 4, 5, 4, 3]

bfs(5)  # dist = [3, 5, 2, 1, 4, 0, 2, 4, 3, 4, 5, 6, 6]

bfs(8)  # dist = [3, 2, 1, 2, 1, 3, 2, 3, 0, 1, 2, 3, 3]