---
description: Algoritmo para encontrar valores em um conjunto ordenado.
---

# Busca binária

## Explicação

Busca binária é um algoritmo que determina a existência de um valor específico em um conjunto ordenado de forma crescente ou decrescente. O algoritmo utiliza a comparação numérica entre o valor a ser encontrado e o valor do conjunto que é verificado em cada passo, a fim de otimizar o intervalo de busca e, consequentemente, o tempo de execução.

### Generalização

Considere uma função crescente `f(x)`, e que queremos determinar o valor de `v` tal que `f(v) = k`. Considere também que `v` é um número inteiro, está no intervalo \[0, 10^6], e que os valores de `f(x)` são distintos para cada `x`.

Para encontrar `v`, poderíamos testar todos os valores no dado intervalo, e verificar para qual valor de `v` a igualdade `f(v) = k` é verdadeira. Essa abordagem possui um custo de processamento linear, e depende do tamanho do intervalo, ou seja, no pior caso possível, teríamos que verificar todos os elementos presentes no intervalo.&#x20;

Para pensar em uma abordagem mais eficiente, vamos relembrar o fato de que `f(x)` é uma função **crescente**, isto é:

$$
a < b \implies f(a) < f(b)
$$

Vamos testar, de forma arbitrária, o valor do "meio" do intervalo: `m`. Sendo assim, `m = 5 * 10^5`. Com base nessa escolha, podemos definir as seguintes implicações:

$$
f(m) > k \implies f(m) > f(v) \ ∧ \ m > v \ ∧ \ v \in [0, \ m[
$$

$$
f(m) < k \implies f(m) < f(v) \ ∧ \ m < v \ ∧ \ v \in \ ]m, \ 10^6]
$$

* Se a primeira desigualdade for verdadeira, `v` é **menor** do que o valor do "meio", portanto podemos considerar o intervalo de busca como sendo o início do intervalo original (inclusivo) até o valor do "meio" original (exclusivo).
* Se a segunda desigualdade for verdadeira, `v` é **maior** do que o valor do "meio", portanto podemos considerar o intervalo de busca como sendo o valor do "meio" original (exclusivo) até o fim do intervalo original (inclusivo).

Em ambos os casos, a quantidade de elementos presentes no intervalo é reduzida pela metade e, consequentemente, o custo de processamento é reduzido pela metade.

O processo de escolher o "meio" do intervalo e verificar o valor da função se repete até que o intervalo se torne vazio ou o valor de `v` seja encontrado. Dessa forma, ao invés de verificar um valor para `v` N (tamanho do intervalo original) vezes, podemos verificar somente log2(N), que é a quantidade de vezes que é possível reduzir o intervalo pela metade até restar um único elemento. No exemplo acima, para N = 10^6, é possível encontrar `v` em no máximo 20 iterações/verificações.

### Busca binária em um array ordenado

Considere o seguinte array de inteiros:

```cpp
{3, 5, 7, 8, 9, 11, 15, 16, 22, 23, 26, 28, 29, 30, 32, 34, 36, 37, 38, 39}
```

Supondo que as posições de cada número não são conhecidas e que queremos encontrar a posição do número **15**, iremos definir dois ponteiros `l` e `r` que apontam, respectivamente, para a primeira e última posição do array. Iremos procurar o número enquanto `l <= r`.

```cpp
{3, 5, 7, 8, 9, 11, 15, 16, 22, 23, 26, 28, 29, 30, 32, 34, 36, 37, 38, 39}
 0  1  2  3  4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19
 ^                                                                       ^
 l                                                                       r
```

Iremos definir a posição do meio `m = floor((l + r) / 2) = 9` e verificar o valor nessa posição.

```cpp
{3, 5, 7, 8, 9, 11, 15, 16, 22, 23, 26, 28, 29, 30, 32, 34, 36, 37, 38, 39}
 0  1  2  3  4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19
 ^                               ^                                       ^
 l                               m                                       r
```

O número na posição `m`, 23, é **maior** que o valor que estamos procurando (15), portanto, sabemos agora que este está à esquerda de `m`, e redefinimos `r = m - 1`.

```cpp
{3, 5, 7, 8, 9, 11, 15, 16, 22, 23, 26, 28, 29, 30, 32, 34, 36, 37, 38, 39}
 0  1  2  3  4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19
 ^                           ^
 l                           r
```

Novamente, redefinimos `m = floor((l + r) / 2) = 4`.

```cpp
{3, 5, 7, 8, 9, 11, 15, 16, 22, 23, 26, 28, 29, 30, 32, 34, 36, 37, 38, 39}
 0  1  2  3  4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19
 ^           ^               ^
 l           m               r
```

O número na posição `m`, 9, é **menor** que o valor que procuramos, portanto, sabemos agora que este está à direita de `m`, e redefinimos `l = m + 1`.

```cpp
{3, 5, 7, 8, 9, 11, 15, 16, 22, 23, 26, 28, 29, 30, 32, 34, 36, 37, 38, 39}
 0  1  2  3  4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19
                 ^           ^
                 l           r
```

Novamente, redefinimos `m = floor((l + r) / 2) = 6`.

```cpp
{3, 5, 7, 8, 9, 11, 15, 16, 22, 23, 26, 28, 29, 30, 32, 34, 36, 37, 38, 39}
 0  1  2  3  4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19
                 ^   ^       ^
                 l   m       r
```

O número na posição `m` é o número que estamos procurando, portanto podemos encerrar a busca e retornar a posição `m`.

Se o número não estivesse presente no array, a busca se encerraria quando `l > r`, `m` não seria retornado e teríamos um retorno nulo.

### Implementação

{% tabs %}
{% tab title="C++" %}
```cpp
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
```
{% endtab %}

{% tab title="Python" %}
```python
# Função para calcular a posição do número x na lista.
# Se o número x não estiver presente, é retornado o número -1.
# Obs: Se x aparecer mais de uma vez na lista,
# a posição irá variar de acordo com o tamanho da mesma.
def busca_binaria(v: list[int], x: int) -> int:
    # Primeira posição da lista
    l = 0
    # Última posição da lista
    r = len(v) - 1

    # Iteração no intervalo [l, r] atual
    while l <= r:
        # Posição do meio do intervalo
        m = (l + r) // 2

        # Se o valor do meio for igual a x
        if v[m] == x:
            # Retornar m
            return m

        # Se o valor do meio for menor que x
        if v[m] < x:
            # Reduzir o intervalo para [m+1, r]
            l = m + 1
        # Caso contrário
        else:
            # Reduzir o intervalo para [l, m-1]
            r = m - 1

    # Se nenhum valor para m foi retornado, x não está na lista
    return -1
```
{% endtab %}
{% endtabs %}

## Lower bound

Dado um conjunto ordenado **C** e um número `x`, denomina-se o _lower bound_ de `x` o menor valor `y` tal que:

$$
y \in C \ ∧ \ x \leq y
$$

Por exemplo, considere uma função crescente `f(x)` e que queremos encontrar o menor valor `v` tal que `f(v) >= k`. Podemos aplicar o mesmo conceito de busca binária mostrado anteriormente, com a diferença de que iremos manter salvo o menor valor possível de `m` de cada iteração que satisfaça a desigualdade `f(m) >= k`. Se nenhum valor de `m` satisfazer essa condição, significa que `v` não possui um _lower bound_ no dado conjunto.

### Implementação

{% tabs %}
{% tab title="C++" %}
```cpp
#include <iostream>
#include <vector>
using namespace std;

// Função para calcular a posição do primeiro número >= x no array.
// Se o número x não estiver presente, é retornado o número -1.
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
```
{% endtab %}

{% tab title="Python" %}
```python
# Função para calcular a posição do primeiro número >= x na lista.
# Se o número x não estiver presente, é retornado o número -1.
def lower_bound(v: list[int], x: int) -> int:
    # Primeira posição da lista
    l = 0
    # Última posição da lista
    r = len(v) - 1

    # Posição do lower bound, inicialmente não encontrada,
    # portanto inicializada como o número -1.
    pos = -1

    # Iteração no intervalo [l, r] atual
    while l <= r:
        # Posição do meio do intervalo
        m = (l + r) // 2

        # Se o valor do meio for maior ou igual a x
        if v[m] >= x:
            # Atualizar a posição do lower bound
            pos = m
            # Reduzir o intervalo para [l, m-1]
            r = m - 1
        # Caso contrário
        else:
            # Reduzir o intervalo para [m+1, r]
            l = m + 1

    # Retornar a posição do lower bound
    return pos
```
{% endtab %}
{% endtabs %}

## Upper bound

Ainda considerando o exemplo mostrado no _lower bound_, denomina-se o _upper bound_ de `x` o menor valor `y` tal que:

$$
y \in C \ ∧ \ x < y
$$

O processo de encontrar o _upper bound_ de um elemento é praticamente o mesmo do _lower bound_, basta apenas mudar o sinal de desigualdade de verificação para `f(m) > k`.

### Implementação

{% tabs %}
{% tab title="C++" %}
```cpp
#include <iostream>
#include <vector>
using namespace std;

// Função para calcular a posição do primeiro número > x no array.
// Se o número x não estiver presente, é retornado o número -1.
int upper_bound(vector<int> v, int x) {
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
```
{% endtab %}

{% tab title="Python" %}
```python
# Função para calcular a posição do primeiro número > x na lista.
# Se o número x não estiver presente, é retornado o número -1.
def upper_bound(v: list[int], x: int) -> int:
    # Primeira posição da lista
    l = 0
    # Última posição da lista
    r = len(v) - 1

    # Posição do upper bound, inicialmente não encontrada,
    # portanto inicializada como o número -1.
    pos = -1

    # Iteração no intervalo [l, r] atual
    while l <= r:
        # Posição do meio do intervalo
        m = (l + r) // 2

        # Se o valor do meio for maior que x
        if v[m] > x:
            # Atualizar a posição do upper bound
            pos = m
            # Reduzir o intervalo para [l, m-1]
            r = m - 1
        # Caso contrário
        else:
            # Reduzir o intervalo para [m+1, r]
            l = m + 1

    # Retornar a posição do upper bound
    return pos
```
{% endtab %}
{% endtabs %}
