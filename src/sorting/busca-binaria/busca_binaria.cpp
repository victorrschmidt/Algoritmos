#include <iostream>
#include <vector>
using namespace std;

// Função para calcular a posição do número x no array.
// Se o número x não estiver presente, é retornado o número -1.
// Obs: Se x aparecer mais de uma vez no array,
// a posição irá variar de acordo com o tamanho do mesmo.
int busca_binaria(vector<int> v, int x) {
    // Primeira posição do array
    int l = 0;
    // Última posição do array
    int r = v.size() - 1;

    // Iteração no intervalo [l, r] atual
    while (l <= r) {
        // Posição do meio do intervalo
        int m = (l + r) / 2;

        // Se o valor do meio for igual a x
        if (v[m] == x) {
            // Retornar m
            return m;
        }

        // Se o valor do meio for menor que x
        if (v[m] < x) {
            // Reduzir o intervalo para [m+1, r]
            l = m + 1;
        }
        // Caso contrário
        else {
            // Reduzir o intervalo para [l, m-1]
            r = m - 1;
        }
    }

    // Se nenhum valor para m foi retornado, x não está no array
    return -1;
}

int main() {

    return 0;
}
