// --------------------------------------------------------------------------------
// BREADTH FIRST SEARCH - MENOR CAMINHO EM UM GRAFO NÃO VALORADO
// --------------------------------------------------------------------------------

/*
Complexidade: O(v+e)

- Onde v e 'e' são, respectivamente, a quantidade de vértices e arestas do grafo.

A ideia do algoritmo é visitar todos os vértices adjacentes ao vértice de origem,
depois visitar todos os vértices adjacentes a esses e assim sucessivamente.
Cada camada de busca corresponde a um movimento - a distância mínima possível
entre o vértice que está sendo visitado e o vértice de origem.

Assim, é possível determinar a menor distância entre o vértice de origem e 
todos os outros vértices do grafo (considerando que cada aresta tem peso 1). 
A distância do vértice de origem até cada um dos vértices será armazenada 
no array dist[]. Como inicialmente não sabemos a distância até cada vértice,
iremos definir todas as distâncias como -1. Conforme fazemos a travessia 
no grafo, armazenamos a distância até o vértice u em dist[u] (onde u é o número do vértice).

No final, teremos o array definido com todas as distâncias e, as distâncias 
que estiverem ainda como -1 indicam que aquele vértice não é conexo 
com o vértice de origem. Assim, podemos verificar a menor distância entre 
o vértice de origem e qualquer outro vértice do grafo em tempo constante.

O grafo utilizado de exemplo está no mesmo diretório deste arquivo.
*/

const VERT = 13;  // Número de vértices do grafo de exemplo

let grafo = [  // Lista de adjacências do grafo de exemplo
    [6,7],  // 0 se liga com 6 e 7
    [7,4,12],  // 1 se liga com 7, 4 e 12
    [3,6,8],  // 2 se liga com 3, 6 e 8
    [5,6,2],  // ...
    [1,8],
    [3],
    [0,3,2],
    [0,1],
    [2,9,4],
    [8,10],
    [9,11],
    [10,12],
    [1,11]
];

let dist = Array(VERT);  // Array para armazenar a distância do vértice de origem até os outros vértices

// Função bfs
function bfs(origem) {
    dist.fill(-1);  // Definimos a distância até os outros vértices como -1
    dist[origem] = 0;  // A distância da origem até a própria origem é 0

    let visitado = Array(VERT).fill(false);  // Array de vértices visitados (todos os elementos inicializados como 'false')
    visitado[origem] = true;  // Definir o vértice de origem como 'visitado'

    let fila = [];  // Fila para verificar as adjacências de cada vértice explorado
    fila.push(origem);  // Adicionar o vértice de origem à fila

    let v_restantes = 1;  // Vértices restantes na camada de busca (inicialmente só com o vértice de origem). Será utilizado para determinar o número de vértices em cada camada de busca
    let distancia = 1;  // Distância até os outros vértices, inicialmente 1 (1° camada de busca)

    while (fila.length) {  // Iteração para cada vértice na fila
        let v = fila.shift();  // Pegar o último vértice e removê-lo da fila

        for (const u of grafo[v]) {  // Iteração para cada vértice adjacente à 'v'
            if (!visitado[u]) {  // Se o vértice u não foi visitado
                visitado[u] = true;  // Agora visitamos esse vértice
                fila.push(u);  // Adicioná-lo à fila
                dist[u] = distancia;  // Definir a distância até esse vértice
            }
        }

        v_restantes--;  // Diminuir o número de vértices na camada de busca
        
        if (v_restantes == 0) {  // Se foram analisados todos os vértices nessa camada de busca
            v_restantes = fila.length;  // A próxima camada de busca tem todos os vértices na próxima camada (tamanho atual da fila)
            distancia++;  // Como teremos que analisar outra camada de busca, a distância aumenta em 1
        }

    }

}

bfs(0);  // dist = [0, 2, 2, 2, 3, 3, 1, 1, 3, 4, 5, 4, 3]

bfs(5);  // dist = [3, 5, 2, 1, 4, 0, 2, 4, 3, 4, 5, 6, 6]

bfs(8);  // dist = [3, 2, 1, 2, 1, 3, 2, 3, 0, 1, 2, 3, 3]