// ------------------------------------------------------------------
// BREADTH-FIRST SEARCH - MENOR CAMINHO EM UM GRAFO NÃO VALORADO
// ------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Número de vértices do grafo de exemplo
const int V = 13;

// Lista de adjacências do grafo de exemplo
vector<vector<int>> adj{
    {6,7},  // 0->6, 0->7
    {7,4,12},  // 1->7, 1->4, 1->12
    {3,6,8},  // 2->3, 2->6, 2->8
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

// Array para armazenar a distância entre
// o vértice de origem e os outros vértices.
vector<int> dist(V);

// Função para calcular a distância entre o vértice
// 'origem' e os outros vértices do grafo.
void bfs(int origem) {
    // Definir a distância até os outros vértices como -1
    fill(dist.begin(), dist.end(), -1);

    // A distância entre a origem e a própria origem é 0
    dist[origem] = 0;

    // Array de vértices visitados
    // (todos os elementos inicializados como false).
    vector<bool> visitado(V);
    // Definir o vértice de origem como 'visitado'
    visitado[origem] = true;

    // Fila para armazenar as adjacências de cada vértice processado
    queue<int> fila;
    // Adicionar o vértice de origem à fila
    fila.push(origem);

    // Iteração para cada vértice na fila
    while (!fila.empty()) {
        // Pegar o primeiro vértice
        int u = fila.front();
        // Removê-lo da fila
        fila.pop();

        // Iteração para cada vértice adjacente à u
        for (auto v : adj[u]) {
            // Se o vértice v ainda não foi visitado
            if (!visitado[v]) {
                // Definir o vértice como 'visitado'
                visitado[v] = true;

                // Adicioná-lo à fila
                fila.push(v);

                // Definir a distância até esse vértice
                // (distância até o vértice u + 1).
                dist[v] = dist[u] + 1;
            }
        }
    }
}

int main() {
    bfs(0);
    // dist[] = {0, 2, 2, 2, 3, 3, 1, 1, 3, 4, 5, 4, 3}

    bfs(5);
    // dist[] = {3, 5, 2, 1, 4, 0, 2, 4, 3, 4, 5, 6, 6}

    bfs(8);
    // dist[] = {3, 2, 1, 2, 1, 3, 2, 3, 0, 1, 2, 3, 3}


    return 0;
}
