// --------------------------------------------------------------------------------
// BUSCA BINÁRIA
// --------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

vector<int> v{1, 4, 8, 8, 9, 11, 11, 12};  // Array de exemplo

// Posição do número x no array, ou -1 (caso x não estiver no array)
// Obs: Se x aparecer mais de uma vez no array, a posição irá variar de acordo com o tamanho do mesmo
int busca_binaria(int x) {
    int l = 0;  // Primeira posição do array
    int r = v.size() - 1;  // Última posição do array

    while (l <= r) {  // Iteração no intervalo
        int m = (l + r) / 2;

        if (v[m] == x) {  // Se o valor for igual a x
            return m;  // Retornar m
        }
        if (v[m] < x) {  // Se o valor for menor que x
            l = m + 1;  // Reduzir o intervalo para [m+1, r]
        }
        else {  // Caso contrário
            r = m - 1;  // Reduzir o intervalo para [l, m-1]
        }
    }

    return -1;  // x não está no array
}

// Posição do primeiro número >= x no array, ou -1 (caso nenhum número no array satisfazer essa condição)
int lower_bound(int x) {
    int l = 0;  // Primeira posição do array
    int r = v.size() - 1;  // Última posição do array
    int pos = -1;  // Posição do lower bound

    while (l <= r) {  // Iteração no intervalo
        int m = (l + r) / 2;

        if (v[m] >= x) {  // Se o valor for maior ou igual a x
            pos = m;  // Atualizar a posição do lower bound
            r = m - 1;  // Reduzir o intervalo para [l, m-1]
        }
        else {  // Caso contrário
            l = m + 1;  // Reduzir o intervalo para [m+1, r]
        }
    }

    return pos;  // Retornar a posição do lower bound (-1 indica que não existe um lower bound de x na lista)
}

// Posição do primeiro número > x no array, ou -1 (caso nenhum número no array satisfazer essa condição)
int upper_bound(int x) {
    int l = 0;  // Primeira posição do array
    int r = v.size() - 1;  // Última posição do array
    int pos = -1;  // Posição do upper bound

    while (l <= r) {  // Iteração no intervalo
        int m = (l + r) / 2;

        if (v[m] > x) {  // Se o valor for maior que x
            pos = m;  // Atualizar a posição do upper bound
            r = m - 1;  // Reduzir o intervalo para [l, m-1]
        }
        else {  // Caso contrário
            l = m + 1;  // Reduzir o intervalo para [m+1, r]
        }
    }

    return pos;  // Retornar a posição do upper bound (-1 indica que não existe um upper bound de x na lista)
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
