# Exponenciação rápida

Algoritmo para calcular um número elevado a um expoente.

## Explicação

Exponenciação é uma operação matemática envolvendo uma base `b` e um expoente `e`, onde o resultado é o produto de `b` por `b`, `e` vezes.

$$b^e = \underbrace{b \cdot b \cdot \dotsc \cdot b}_\text{$e$ vezes}$$

Uma das formas de calcular `b` elevado a `e` é criar um loop de `i` até `e`, e para cada iteração, multiplicar o resultado por `b`.

```cpp
int res = 1;

for (int i = 1; i <= e; i++) {
    res *= b;
}
```

Um algoritmo desse tipo teria uma complexidade de tempo de O(e), pois teríamos que fazer `e` iterações.

Entretanto, existe uma forma mais eficiente de calcular `b` elevado a `e`, utilizando uma das propriedades da exponenciação - a multiplicação de potências de mesma base:

```math
b^x \cdot b^y = b^{x+y}
```

Com essa propriedade, se o expoente `e` for par, podemos definir:

```math
b^e = b^\frac{e}{2} \cdot b^\frac{e}{2}
```

E se o expoente `e` for ímpar, podemos definir:

```math
b^e = b \cdot b^{e-1}
```

Dessa forma, podemos definir a seguinte recorrência:

```math
b^e = \begin{cases}
  1 & \text{se } e=0  \\
  b \cdot b^{e-1} & \text{se } e \text{ for ímpar} \\
  b^\frac{e}{2} \cdot b^\frac{e}{2} & \text{se } e \text{ for par}
\end{cases}
```

Assim, é possível escrever uma função recursiva f(b, e), que calcula b elevado a e:

```math
f\big(b, e\big) = \begin{cases}
  1 & \text{ se } e=0  \\
  b \cdot f\big(b, e-1\big) & \text{ se } e \text{ for ímpar} \\
  f\big(b, \frac{e}{2}\big) \cdot f\big(b, \frac{e}{2}\big) & \text{ se } e \text{ for par}
\end{cases}
```

A complexidade de tempo do algoritmo acima é de O(log(e)), que é a quantidade de vezes que iremos dividir `e` por 2 até chegar no caso base: 0. A complexidade de espaço também é de O(log(e)), que é a profundidade (_depht_) máximo da função.

## Exponenciação modular

A exponenciação modular é utilizada para calcular a potência quando a base e/ou expoente é muito grande, e para isso é utilizado um módulo para limitar o tamanho do resultado.

O mesmo algoritmo pode ser utilizado com um módulo `m`, apenas adicionando-o à recorrência, tendo assim uma função f(b, e, m) que calcula b elevado a e módulo m.

```math
f\big(b, e, m\big) = \begin{cases}
  1 & \text{ se } e = 0  \\
  b \cdot f\big(b, e-1, m\big) \bmod m & \text{ se } e \text{ for ímpar} \\
  f\big(b, \frac{e}{2}, m\big) \cdot f\big(b, \frac{e}{2}, m\big) \bmod m & \text{ se } e \text{ for par}
\end{cases}
```
