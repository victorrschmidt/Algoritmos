// --------------------------------------------------------------------------------
// BREADTH FIRST SEARCH - MENOR CAMINHO EM UM GRAFO NÃO VALORADO
// --------------------------------------------------------------------------------

/*
Complexidade: O(v+e)

- Onde 'v' e 'e' são, respectivamente, a quantidade de vértices e arestas do grafo.

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

#include <bits/stdc++.h>
using namespace std;

const int V = 13;  // Número de vértices do grafo de exemplo

vector<int> adj[V] = {  // Lista de adjacências do grafo de exemplo
    {6,7},  // 0 se liga com 6 e 7
    {7,4,12},  // 1 se liga com 7, 4 e 12
    {3,6,8},  // 2 se liga com 3, 6 e 8
    {5,6,2},  // ...
    {1,8},
    {3},
    {0,3,2},
    {0,1},
    {2,9,4},
    {8,10},
    {9,11},
    {10,12},
    {1,11}
};

int dist[V];  // Array para armazenar a distância do vértice de origem até os outros vértices

void bfs(int origem) {
    memset(dist, -1, sizeof(dist));  // Definimos a distância até os outros vértices como -1
    dist[origem] = 0;  // A distância da origem até a própria origem é 0

    bool visitado[V] = {false};  // Array de vértices visitados (todos os elementos inicializados como 'false')
    visitado[origem] = true;  // Definir o vértice de origem como 'visitado'

    queue<int> fila;  // Fila para verificar as adjacências de cada vértice explorado
    fila.push(origem);  // Adicionar o vértice de origem à fila

    while (!fila.empty()) {  // Iteração para cada vértice na fila
        int v = fila.front();  // Pegar o último vértice
        fila.pop();  // Removê-lo da fila

        for (const auto u : adj[v]) {  // Iteração para cada vértice adjacente à 'v'
            if (visitado[u]) {  // Se o vértice u já foi visitado
                continue;  // Continuar a iteração
            }

            visitado[u] = true;  // Agora visitamos esse vértice
            fila.push(u);  // Adicioná-lo à fila
            dist[u] = dist[v]+1;  // Definir a distância até esse vértice (distância até o vértice anterior + 1)
        }
    }

}

int main() {
    bfs(0);  // dist[] = {0, 2, 2, 2, 3, 3, 1, 1, 3, 4, 5, 4, 3}

    bfs(5);  // dist[] = {3, 5, 2, 1, 4, 0, 2, 4, 3, 4, 5, 6, 6}

    bfs(8);  // dist[] = {3, 2, 1, 2, 1, 3, 2, 3, 0, 1, 2, 3, 3}


    return 0;
}