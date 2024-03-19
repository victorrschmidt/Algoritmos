// --------------------------------------------------------------------------------
// CRIVO DE ERATÓSTENES
// --------------------------------------------------------------------------------

/*
Complexidade: O(n*log(log(n)))

- Onde n é o número limite a ser considerado
*/

function crivo(n) {
    let primos = Array(n+1).fill(true);

    primos[0] = primos[1] = false;  // Casos especiais: 0 e 1 não são primos

    let p = 2;

    while (p * p <= n) {
        if (primos[p]) {
            for (let i = p * p; i <= n; i += p) {
                primos[i] = false;
            }
        }

        p++;
    }

    return primos;
}

console.log(crivo(15));
// [false, false, true, true, false, true, false, true, false, false, false, true, false, true, false, false]
//    0      1      2     3     4      5     6      7     8      9     10     11    12     13    14     15