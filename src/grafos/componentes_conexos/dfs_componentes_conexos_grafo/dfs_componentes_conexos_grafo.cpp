// ------------------------------------------------------------------
// DEPTH-FIRST SEARCH - COMPONENTES CONEXOS EM UM GRAFO
// ------------------------------------------------------------------

#include <iostream>
#include <vector>
using namespace std;

// Número de vértices do grafo de exemplo
const int V = 12;

// Lista de adjacências do grafo de exemplo
vector<vector<int>> adj{
    {5,8,4},  // 0->5, 0->8, 0->4
    {7,11},  // 1->7, 1->11
    {6},  // 2->6
    {},  // ...
    {0,8},
    {0},
    {2,9},
    {1,11},
    {0,4},
    {10,6},
    {9},
    {1,7}
};

// Contador que define o número do grupo de cada vértice
int id = 0;

// Array para identificar o grupo ao qual cada vértice pertence
vector<int> componente(V);

// Array de vértices visitados
// (todos os elementos inicializados como false).
vector<bool> visitado(V);

// Função recursiva de busca em profundidade
void dfs(int u) {
    // Definir o vértice u como 'visitado'
    visitado[u] = true;

    // Identificar o id do vértice no array.
    // O grupo ao qual esse vértice pertence é o id atual.
    componente[u] = id;

    // Iteração para cada vértice adjacente à u
    for (auto v : adj[u]) {
        // Se o vértice v ainda não foi visitado
        if (!visitado[v]) {
            // Chamar a função dfs para v
            dfs(v);
        }
    }
}

// Função para identificar cada um dos vértices do grafo
void encontrar_compoentes() {
    // Iteração para cada vértice no grafo
    for (int i = 0; i < V; i++) {
        // Se o vértice i ainda não foi visitado
        if (!visitado[i]) {
            // Chamar a função dfs para i
            dfs(i);

            // Incrementar o id (número de grupos).
            // Todos os vértices conexos à i já foram
            // visitados/processados
            id++;
        }
    }
}

int main() {
    encontrar_compoentes();

    // componente[] = {0, 1, 2, 3, 0, 0, 2, 1, 0, 2, 2, 1}
    // id = 4 = n° de componentes conexos no grafo

    return 0;
}
