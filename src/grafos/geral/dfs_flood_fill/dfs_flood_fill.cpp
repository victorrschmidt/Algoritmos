// --------------------------------------------------------------------------------
// DEPTH FIRST SEARCH E FLOOD FILL - COMPONENTES CONEXOS EM UMA MATRIZ
// --------------------------------------------------------------------------------

/*
* Complexidade: O(N*M)
*
* - Onde N e M são as dimensões da matriz.
*/

#include <bits/stdc++.h>
using namespace std;

const int L = 10;
const int C = 12;

char matriz[L][C] = {
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

int adj_l[] = {-1,0,1,0};
int adj_c[] = {0,1,0,-1};

// Função Flood Fill
void floodFill(int x, int y) {
    matriz[x][y] = 'V';

    for (int i = 0; i < 4; i++) {
        int l = x + adj_l[i];
        int c = y + adj_c[i];

        if (l >= 0 && c >= 0 && l < L && c < C && matriz[l][c] == '.') {
            floodFill(l, c);
        }
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