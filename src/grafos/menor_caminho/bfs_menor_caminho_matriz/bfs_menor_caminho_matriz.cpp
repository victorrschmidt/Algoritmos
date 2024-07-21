// --------------------------------------------------------------------------------
// BREADTH FIRST SEARCH - MENOR CAMINHO EM UMA MATRIZ
// --------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

const int L = 6;  // Quantidade de linhas da matriz de exemplo
const int C = 8;  // Quantidade de colunas da matriz de exemplo

vector<vector<char>> matriz{  // Matriz de exemplo
    {'C','.','#','.','.','.','.','#'},
    {'.','.','.','.','#','#','#','.'},
    {'.','#','.','.','.','#','.','.'},
    {'#','.','.','#','.','#','F','#'},
    {'.','.','#','#','.','.','.','.'},
    {'#','.','.','.','.','.','.','#'}
};

int pos_l = 0;  // Posição inicial Y (linha)
int pos_c = 0;  // Posição inicial X (coluna)

int bfs() {
    vector<int> dl{-1,0,1,0};  // Valores a serem somados na posição Y (linha)
    vector<int> dc{0,1,0,-1};  // Valores a serem somados na posição X (coluna)

    vector<vector<bool>> visitado(L, vector<bool>(C));  // Matriz de células visitadas (todas as células inicializadas como false)
    visitado[pos_l][pos_c] = true;  // Definir a célula inicial como visitada

    queue<pair<int,int>> fila;  // Fila para verificar cada célula adjacente na matriz
    fila.push(make_pair(pos_l, pos_c));  // Adicionar a célula inicial na fila ( {eixo X, eixo Y} )

    int c_restantes = 1;  // Células restantes na camada de busca (inicialmente só com a célula inicial). Será utilizado para determinar o número de células em cada camada de busca
    int distancia = 0;  // Contador de distância até a célula final

    while (!fila.empty()) {  // Iteração para cada célula na fila
        auto [l, c] = fila.front();  // Pegar a posição Y (linha) da célula e a posição X (coluna) da célula
        fila.pop();  // Remover a célula da fila

        if (matriz[l][c] == 'F') {  // Se essa célula é a célula final
            return distancia;  // Retornar a distância entre a célula inicial e final
        }

        for (int i = 0; i < 4; i++) {  // Iteração para cada célula adjacente à célula que está sendo visitada
            int nova_l = l + dl[i];  // Posição Y (linha) da célula a ser visitada
            int nova_c = c + dc[i];  // Posição X (coluna) da célula a ser visitada

            if (nova_l < 0 || nova_c < 0) continue;  // Se as posições Y ou X da célula não estão na matriz (saíram dos limites da matriz, menores que 0)
            if (nova_l >= L || nova_c >= C) continue;  // Se as posições Y ou X da célula não estão na matriz (saíram dos limites da matriz, maiores que o tamanho da matriz)
            if (visitado[nova_l][nova_c]) continue;  // Se a célula já foi visitada
            if (matriz[nova_l][nova_c] == '#') continue;  // Se a célula é inacessível (pedra)

            // Se qualquer uma das condições acima for verdadeira, a iteração reinicia

            fila.push(make_pair(nova_l, nova_c));  // Adicionar a célula à fila
            visitado[nova_l][nova_c] = true;  // Agora visitamos essa célula
        }

        c_restantes--;  // Diminuir o número de células na camada de busca

        if (c_restantes == 0) {  // Se foram verificadas todas as células nessa camada de busca
            c_restantes = fila.size();  // A próxima camada de busca tem todas as células na próxima camada (tamanho atual da fila)
            distancia++;  // Como teremos que verificar outra camada de busca, a distância aumenta em 1
        }

    }

    return -1;  // Não existe caminho possível entre a célula inicial e final
}

int main() {
    cout << bfs() << '\n';  // 11

    return 0;
}
