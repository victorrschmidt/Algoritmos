# Busca binária

Complexidade de tempo: **$O(\log(n))$**  
Complexidade de espaço: **$O(1)$**  

- Onde $n$ é a quantidade de elementos na faixa de busca.

## Explicação

Busca binária é um algoritmo que determina a existência de um valor arbitrário em um conjunto ordenado.

### Generalização

Considere uma função crescente $f(x)$, e que queremos determinar o valor de $x$ tal que $f(x) = k$. Considere também que $x \in [0, \ 10^6]$, $x \in \mathbb{Z}$ e que os valores de $f(x)$ são distintos para cada $x$.

Para encontrar $x$, poderíamos testar todos os valores no dado intervalo. Essa abordagem possui um custo de processamento linear, e depende do tamanho do intervalo. Para pensar em uma abordagem melhor, podemos considerar o fato de que $f(x)$ é uma função **crescente**, isto é:

$$x < y \implies f(x) < f(y)$$

Vamos testar, de forma arbitrária, o valor do "meio" do intervalo ($5 \cdot 10^5$). Com base nessa escolha, podemos definir as seguintes implicações:

$$f(5 \cdot 10^5) > k \implies f(x) < f(5 \cdot 10^5) \ ∧ \ x < 5 \cdot 10^5 \ ∧ \ x \in [0, \ 5 \cdot 10^5[$$

$$f(5 \cdot 10^5) < k \implies f(x) > f(5 \cdot 10^5) \ ∧ \ x > 5 \cdot 10^5 \ ∧ \ x \in ]5 \cdot 10^5, \ 10^6]$$

- Se a primeira desigualdade for verdadeira, $x$ é menor que o valor do "meio", portanto podemos considerar o intervalo de busca como o início do intervalo original (inclusivo) até o valor do "meio" original (exclusivo).
- Se a segunda desigualdade for verdadeira, $x$ é maior que o valor do "meio", portanto podemos considerar o intervalo de busca como o valor do "meio" original (exclusivo) até o fim do intervalo original (inclusivo).

Em ambos os casos, a quantidade de elementos presentes no intervalo é reduzida pela metade, e consequentemente o custo de processamento também é reduzido pela metade.

O processo de escolher o "meio" do intervalo e verificar o valor da função se repete até que o intervalo seja vazio ou o valor de $x$ seja encontrado. Desta forma, ao invés de verificar um valor para $x$ $n$ (tamanho do intervalo original) vezes, podemos verificar somente $\log_2(n)$ vezes, que é a quantidade de vezes que é possível reduzir o intervalo pela metade até restar um único elemento. No exemplo acima, para $n = 10^6$, é possível encontrar $x$ em no máximo $20$ iterações.

### Busca binária em array ordenado

Considere o seguinte array de inteiros:

```cpp
{3, 5, 7, 8, 9, 11, 15, 16, 22, 23, 26, 28, 29, 30, 32, 34, 36, 37, 38, 39}
```

Supondo que as posições de cada número não são conhecidas e que queremos encontrar a posição do número $15$, iremos definir dois ponteiros $l$ e $r$, que apontam, respectivamente, para a primeira e última posição do array. Iremos procurar o número enquanto $l \leq r$.

```cpp
{3, 5, 7, 8, 9, 11, 15, 16, 22, 23, 26, 28, 29, 30, 32, 34, 36, 37, 38, 39}
 0  1  2  3  4  5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
 ^                                                                      ^
 l                                                                      r
```

Iremos definir a posição do meio $m = ⌊\frac{l + r}{2}⌋ = 9$ e verificar o valor nessa posição.

```cpp
{3, 5, 7, 8, 9, 11, 15, 16, 22, 23, 26, 28, 29, 30, 32, 34, 36, 37, 38, 39}
 0  1  2  3  4  5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
 ^                              ^                                       ^
 l                              m                                       r
```

O número na posição $m$, $23$, é **maior** que o número que estamos procurando ($15$), portanto, sabemos agora que esse valor está à esquerda de $m$, e redefinimos que $r = m - 1$.

```cpp
{3, 5, 7, 8, 9, 11, 15, 16, 22, 23, 26, 28, 29, 30, 32, 34, 36, 37, 38, 39}
 0  1  2  3  4  5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
 ^                          ^
 l                          r
```

Novamente, redefinimos $m = ⌊\frac{l + r}{2}⌋ = 4$.

```cpp
{3, 5, 7, 8, 9, 11, 15, 16, 22, 23, 26, 28, 29, 30, 32, 34, 36, 37, 38, 39}
 0  1  2  3  4  5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
 ^           ^              ^
 l           m              r
```

O número na posição $m$, $9$, é **menor** que o número que procuramos, portanto, sabemos agora que esse valor está à direita de $m$, e redefinimos que $l = m + 1$.

```cpp
{3, 5, 7, 8, 9, 11, 15, 16, 22, 23, 26, 28, 29, 30, 32, 34, 36, 37, 38, 39}
 0  1  2  3  4  5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
                ^           ^
                l           r
```

Novamente, redefinimos $m = ⌊\frac{l + r}{2}⌋ = 6$.

```cpp
{3, 5, 7, 8, 9, 11, 15, 16, 22, 23, 26, 28, 29, 30, 32, 34, 36, 37, 38, 39}
 0  1  2  3  4  5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
                ^   ^       ^
                l   m       r
```

O número na posição $m$ é o número que estamos procurando, portanto podemos encerrar a busca e retornar a posição $m$.

Se o número não estivesse presente no array, a busca se encerraria quando $l > r$, $m$ não seria retornado e teríamos um retorno nulo.

### Outros conceitos

#### Lower bound

Dado um conjunto ordenado $C$ e um número $x$, chamamos de _lower bound_ de $x$ o menor valor $y$ tal que $y \in C \ ∧ \ x \leq y$.

Por exemplo, considere uma função crescente $f(x)$ e que queremos encontrar o menor valor $x$ tal que $f(x) \geq k$. Podemos aplicar o mesmo conceito de busca binária mostrado anteriormente, com a diferença de que iremos manter salvo o menor valor global $m$ de cada iteração que satisfaça a desigualdade $f(m) \geq k$. Se nenhum valor $m$ satisfazer essa condição, significa que $x$ não possui um _lower bound_ no dado conjunto.

#### Upper bound

Ainda considerando o exemplo mostrado no _lower bound_, chamamos de _upper bound_ de $x$ o menor valor $y$ tal que $y \in C \ ∧ \ x < y$. O processo de encontrar o _upper bound_ é praticamente o mesmo de encontrar o _lower bound_, basta apenas mudar o sinal de desigualdade de verificação para $f(m) > k$.