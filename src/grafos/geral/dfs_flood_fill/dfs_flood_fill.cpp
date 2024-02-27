// --------------------------------------------------------------------------------
// DEPTH FIRST SEARCH E FLOOD FILL - COMPONENTES CONEXOS EM UMA MATRIZ
// --------------------------------------------------------------------------------

/*
* Complexidade: O(N*M)
*
* - Onde N e M são as dimensões da matriz.
*
* O grafo utilizado de exemplo está no mesmo diretório deste arquivo.
*/

#include <bits/stdc++.h>
using namespace std;

const int L = 10;
const int C = 10;

char matriz[L][C] = {
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {}
};

int adjL[] = {-1,0,1,0};
int adjC[] = {0,1,0,-1};

// Função Flood Fill
void floodFill(int x, int y) {
    matriz[x][y] = 'V';

    for (int i = 0; i < 4; i++) {
        int l = x + adjL[i];
        int c = y + adjC[i];

        if (l >= 0 && c >= 0 && l < L && c < C && matriz[l][c] == '.') {
            floodFill(l, c);
        }
    }

}

int main() {


    return 0;
}