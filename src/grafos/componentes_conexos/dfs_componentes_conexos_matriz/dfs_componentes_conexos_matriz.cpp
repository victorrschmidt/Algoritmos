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

void floodFill(int i, int j) {
    matriz[i][j] = 'V';  // Alterar o valor da célula

    for (int k = 0; k < 4; k++) {  // Iteração para cada célula adjacente à célula que está sendo visitada
        int i_ = i + vi[k];  // Posição i (linha) da célula a ser visitada
        int j_ = j + vj[k];  // Posição j (coluna) da célula a ser visitada

        if (i_ < 0 || j_ < 0) continue;  // Se as posições i ou j da célula não estão na matriz (saíram dos limites da matriz, menores que 0)
        if (i_ >= L || j_ >= C) continue;  // Se as posições i ou j da célula não estão na matriz (saíram dos limites da matriz, maiores que o tamanho da matriz)
        if (matriz[i_][j_] != '.') continue;  // Se a célula não é um espaço em branco '.'

        // Se qualquer uma das condições acima for verdadeira, a iteração reinicia

        floodFill(i_, j_);  // Chamar a função Flood fill para a célula adjacente
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
