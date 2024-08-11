// --------------------------------------------------------------------------------
// BREADTH-FIRST SEARCH - MENOR CAMINHO EM UM GRAFO NÃO VALORADO
// --------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

const int V = 13;  // Número de vértices do grafo de exemplo

vector<vector<int>> adj{  // Lista de adjacências do grafo de exemplo
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

vector<int> dist(V);  // Array para armazenar a distância do vértice de origem até os outros vértices

void bfs(int origem) {
    fill(dist.begin(), dist.end(), -1);  // Definir a distância até os outros vértices como -1
    dist[origem] = 0;  // A distância da origem até a própria origem é 0

    vector<bool> visitado(V);  // Array de vértices visitados (todos os elementos inicializados como false)
    visitado[origem] = true;  // Definir o vértice de origem como 'visitado'

    queue<int> fila;  // Fila para verificar as adjacências de cada vértice processado
    fila.push(origem);  // Adicionar o vértice de origem à fila

    while (!fila.empty()) {  // Iteração para cada vértice na fila
        int u = fila.front();  // Pegar o último vértice
        fila.pop();  // Removê-lo da fila

        for (const auto v : adj[u]) {  // Iteração para cada vértice adjacente à u
            if (!visitado[v]) {  // Se o vértice v ainda não foi visitado
                visitado[v] = true;  // Definir o vértice como 'visitado'
                fila.push(v);  // Adicioná-lo à fila
                dist[v] = dist[u]+1;  // Definir a distância até esse vértice (distância até o vértice u + 1)
            }
        }
    }
}

int main() {
    bfs(0);  // dist[] = {0, 2, 2, 2, 3, 3, 1, 1, 3, 4, 5, 4, 3}

    bfs(5);  // dist[] = {3, 5, 2, 1, 4, 0, 2, 4, 3, 4, 5, 6, 6}

    bfs(8);  // dist[] = {3, 2, 1, 2, 1, 3, 2, 3, 0, 1, 2, 3, 3}


    return 0;
}
