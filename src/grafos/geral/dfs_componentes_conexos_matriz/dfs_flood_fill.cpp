// --------------------------------------------------------------------------------
// DEPTH FIRST SEARCH E FLOOD FILL - COMPONENTES CONEXOS EM UMA MATRIZ
// --------------------------------------------------------------------------------

/*
Complexidade: O(n*m)

- Onde n e m são as dimensões da matriz.

Flood fill - preenchimento por inundação é um algoritmo utilizado para determinar
a conectividade entre vértices de um grafo a partir de um vértice de origem e,
por sua vez, alterar uma informação de cada vértice pertencente a esse grupo conexo.

Esse algoritmo é utilizado, por exemplo, na ferramenta de balde de tinta do
Microsoft Paint, onde todos os pixels de mesma cor e que estejam ligados ao
pixel selecionado têm sua cor alterada.

No exemplo deste algoritmo, temos uma matriz, com as áreas modificáveis '.' e as
áreas fixas '#'. A partir disso, queremos modificar uma determinada área dessa
matriz a partir de uma célula arbitrária, modificando o valor de todas as células
modificáveis e adjacentes à essa por 'V' (utilizando o mesmo conceito do balde do Paint).

A ideia do algoritmo é visitar todas as células adjacentes à célula de origem e
verificar se estas são modificáveis. Em caso positivo, alteramos seu valor e
visitamos todas as células adjacentes à essa, assim repetindo o ciclo inicial.

O algoritmo utiliza recursividade, onde a função chama a si mesma conforme
visitamos outros vértices, colocando as chamadas mais antigas em uma prioridade
menor, priorizando as chamadas mais recentes.

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
*/

#include <bits/stdc++.h>
using namespace std;

const int L = 10;  // Quantidade de linhas da matriz de exemplo
const int C = 12;  // Quantidade de colunas da matriz de exemplo

char matriz[L][C] = {  // Matriz de exemplo
    {'#','.','.','#','#','#','.','#','#','.','#','#'},
    {'#','#','.','#','#','.','.','.','#','#','#','.'},
    {'.','#','#','.','.','#','.','.','.','.','.','#'},
    {'#','.','.','#','.','.','.','.','#','#','#','#'},
    {'.','#','.','#','.','#','.','.','#','.','.','#'},
    {'.','.','#','#','#','#','#','.','#','.','.','.'},
    {'.','.','#','.','.','#','.','.','#','.','.','#'},
    {'.','.','#','.','.','#','#','#','.','.','.','#'},
    {'.','#','.','#','.','.','.','#','#','.','#','.'},
    {'#','#','.','.','.','.','#','.','.','.','.','.'}
};

int adj_l[] = {-1,0,1,0};  // Valores a serem somados na posição Y (linha)
int adj_c[] = {0,1,0,-1};  // Valores a serem somados na posição X (coluna)

void floodFill(int x, int y) {
    matriz[x][y] = 'V';  // Alterar o valor da célula

    for (int i = 0; i < 4; i++) {  // Iteração para cada célula adjacente à célula que está sendo visitada
        int l = x + adj_l[i];  // Posição Y (linha) da célula a ser visitada
        int c = y + adj_c[i];  // Posição X (coluna) da célula a ser visitada

        if (l < 0 || c < 0) continue;  // Se as posições Y ou X da célula não estão na matriz (saíram dos limites da matriz, menores que 0)
        if (l >= L || c >= C) continue;  // Se as posições Y ou X da célula não estão na matriz (saíram dos limites da matriz, maiores que o tamanho da matriz)
        if (matriz[l][c] != '.') continue;  // Se a célula não é um espaço em branco '.'

        // Se qualquer uma das condições acima for verdadeira, a iteração reinicia

        floodFill(l, c);  // Chamar a função Flood fill para a célula adjacente
    }

}

int main() {
    floodFill(2, 6);

    // matriz[] = {
    //     {'#','.','.','#','#','#','V','#','#','.','#','#'},
    //     {'#','#','.','#','#','V','V','V','#','#','#','.'},
    //     {'.','#','#','V','V','#','V','V','V','V','V','#'},
    //     {'#','.','.','#','V','V','V','V','#','#','#','#'},
    //     {'.','#','.','#','V','#','V','V','#','.','.','#'},
    //     {'.','.','#','#','#','#','#','V','#','.','.','.'},
    //     {'.','.','#','.','.','#','V','V','#','.','.','#'},
    //     {'.','.','#','.','.','#','#','#','.','.','.','#'},
    //     {'.','#','.','#','.','.','.','#','#','.','#','.'},
    //     {'#','#','.','.','.','.','#','.','.','.','.','.'}
    // }

    return 0;
}