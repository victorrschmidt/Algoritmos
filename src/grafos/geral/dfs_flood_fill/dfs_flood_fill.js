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

const L = 10;
const C = 10;

let matriz = [
    [],
    [],
    [],
    [],
    [],
    [],
    [],
    [],
    [],
    []
];

const adjL = [-1,0,1,0];
const adjC = [0,1,0,-1];

// Função Flood Fill
function floodFill(x, y) {
    matriz[x][y] = 'V';

    for (let i = 0; i < 4; i++) {
        let l = x + adjL[i];
        let c = y + adjC[i];

        if (l >= 0 && c >= 0 && l < L && c < C && matriz[l][c] == '.') {
            floodFill(l, c);
        }
    }

}