---
description: Algoritmo para encontrar números primos de 0 a n.
---

# Crivo de Eratóstenes

## Explicação

O Crivo de Eratóstenes é um algoritmo antigo utilizado para encontrar números primos no intervalo \[0, n], onde n é um número inteiro arbitrário utilizado como limite. O algoritmo foi nomeado por causa de seu criador, o matemático grego Eratóstenes de Cirene.

### Início

Primeiro definimos um número inteiro `n` como o limite para o intervalo \[0, n].

Em seguida, geramos um array booleano `primos[]` de tamanho `n + 1` contendo todos os valores definidos como `true`. Ele será utilizado para armazenar a informação de primalidade de um número, ou seja, para saber se um número arbitrário `x` é primo, bastar verificar em `primos[x]`.

Os números 0 e 1 são casos especiais, e são definidos como `false` no início do algoritmo.

### Funcionamento

Suponhamos que o número limite seja `n = 10`.

Definimos um ponteiro `p` que será utilizado para iterar através os elementos de `primos[]`. Inicialmente, `p = 2`, o primeiro número primo.

Em seguida, iremos definir como `false` todos os múltiplos de `p` no intervalo \[p\*p, n].

```cpp
{false, false, true, true, false, true, false, true, false, true, false}
   0      1      2     3     4      5     6      7     8      9    10
                             ^            ^            ^            ^
```

Após isso, iremos incrementar o valor de `p` em 1, ou seja, `p = 3`.

Iremos verificar que `primos[p] = true`, logo faremos o mesmo processo, definir como `false` todos os múltiplos de `p` no intervalo \[p\*p, n].

```cpp
{false, false, true, true, false, true, false, true, false, false, false}
   0      1      2     3     4      5     6      7     8      9     10
                                                              ^
```

Após isso, iremos incrementar o valor de `p` em 1, ou seja, `p = 4`.

Observe que p\*p > n, ou seja, o valor de p\*p agora ultrapassa o fim do intervalo limitado por n. Assim, no algoritmo, o valor de p estará no intervalo \[2, ⌊√n⌋], visto que se p\*p > n, consequentemente p > √n.

### Conclusão

Quando o valor de p ultrapassar o valor de √n, o algoritmo se encerra, e teremos o array `primos[]` definido. Com isso, podemos verificar se um número menor ou igual a `n` é primo em tempo constante.

Abaixo está uma visualização do funcionamento do algoritmo.

<figure><img src="../../.gitbook/assets/crivo_eratostenes.gif" alt="Crivo de Eratóstenes"><figcaption><p>Crivo de Eratóstenes. Fonte: <a href="https://pt.wikipedia.org/wiki/Ficheiro:New_Animation_Sieve_of_Eratosthenes.gif">https://pt.wikipedia.org/wiki/Ficheiro:New_Animation_Sieve_of_Eratosthenes.gif</a></p></figcaption></figure>

## Implementação

{% tabs %}
{% tab title="C++" %}
```cpp
#include <iostream>
#include <vector>
using namespace std;

// Função para gerar o array de primos de 0 até n
vector<bool> crivo(int n) {
    // Array de números (todos os elementos inicializados como true).
    // Cada posição p é um valor booleano que determina se o número
    // p é primo (true) ou não (false).
    vector<bool> primos(n+1, true);

    // Casos especiais: 0 e 1 não são números primos
    primos[0] = primos[1] = false;

    // Iteração de p no intervalo [2, √n]
    for (int p = 2; p*p <= n; p++) {
        // Se p não é primo
        if (!primos[p]) {
            // Continuar a iteração
            continue;
        }

        // Iteração de i (múltiplos de p) no intervalo [p*p, n]
        for (int i = p*p; i <= n; i += p) {
            // Definir i como não primo
            primos[i] = false;
        }
    }

    // Retornar o array
    return primos;
}
```
{% endtab %}

{% tab title="Python" %}
```python
# Função para gerar a lista de primos de 0 até n
def crivo(n: int) -> list[bool]:
    # Lista de números (todos os elementos inicializados como True).
    # Cada posição p é um valor booleano que determina se o número
    # p é primo (True) ou não (False).
    primos = [True for i in range(n+1)]

    # Casos especiais: 0 e 1 não são números primos
    primos[0] = primos[1] = False

    # Iteração de p no intervalo [2, √n]
    p = 2
    while p*p <= n:
        # Se p é primo
        if primos[p]:
            # Iteração de i (múltiplos de p) no intervalo [p*p, n]
            for i in range(p*p, n+1, p):
                # Definir i como não primo
                primos[i] = False
        p += 1

    # Retornar a lista
    return primos
```
{% endtab %}
{% endtabs %}
