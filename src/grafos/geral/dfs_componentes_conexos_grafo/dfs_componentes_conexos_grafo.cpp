// --------------------------------------------------------------------------------
// DEPTH FIRST SEARCH - COMPONENTES CONEXOS EM UM GRAFO
// --------------------------------------------------------------------------------

/*
* Complexidade: O(V+E)
*
* - Onde V e E são, respectivamente, a quantidade de vértices e arestas do grafo.
*
* O grafo utilizado de exemplo está no mesmo diretório deste arquivo.
*/

#include <bits/stdc++.h>
using namespace std;

const int VERT = 12;

vector<int> grafo[VERT] = {
    {5,8,4},  // 0 se liga com 5, 8 e 4
    {7,11},  // 1 se liga com 7 e 11
    {6},  // 2 se liga com 6
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

int id = 0;  // Define o grupo de cada vértice
int componente[VERT];  // Array para identificar o grupo de cada componente
bool visitado[VERT] = {false};  // Array de vértices visitados (todos os elementos inicializados como 'false')

// Função dfs
void dfs(int v) {
    visitado[v] = true;  // O vértice passado na função agora é visitado
    componente[v] = id;  // Identificar o id do vértice no array (o grupo ao qual esse vértice pertence é o id atual)

    for (auto u : grafo[v]) {  // Iteração para cada vértice adjacente à 'v'
        if (!visitado[u]) {  // Se o vértice 'u' não foi visitado
            dfs(u);  // Chamar a função dfs para 'u'.
        }
    }

}

// Função para identificar os vértices
void encontrarComponentes() {
    for (int i = 0; i < VERT; i++) {  // Iteração para cada vértice no grafo
        if (!visitado[i]) {  // Se o vértice não foi visitado
            id++;  // Aumentar o id (número de grupos)
            dfs(i);  // Chamar a função dfs para esse vértice
        }
    }

}

int main() {
    encontrarComponentes();

    // componente[] = {1, 2, 3, 4, 1, 1, 3, 2, 1, 3, 3, 2}
    // id = 4 (4 grupos)

    return 0;
}