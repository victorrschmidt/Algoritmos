// --------------------------------------------------------------------------------
// BREADTH FIRST SEARCH - MENOR CAMINHO EM UMA MATRIZ
// --------------------------------------------------------------------------------

/*
Complexidade de tempo: O(n*m)
Complexidade de espaço: O(n*m)

- Onde n e m são as dimensões da matriz.

Temos o seguinte problema: Estamos presos em uma caverna, começando na posição inicial 'C', e
queremos determinar o menor número de passos necessários para chegar até a saída da caverna 'F'.
Podemos atravessar todos os espaços vazios '.', e não podemos atravessar os espaços com pedras '#'.
Podemos nos mover para cima, para a direita, para baixo e para a esquerda.

A ideia do algoritmo é visitar todas as células adjacentes à célula inicial,
depois visitar todas as células adjacentes à essas, e assim sucessivamente.
Cada camada de busca corresponde a um movimento - a distância mínima possível
entre a célula inicial e a célula que está sendo visitada.

Assim, é possível determinar a menor distância entre a célula inicial e
a célula final (considerando que cada movimento tem peso 1).

Perceba que a matriz é basicamente um grafo, onde cada célula possui ligação
com suas células adjacentes. As céluas adjacentes são: a célula de cima, da direita,
de baixo e da esquerda.

Abaixo está a representação de uma célula (meio) e suas adjacências:

            | (x, y-1) |
------------------------------------
  (x-1, y)  |  (x, y)  |  (x+1, y)
------------------------------------
            | (x, y+1) |

Ou seja, para analisar as células adjacentes, basta alterar o valor de X ou Y.
Para a célula de cima, diminuímos o Y em 1.
Para a célula da direita, aumentamos o X em 1.
Para a celula de baixo, aumentamos o Y em 1.
Para a célula da esquerda, diminuímos o X em 1.

Então, temos a seguinte notação para as células:

Célula do meio = V

Célula de cima = A
A(X) = V(X) e A(Y) = V(Y) - 1

Célula da direita = B
B(X) = V(X) + 1 e B(Y) = V(Y)

Célula de baixo = C
C(X) = V(X) e C(Y) = V(Y) + 1

Célula da esquerda = D
D(X) = V(X) - 1 e D(Y) = V(Y)

Podemos armazenar a variação dos valores de X e Y em dois arrays:
x[] = {-1,0,1,0}
y[] = {0,1,0,-1}

Obs: Estamos considerando uma matriz representada por um computador,
logo os valores de Y são crescentes de cima para baixo, diferente da
representação em um plano cartesiano.

A matriz utilizada de exemplo está no mesmo diretório deste arquivo.
*/

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
