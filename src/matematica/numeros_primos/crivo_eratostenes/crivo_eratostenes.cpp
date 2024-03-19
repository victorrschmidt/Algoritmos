// --------------------------------------------------------------------------------
// CRIVO DE ERATÓSTENES
// --------------------------------------------------------------------------------

/*
Complexidade: O(n*log(log(n)))

- Onde n é o número limite a ser considerado.

O Crivo de Eratóstenes é um algoritmo antigo utilizado para encontrar números primos 
no intervalo [0, n], onde n é um número natural arbitrário utilizado como limite.

O algoritmo funciona da seguinte forma:

Início

    Primeiro definimos um número natural n como o limite para o intervalo [0, n].

    Em seguida, geramos um array booleano primos[] de tamanho n+1 contendo todos os valores 
    definidos como true. Ela será utilizada para armazenar a informação de primalidade de
    um número, ou seja, para saber se um número arbitrário x é primo, bastar verificar em
    primos[x] (x deve pertencer ao intervalo [0, n]).
    
    Os números 0 e 1 são casos especiais, e são definidos como false no início do algoritmo.

Funcionamento

    Supomos que o número limite n = 10.
    
    Definimos um ponteiro P que será utilizado para iterar através os elementos de primos[].
    Inicialmente, P = 2, o primeiro número primo.
    
    Em seguida, iremos definir como false todos os múltiplos de P no intervalo [P * P, n].

    
    {false, false, true, true, false, true, false, true, false, true, false}
       0      1      2     3     4      5     6      7     8      9    10
                                 ^            ^            ^           ^
    

    Após isso, iremos incrementar o valor de P em 1, ou seja, P = 3.

    Iremos verificar que primos[P] é true, logo faremos o mesmo processo, definir como
    false todos os múltiplos de P no intervalo [P * P, n].

    
    {false, false, true, true, false, true, false, true, false, false, false}
       0      1      2     3     4      5     6      7     8      9     10
                                                                  ^


    Após isso, iremos incrementar o valor de P em 1, ou seja, P = 4.

    Observe que P * P > n, ou seja, o valor de P agora ultrapassa o intervalo limitado por n.
    Ou seja, no algoritmo, o valor de P estará no intervalo [2, √n], visto que se P > √n,
    consequentemente P * P > n.

Terminus

    Quando o valor de P ultrapassar o valor de √n, o algoritmo se encerra, e teremos o array
    primos[] definido. Com isso, podemos responder se um número arbitrário x é primo em O(1).

Uma visualização do funcionamento do algoritmo pode ser vista no link abaixo:
https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes#/media/File:Animation_Sieve_of_Eratosth.gif
*/

#include <bits/stdc++.h>
using namespace std;

vector<bool> crivo(int n) {
    vector<bool> primos(n+1);  // Array de primos
    fill(primos.begin(), primos.end(), true);  // Todos os elementos inicializados como true

    primos[0] = primos[1] = false;  // Casos especiais: 0 e 1 não são primos

    for (int p = 2; p <= sqrt(n); p++) {  // Iteração de p no intervalo [2, √n]
        if (!primos[p]) {  // Se o número não é primo
            continue;  // Continuar a iteração
        }

        for (int i = p * p; i <= n; i += p) {  // Iteração de i (múltiplos de p) no intervalo [p * p, n]
            primos[i] = false;  // Definir o número como não-primo
        }
    }

    return primos;  // Retornar o array
}

int main() {
    vector<bool> v = crivo(14);

    // [false, false, true, true, false, true, false, true, false, false, false, true, false, true, false]
    //    0      1      2     3     4      5     6      7     8      9     10     11    12     13    14
    //                primo primo        primo        primo                      primo        primo

    return 0;
}