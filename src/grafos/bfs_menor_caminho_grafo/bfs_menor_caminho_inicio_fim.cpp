// --------------------------------------------------------------------------------
// BREADTH FIRST SEARCH - MENOR CAMINHO EM UM GRAFO NÃO VALORADO
// --------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

const int vertices = 13;  // Número de vértices no grafo de exemplo

vector<int> grafo[vertices] = {  // Lista de adjacências do grafo de exemplo
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

// Criar a função bfs
int bfs(int inicio,int fim){
    if(inicio == fim){  // Se o vértice 'inicio' for igual ao vértice 'fim', o custo é zero
        return 0;
    }

    bool visitado[vertices] = {false};  // Array de vértices visitados (todos os elementos inicializados como 'false')
    visitado[inicio] = true;  // Definir o vértice 'inicio' como 'visitado'

    queue<int> fila;  // Fila para verificar as adjacências de cada vértice explorado
    fila.push(inicio);  // Adicionar o vértice 'inicio' à fila
    
    int v_restantes = 1;  // Vértices restantes na camada de busca (inicialmente só com o vértice 'inicio'). Será utilizado para determinar o número de vértices em cada camada de busca
    int distancia = 1;  // Distância até o vértice 'fim'. Inicialmente é no mínimo 1

    while(!fila.empty()){  // Iteração para cada vértice na fila
        int v = fila.front(); fila.pop();  // Pegar o último vértice e removê-lo da fila

        for(int proximo : grafo[v]){  // Iteração para cada vértice adjacente à 'v'
            if(proximo == fim){  // Se o próximo vértice da lista de adjacências de 'v' for igual ao vértice 'fim'
                return distancia;  // Retornar a distância entre eles
            }
            if(!visitado[proximo]){  // Se o próximo vértice não foi visitado
                fila.push(proximo);  // Adicioná-lo à fila
                visitado[proximo] = true;  // Agora visitamos esse vértice
            }
        }

        v_restantes--;  // Diminuir o número de vértices na camada de busca
        if(v_restantes == 0){  // Se foram analisados todos os vértices nessa camada de busca
            v_restantes = fila.size();  // A próxima camada de busca tem todos os vértices na próxima camada (tamanho atual da fila)
            distancia++;  // Como teremos que analisar outra camada de busca, a distância aumenta em 1
        }
    }

    return -1;  // Não encontramos o vértice 'fim', logo os vértices não são conexos
}

int main(){
    cout << bfs(5,12) << "\n";  // 6
    cout << bfs(4,0) << "\n";  // 3
    cout << bfs(1,3) << "\n";  // 4

    return 0;
}