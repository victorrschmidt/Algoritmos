// --------------------------------------------------------------------------------
// DEPTH FIRST SEARCH E FLOOD FILL - COMPONENTES CONEXOS EM UMA MATRIZ
// --------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

const int L = 10;  // Quantidade de linhas da matriz de exemplo
const int C = 12;  // Quantidade de colunas da matriz de exemplo

vector<vector<char>> matriz{  // Matriz de exemplo
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

vector<int> dl{-1,0,1,0};  // Valores a serem somados na posição Y (linha)
vector<int> dc{0,1,0,-1};  // Valores a serem somados na posição X (coluna)

void floodFill(int l, int c) {
    matriz[l][c] = 'V';  // Alterar o valor da célula

    for (int i = 0; i < 4; i++) {  // Iteração para cada célula adjacente à célula que está sendo visitada
        int nova_l = l + dl[i];  // Posição Y (linha) da célula a ser visitada
        int nova_c = c + dc[i];  // Posição X (coluna) da célula a ser visitada

        if (nova_l < 0 || nova_c < 0) continue;  // Se as posições Y ou X da célula não estão na matriz (saíram dos limites da matriz, menores que 0)
        if (nova_l >= L || nova_c >= C) continue;  // Se as posições Y ou X da célula não estão na matriz (saíram dos limites da matriz, maiores que o tamanho da matriz)
        if (matriz[nova_l][nova_c] != '.') continue;  // Se a célula não é um espaço em branco '.'

        // Se qualquer uma das condições acima for verdadeira, a iteração reinicia

        floodFill(nova_l, nova_c);  // Chamar a função Flood fill para a célula adjacente
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
