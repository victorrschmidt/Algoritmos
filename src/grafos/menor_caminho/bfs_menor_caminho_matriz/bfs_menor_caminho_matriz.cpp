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

int i0 = 0;  // Posição inicial i (linha)
int j0 = 0;  // Posição inicial j (coluna)

int bfs() {
    vector<int> vi{-1,0,1,0};  // Variação de valores da posição i (linha)
    vector<int> vj{0,1,0,-1};  // Variação de valores da posição j (coluna)

    vector<vector<bool>> visitado(L, vector<bool>(C));  // Matriz de células visitadas (todas as células inicializadas como false)
    visitado[i0][j0] = true;  // Definir a célula inicial como visitada

    queue<pair<int,int>> fila;  // Fila para verificar cada célula adjacente na matriz
    fila.push(make_pair(i0, j0));  // Adicionar a célula inicial na fila ( {i, j} )

    int c_restantes = 1;  // Células restantes na camada de busca (inicialmente só com a célula inicial). Será utilizado para determinar o número de células em cada camada de busca
    int distancia = 0;  // Contador de distância até a célula final

    while (!fila.empty()) {  // Iteração para cada célula na fila
        auto [i, j] = fila.front();  // Pegar a posição i (linha) da célula e a posição j (coluna) da célula
        fila.pop();  // Remover a célula da fila

        if (matriz[i][j] == 'F') {  // Se essa célula é a célula final
            return distancia;  // Retornar a distância
        }

        for (int k = 0; k < 4; k++) {  // Iteração para cada célula adjacente à célula que está sendo visitada
            int iv = i + vi[k];  // Posição i (linha) da célula a ser visitada
            int jv = j + vj[k];  // Posição j (coluna) da célula a ser visitada

            if (iv < 0 || jv < 0) continue;  // Se as posições i ou j da célula não estão na matriz (saíram dos limites da matriz, menores que 0)
            if (iv >= L || jv >= C) continue;  // Se as posições i ou j da célula não estão na matriz (saíram dos limites da matriz, maiores que o tamanho da matriz)
            if (visitado[iv][jv]) continue;  // Se a célula já foi visitada
            if (matriz[iv][jv] == '#') continue;  // Se a célula é inacessível (pedra)

            // Se qualquer uma das condições acima for verdadeira, a iteração reinicia

            fila.push(make_pair(iv, jv));  // Adicionar a célula à fila
            visitado[iv][jv] = true;  // Agora visitamos essa célula
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
