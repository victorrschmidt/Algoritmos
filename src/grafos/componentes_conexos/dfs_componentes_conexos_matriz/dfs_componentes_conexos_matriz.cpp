// --------------------------------------------------------------------------------
// DEPTH-FIRST SEARCH/FLOOD FILL - COMPONENTES CONEXOS EM UMA MATRIZ
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

vector<int> vi{-1,0,1,0};  // Variação de valores da posição i (linha)
vector<int> vj{0,1,0,-1};  // Variação de valores da posição j (coluna)

void flood_fill(int i, int j) {
    matriz[i][j] = 'V';  // Alterar o valor da célula

    for (int k = 0; k < 4; k++) {  // Iteração para cada célula adjacente à célula que está sendo visitada
        int _i = i + vi[k];  // Posição i (linha) da célula a ser visitada
        int _j = j + vj[k];  // Posição j (coluna) da célula a ser visitada

        if (_i < 0 || _j < 0) continue;  // Se as posições i ou j da célula não estão na matriz (saíram dos limites da matriz, menores que 0)
        if (_i >= L || _j >= C) continue;  // Se as posições i ou j da célula não estão na matriz (saíram dos limites da matriz, maiores que o tamanho da matriz)
        if (matriz[_i][_j] != '.') continue;  // Se a célula não é um espaço em branco '.'

        // Se qualquer uma das condições acima for verdadeira, a iteração reinicia

        flood_fill(_i, _j);  // Chamar a função Flood fill para a célula adjacente
    }
}

int main() {
    flood_fill(2, 6);

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
