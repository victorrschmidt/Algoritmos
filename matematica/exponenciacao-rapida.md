---
description: Algoritmo para calcular um número elevado a um expoente.
---

# Exponenciação rápida

## Explicação

Exponenciação é uma operação matemática envolvendo uma base `b` e um expoente `e`, onde o resultado é o produto de `b` por `b`, `e` vezes.

$$
b^e = \underbrace{b \cdot b \cdot \dotsc \cdot b}_\text{$e$ vezes}
$$

Uma das formas de calcular `b` elevado a `e` é criar um loop de `i` até `e`, e para cada iteração, multiplicar o resultado por `b`.

```cpp
int res = 1;

for (int i = 1; i <= e; i++) {
    res *= b;
}
```

Um algoritmo desse tipo teria uma complexidade de tempo de O(e), pois teríamos que fazer `e` iterações para calcular o resultado final.

Entretanto, existe uma forma mais eficiente de calcular `b` elevado a `e`, utilizando uma das propriedades da exponenciação - a multiplicação de potências de mesma base:

$$
b^x \cdot b^y = b^{x+y}
$$

Com essa propriedade, se o expoente `e` for par, podemos definir:

$$
b^e = b^\frac{e}{2} \cdot b^\frac{e}{2}
$$

E se o expoente `e` for ímpar, podemos definir:

$$
b^e = b \cdot b^{e-1}
$$

Dessa forma, podemos definir a seguinte recorrência:

$$
b^e = \begin{cases}
  1 & \text{se } e=0  \\
  b \cdot b^{e-1} & \text{se } e \text{ for ímpar} \\
  b^\frac{e}{2} \cdot b^\frac{e}{2} & \text{se } e \text{ for par}
\end{cases}
$$

Assim, é possível definir uma função recursiva `f(b, e)` que calcula `b` elevado a `e`:

$$
f\big(b, e\big) = \begin{cases}
  1 & \text{ se } e=0  \\
  b \cdot f\big(b, e-1\big) & \text{ se } e \text{ for ímpar} \\
  f\big(b, \frac{e}{2}\big) \cdot f\big(b, \frac{e}{2}\big) & \text{ se } e \text{ for par}
\end{cases}
$$

A complexidade de tempo do algoritmo acima é de O(log(e)), que é a quantidade de vezes que iremos dividir `e` por 2 até chegar no caso base: 0. A complexidade de espaço também é de O(log(e)), que é a profundidade (_depth_) máximo da função.

### Implementação

{% tabs %}
{% tab title="C++" %}
```cpp
#include <iostream>
using namespace std;

// Função recursiva para calcular b**e
int potencia(int b, int e) {
    // Caso base: b**0 é igual a 1
    if (e == 0) {
        return 1;
    }

    // Se o expoente for ímpar
    if (e & 1) {
        // Retornar b * b**(e-1)
        return b * potencia(b, e - 1);
    }

    // Se o expoente for par, definir p = b**(e/2)
    int p = potencia(b, e / 2);

    // Retornar p*p = b**(e/2) * b**(e/2)
    return p*p;
}
```
{% endtab %}

{% tab title="Python" %}
```python
# Função recursiva para calcular b**e
def potencia(b: int, e: int) -> int:
    # Caso base: b**0 é igual a 1
    if e == 0:
        return 1

    # Se o expoente for ímpar
    if e & 1:
        # Retornar b * b**(e-1)
        return b * potencia(b, e - 1)

    # Se o expoente for par, definir p = b**(e/2)
    p = potencia(b, e // 2)

    # Retornar p*p = b**(e/2) * b**(e/2)
    return p*p
```
{% endtab %}
{% endtabs %}

## Exponenciação modular

A exponenciação modular é utilizada para calcular a potência quando a base e/ou expoente é muito grande, e para isso é utilizado um módulo para limitar o tamanho do resultado.

O mesmo algoritmo pode ser utilizado com um módulo `m`, apenas adicionando-o à recorrência, assim podendo ser definida uma função `f(b, e, m)` que calcula `b` elevado a `e` módulo `m`.

$$
f\big(b, e, m\big) = \begin{cases}
  1 & \text{ se } e = 0  \\
  b \cdot f\big(b, e-1, m\big) \bmod m & \text{ se } e \text{ for ímpar} \\
  f\big(b, \frac{e}{2}, m\big) \cdot f\big(b, \frac{e}{2}, m\big) \bmod m & \text{ se } e \text{ for par}
\end{cases}
$$

### Implementação

{% tabs %}
{% tab title="C++" %}
```cpp
#include <iostream>
using namespace std;

// Função recursiva para calcular b**e % m
int potencia_mod(int b, int e, int m) {
    // Caso base: b**0 é igual a 1
    if (e == 0) {
        return 1;
    }

    // Se o expoente for ímpar
    if (e & 1) {
        // Retornar b * b**(e-1) % m
        return b * potencia_mod(b, e - 1, m) % m;
    }

    // Se o expoente for par, definir p = b**(e/2)
    int p = potencia_mod(b, e / 2, m);

    // Retornar p*p % m = b**(e/2) * b**(e/2) % m
    return p*p % m;
}
```
{% endtab %}

{% tab title="Python" %}
```python
# Função recursiva para calcular b**e % m
def potencia_mod(b: int, e: int, m: int) -> int:
    # Caso base: b**0 é igual a 1
    if e == 0:
        return 1

    # Se o expoente for ímpar
    if e & 1:
        # Retornar b * b**(e-1) % m
        return b * potencia_mod(b, e - 1, m) % m

    # Se o expoente for par, definir p = b**(e/2)
    p = potencia_mod(b, e // 2, m)

    # Retornar p*p % m = b**(e/2) * b**(e/2) % m
    return p*p % m
```
{% endtab %}
{% endtabs %}
