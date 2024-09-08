# Programação dinâmica

## Sobre

Programação dinâmica é uma técnica de resolução e otimização, onde o problema principal é decomposto em um conjunto de subproblemas menores que são utilizados como base para encontrar uma resposta ótima para o problema principal.

## Calculando números de Fibonacci

Tomemos como exemplo a famosa **Sequência de Fibonacci**. Nessa sequência, começamos pelos dois primeiros termos: $0$ e $1$, e a partir destes, cada número será a soma dos dois termos anteriores. Abaixo estão os $10$ primeiros números dessa sequência.

$$0,\ 1,\ 1,\ 2,\ 3,\ 5,\ 8,\ 13,\ 21,\ 34, \dots$$

Considere $fib(n)$ uma função que retorna o enésimo (0-indexado) número da Sequência de Fibonacci. Sendo assim, por definição:

```math
fib(n)  = \begin{cases}
  0 & \text{se } n=0 \\
  1 & \text{se } n=1 \\
  fib(n-2) + fib(n-1) & \text{se } n > 1
\end{cases}
```

Para calcular $fib(7)$, por exemplo, seria necessário calcular $fib(m)$ para todo $m \leq 7$. Abaixo está uma visualização da árvore recursiva de $fib(7)$.

<p align="center">
   <img src="/img/programacao_dinamica_generalizacao.png" width="840" alt="arvore_recursiva_fibonacci">
</p>

_Fonte_: https://en.wikipedia.org/wiki/File:FibbonacciRecurisive.png

Para chegarmos ao resultado final, é preciso dividir o problema em diversos problemas menores. Para todo $m \leq 7$ (com exceção do casos base $1$ e $2$) são calculadas duas funções que definem o resultado da inicial. O fator de multiplicação do número de chamadas recursivas em função de $n$ é exponencial, portanto, em termos de complexidade de tempo, $fib(n)$ é calculado em $O(2^n)$.

## Memorizando cálculos

Ainda considerando a árvore recursiva acima, perceba que diversas funções são calculadas mais de uma vez. Como dito anteriormente, a complexidade de tempo para calcular $fib(n)$ é exponencial, pois cada função "chama" mais duas funções. Para otimizar esse problema e evitar recálculos, podemos armazenar o resultado de $fib(n)$ em um array $dp[\ ]$* na posição $n$. Dessa forma, antes de chamar as funções que definem $fib(n)$, verificamos se $dp[n]$ já foi calculado. Em caso positivo, simplesmente retornamos o resultado, caso contrário, chamamos as funções para que o valor para $n$ seja calculado. Com isso, a complexidade de tempo cai de $O(2^n)$ para $O(n)$.

\* "dp" é um nome comum utilizado para nomear o array de memorização em problemas de PD.

## PD Top-down

A abordagem Top-down se baseia em: começar pelo problema maior e recursivamente calcular os subproblemas menores. Essa é a abordagem do exemplo acima, onde é gerada uma árvore recursiva.

```txt
dp[0] = 0
dp[1] = 1

funcao fib(n):
    se n já foi calculado:
        retorne dp[n]
    senao:
        dp[n] = fib(n-2) + fib(n-1)
        retorne dp[n]
```

## PD Bottom-up

A abordagem Bottom-up se baseia em: começar pelos subproblemas menores, para no final responder o problema maior. Ainda no exemplo da Sequência de Fibonacci, começamos calculando o segundo termo, que só depende dos dois casos base $0$ e $1$. Assim, cada número é calculado de forma sequencial, tendo como base os termos previamente calculados.

```txt
dp[0] = 0
dp[1] = 1

para cada i em 2...n:
    dp[i] = dp[i-2] + dp[i-1]

// após isso, todos os valores até n estarão calculados
```

Exemplos completos de ambas as abordagens estão disponíveis no mesmo diretório deste arquivo.
