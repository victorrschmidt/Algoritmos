// --------------------------------------------------------------------------------
// BUSCA BINÁRIA
// --------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

vector<int> v{1, 4, 8, 8, 9, 11, 11, 12};

// Posição do número x no array, ou -1 (caso x não estiver no array)
// Obs: Se x aparecer mais de uma vez no array, a posição irá variar de acordo com o tamanho do mesmo
int busca_binaria(int x) {
    int l = 0;
    int r = v.size() - 1;

    while (l <= r) {
        int m = (l + r) / 2;

        if (v[m] == x) {
            return m;
        }
        if (v[m] < x) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    return -1;
}

// Posição do primeiro número >= x no array, ou -1 (caso nenhum número no array satisfazer essa condição)
int lower_bound(int x) {
    int l = 0;
    int r = v.size() - 1;
    int pos = -1;

    while (l <= r) {
        int m = (l + r) / 2;

        if (v[m] >= x) {
            pos = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    return pos;
}

// Posição do primeiro número > x no array, ou -1 (caso nenhum número no array satisfazer essa condição)
int upper_bound(int x) {
    int l = 0;
    int r = v.size() - 1;
    int pos = -1;

    while (l <= r) {
        int m = (l + r) / 2;

        if (v[m] > x) {
            pos = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

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
