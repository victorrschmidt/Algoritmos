#include <iostream>
#include <vector>
using namespace std;

// Função para encontrar a posição do primeiro número >= x no array.
// Se nenhum valor satisfazer essa condição, é retornado o número -1.
int lower_bound(vector<int> v, int x) {
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

int main() {

    return 0;
}
