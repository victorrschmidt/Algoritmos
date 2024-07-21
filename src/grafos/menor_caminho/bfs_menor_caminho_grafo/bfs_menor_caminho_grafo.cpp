// --------------------------------------------------------------------------------
// BREADTH FIRST SEARCH - MENOR CAMINHO EM UM GRAFO NÃO VALORADO
// --------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

const int V = 13;  // Número de vértices do grafo de exemplo

vector<vector<int>> adj{  // Lista de adjacências do grafo de exemplo
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

vector<int> dist(V, -1);  // Array para armazenar a distância do vértice de origem até os outros vértices (com todas as distância inicializadas como -1)

void bfs(int origem) {
    dist[origem] = 0;  // A distância da origem até a própria origem é 0

    vector<bool> visitado(V);  // Array de vértices visitados (todos os elementos inicializados como false)
    visitado[origem] = true;  // Definir o vértice de origem como 'visitado'

    queue<int> fila;  // Fila para verificar as adjacências de cada vértice explorado
    fila.push(origem);  // Adicionar o vértice de origem à fila

    while (!fila.empty()) {  // Iteração para cada vértice na fila
        int v = fila.front();  // Pegar o último vértice
        fila.pop();  // Removê-lo da fila

        for (const auto u : adj[v]) {  // Iteração para cada vértice adjacente à v
            if (!visitado[u]) {  // Se o vértice u ainda não foi visitado
                visitado[u] = true;  // Agora visitamos esse vértice
                fila.push(u);  // Adicioná-lo à fila
                dist[u] = dist[v]+1;  // Definir a distância até esse vértice (distância até o vértice anterior + 1)
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
