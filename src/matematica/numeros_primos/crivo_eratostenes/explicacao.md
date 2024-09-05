# Crivo de Eratóstenes

Complexidade de tempo: **$O(n \cdot log(log(n)))$**  
Complexidade de espaço: **$O(n)$**  

- Onde $n$ é o número limite a ser considerado.

# Explicação

O Crivo de Eratóstenes é um algoritmo antigo utilizado para encontrar números primos no intervalo $[0, n]$, onde $n$ é um número inteiro arbitrário utilizado como limite.

## Início

Primeiro definimos um número inteiro $n$ como o limite para o intervalo $[0, n]$.

Em seguida, geramos um array booleano $primos[\ ]$ de tamanho $n + 1$ contendo todos os valores definidos como _true_. Ele será utilizado para armazenar a informação de primalidade de um número, ou seja, para saber se um número arbitrário $x$ é primo, bastar verificar em $primos[x]$.

Os números $0$ e $1$ são casos especiais, e são definidos como _false_ no início do algoritmo.

## Funcionamento

Suponhamos que o número limite seja $n = 10$.

Definimos um ponteiro $p$ que será utilizado para iterar através os elementos de $primos[\ ]$. Inicialmente, $p = 2$, o primeiro número primo.

Em seguida, iremos definir como _false_ todos os múltiplos de $p$ no intervalo $[p \cdot p, n]$.

```cpp
{false, false, true, true, false, true, false, true, false, true, false}
   0      1      2     3     4      5     6      7     8      9    10
                             ^            ^            ^            ^
```

Após isso, iremos incrementar o valor de $p$ em $1$, ou seja, $p = 3$.

Iremos verificar que $primos[p]$ é _true_, logo faremos o mesmo processo, definir como _false_ todos os múltiplos de $p$ no intervalo $[p \cdot p, n]$.

```cpp
{false, false, true, true, false, true, false, true, false, false, false}
   0      1      2     3     4      5     6      7     8      9     10
                                                              ^
```

Após isso, iremos incrementar o valor de $p$ em $1$, ou seja, $p = 4$.

Observe que $p \cdot p > n$, ou seja, o valor de $p \cdot p$ agora ultrapassa o intervalo limitado por $n$. Assim, no algoritmo, o valor de $p$ estará no intervalo $[2, ⌊√n⌋]$, visto que se $p \cdot p > n$, consequentemente $p > √n$.

## Conclusão

Quando o valor de $p$ ultrapassar o valor de $√n$, o algoritmo se encerra, e teremos o array $primos[\ ]$ definido. Com isso, podemos verificar se um número menor ou igual a $n$ é primo em $O(1)$.

Abaixo está uma visualização do funcionamento do algoritmo.

<p align="center">
   <img src="/img/crivo_eratostenes.gif" width="480" alt="crivo">
</p>

_Fonte_: https://pt.wikipedia.org/wiki/Ficheiro:New_Animation_Sieve_of_Eratosthenes.gif
