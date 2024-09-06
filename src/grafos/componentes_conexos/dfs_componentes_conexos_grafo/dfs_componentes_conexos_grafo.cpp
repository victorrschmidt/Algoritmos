// --------------------------------------------------------------------------------
// DEPTH-FIRST SEARCH - COMPONENTES CONEXOS EM UM GRAFO
// --------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

const int V = 12;  // Número de vértices do grafo de exemplo

vector<vector<int>> adj{  // Lista de adjacências do grafo de exemplo
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

int id = 0;  // Contador que define o número do grupo de cada vértice
vector<int> componente(V);  // Array para identificar o grupo ao qual cada vértice pertence
vector<bool> visitado(V);  // Array de vértices visitados (todos os elementos inicializados como false)

// Função dfs
void dfs(int u) {
    visitado[u] = true;  // Definir o vértice u como 'visitado'
    componente[u] = id;  // Identificar o id do vértice no array (o grupo ao qual esse vértice pertence é o id atual)

    for (const auto v : adj[u]) {  // Iteração para cada vértice adjacente à u
        if (!visitado[v]) {  // Se o vértice v ainda não foi visitado
            dfs(v);  // Chamar a função dfs para v
        }
    }
}

// Função para identificar os vértices
void encontrarComponentes() {
    for (int i = 0; i < V; i++) {  // Iteração para cada vértice no grafo
        if (!visitado[i]) {  // Se o vértice i ainda não foi visitado
            id++;  // Incrementar o id (número de grupos)
            dfs(i);  // Chamar a função dfs para i
        }
    }
}

int main() {
    encontrarComponentes();

    // componente[] = {1, 2, 3, 4, 1, 1, 3, 2, 1, 3, 3, 2}
    // id = 4 (4 grupos)

    return 0;
}
