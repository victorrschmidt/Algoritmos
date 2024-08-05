# Primalidade

Complexidade de tempo: **$O(√n)$**  
Complexidade de espaço: **$O(1)$**  

- Onde $n$ é o número a ser verificado.

# Explicação

Um número primo é um número inteiro maior que $1$ que só é divisível por $1$ e por ele mesmo. Em contrapartida, um número composto é um número inteiro maior que $1$ e que possui um ou mais divisores, além do $1$ e ele mesmo.

Uma das propriedades dos números compostos é:

$$\forall n((n \in C) \implies (\exists a(\exists b(a > 1 \land b > 1 \land ab = n))))$$

- Para qualquer número $n$ pertencente ao conjunto dos números compostos, existe pelo menos um par de números $a$ e $b$ tal que $a > 1$ e $b > 1$ e $ab = n$.

Por exemplo, a fatoração dos números compostos $8$ e $9$:

$$8 = 1 \cdot 8 = 2 \cdot 4 = 4 \cdot 2 = 8 \cdot 1$$

$$9 = 1 \cdot 9 = 3 \cdot 3 = 9 \cdot 1$$

Perceba que os fatores se invertem em certo ponto, onde o primeiro fator passa a ser maior que o segundo. Esse ponto é simplesmente $⌊√n⌋$, já que por definição, $√n \cdot √n = n$, então quando o primeiro fator alcança o primeiro número maior ou igual a $√n$, o segundo fator passa a ser menor ou igual ao primeiro, assim repetindo os fatores.

Tendo isso em mente, para um número ser considerado composto, este deve possuir pelo menos um divisor no intervalo $[2, ⌊√n⌋]$. Dessa forma, para um número ser considerado primo, a proposição anterior deve ser falsa, ou seja, um número primo não pode possuir nenhum divisor no dado intervalo.

O teste de primalidade é um algoritmo que verifica se um dado número $n$ possui algum divisor no intervalo $[2, ⌊√n⌋]$. Em caso negativo, o número é primo.
