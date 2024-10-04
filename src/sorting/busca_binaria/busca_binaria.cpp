// ------------------------------------------------------------------
// BUSCA BINÁRIA
// ------------------------------------------------------------------

#include <iostream>
#include <vector>
using namespace std;

// Array de exemplo
vector<int> v = {1, 4, 8, 8, 9, 11, 11, 12};

// Função para calcular a posição do número x no array.
// Se o número x não estiver presente, é retornado o número -1.
// Obs: Se x aparecer mais de uma vez no array,
// a posição irá variar de acordo com o tamanho do mesmo.
int busca_binaria(int x) {
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

    // Se um valor para m não foi retornado, x não está no array
    return -1;
}

// Função para calcular a posição do primeiro número >= x no array.
// Se o número x não estiver presente, é retornado o número -1.
int lower_bound(int x) {
    // Primeira posição do array
    int l = 0;
    // Última posição do array
    int r = v.size() - 1;

    // Posição do lower bound, inicialmente não encontrada,
    // portanto inicializada como o número -1.
    int pos = -1;

    // Iteração no intervalo [l, r] atual
    while (l <= r) {
        // Posição do meio do intervalo
        int m = (l + r) / 2;

        // Se o valor do meio for maior ou igual a x
        if (v[m] >= x) {
            // Atualizar a posição do lower bound
            pos = m;
            // Reduzir o intervalo para [l, m-1]
            r = m - 1;
        }
        // Caso contrário
        else {
            // Reduzir o intervalo para [m+1, r]
            l = m + 1;
        }
    }

    // Retornar a posição do lower bound
    return pos;
}

// Função para calcular a posição do primeiro número > x no array.
// Se o número x não estiver presente, é retornado o número -1.
int upper_bound(int x) {
    // Primeira posição do array
    int l = 0;
    // Última posição do array
    int r = v.size() - 1;

    // Posição do upper bound, inicialmente não encontrada,
    // portanto inicializada como o número -1.
    int pos = -1;

    // Iteração no intervalo [l, r] atual
    while (l <= r) {
        // Posição do meio do intervalo
        int m = (l + r) / 2;

        // Se o valor do meio for maior que x
        if (v[m] > x) {
            // Atualizar a posição do upper bound
            pos = m;
            // Reduzir o intervalo para [l, m-1]
            r = m - 1;
        }
        // Caso contrário
        else {
            // Reduzir o intervalo para [m+1, r]
            l = m + 1;
        }
    }

    // Retornar a posição do upper bound
    return pos;
}

int main() {
    cout << busca_binaria(9) << '\n';  // 4
    cout << busca_binaria(7) << '\n';  // -1
    cout << lower_bound(8) << '\n';  // 2
    cout << lower_bound(3) << '\n';  // 1
    cout << upper_bound(15) << '\n';  // -1
    cout << upper_bound(4) << '\n';  // 2

    return 0;
}
