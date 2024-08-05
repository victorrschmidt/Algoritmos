# Exponenciação rápida

Complexidade de tempo: **$O(log(e))$**  
Complexidade de espaço: **$O(log(e))$**  

- Onde $e$ é o expoente.

# Explicação

Exponenciação é uma operação matemática envolvendo uma base $b$ e um expoente $e$, onde o resultado é a multiplicação de $b$ por $b$, $e$ vezes.

```math
b^e =
\underbrace{b \cdot b \cdot \text{ ... } \cdot b}_\text{$e$ vezes} =
\prod_{i=1}^e b
```

Uma das formas de calcular $b^e$, seria criar um loop de $i$ até $e$, e para cada iteração, multiplicar o resultado por $b$.

```cpp
int res = 1;

for (int i = 1; i <= e; i++) {
    res *= b;
}
```

Um algoritmo desse tipo teria uma complexidade de tempo de $O(e)$, pois teríamos que fazer $e$ iterações.

Entretanto, existe uma forma mais eficiente de calcular $b^e$, utilizando uma das propriedades da exponenciação; a multiplicação de potências de mesma base:

```math
b^x \cdot b^y = b^{x+y}
```

Ou seja, se o expoente $e$ for par, podemos definir:

```math
b^e = b^\frac{e}{2} \cdot b^\frac{e}{2}
```

E se o expoente for ímpar, podemos definir:

```math
b^e = b \cdot b^{e-1}
```

Dessa forma, podemos definir a seguinte recorrência:

```math
b^e = \begin{cases}
  1 & \text{se } e = 0  \\
  b \cdot b^{e-1} & \text{se } e \text{ for ímpar} \\
  b^\frac{e}{2} \cdot b^\frac{e}{2} & \text{se } e \text{ for par}
\end{cases}$$
```

Assim, é possível escrever uma função recursiva $f(b, e)$, que calcula $b^e$:

```math
f\Big(b, e\Big) = \begin{cases}
  1, \text{ se } e = 0  \\
  b \cdot f\Big(b, e - 1\Big), \text{ se } e \text{ for ímpar} \\
  f\Big(b, \frac{e}{2}\Big) \cdot f\Big(b, \frac{e}{2}\Big), \text{ se } e \text{ for par}
\end{cases}$$
```

A complexidade de tempo do algoritmo acima é de $O(log(e))$, que é a quantidade de vezes que iremos dividir $e$ por $2$ até chegar no caso base: $0$. A complexidade de espaço também é de $O(log(e))$, que é a profundidade (depht) máximo da função.

## Exponenciação modular

A exponenciação modular é utilizada para calcular a potência quando a base e/ou expoente é muito grande, e para isso é utilizado um módulo para limitar o tamanho do resutado.

O mesmo algoritmo pode ser utilizado com um módulo $m$, apenas adicionando-o à recorrência.

```math
f\Big(b, e\Big) \bmod m = \begin{cases}
  1, \text{ se } e = 0  \\
  b \cdot f\Big(b, e - 1\Big) \bmod m, \text{ se } e \text{ for ímpar} \\
  f\Big(b, \frac{e}{2}\Big) \cdot f\Big(b, \frac{e}{2}\Big) \bmod m, \text{ se } e \text{ for par}
\end{cases}$$
```
