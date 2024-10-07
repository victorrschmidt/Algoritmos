# Crivo de Eratóstenes

Algoritmo para encontrar números primos de 0 a n.

## Explicação

O Crivo de Eratóstenes é um algoritmo antigo utilizado para encontrar números primos no intervalo [0, n], onde n é um número inteiro arbitrário utilizado como limite.

### Início

Primeiro definimos um número inteiro `n` como o limite para o intervalo [0, n].

Em seguida, geramos um array booleano `primos[]` de tamanho `n + 1` contendo todos os valores definidos como `true`. Ele será utilizado para armazenar a informação de primalidade de um número, ou seja, para saber se um número arbitrário `x` é primo, bastar verificar em `primos[x]`.

Os números 0 e 1 são casos especiais, e são definidos como `false` no início do algoritmo.

### Funcionamento

Suponhamos que o número limite seja `n = 10`.

Definimos um ponteiro `p` que será utilizado para iterar através os elementos de `primos[]`. Inicialmente, `p = 2`, o primeiro número primo.

Em seguida, iremos definir como `false` todos os múltiplos de `p` no intervalo [p\*p, n].

```cpp
{false, false, true, true, false, true, false, true, false, true, false}
   0      1      2     3     4      5     6      7     8      9    10
                             ^            ^            ^            ^
```

Após isso, iremos incrementar o valor de `p` em 1, ou seja, `p = 3`.

Iremos verificar que `primos[p] = true`, logo faremos o mesmo processo, definir como `false` todos os múltiplos de `p` no intervalo [p\*p, n].

```cpp
{false, false, true, true, false, true, false, true, false, false, false}
   0      1      2     3     4      5     6      7     8      9     10
                                                              ^
```

Após isso, iremos incrementar o valor de `p` em 1, ou seja, `p = 4`.

Observe que p\*p > n, ou seja, o valor de p\*p agora ultrapassa o intervalo limitado por n. Assim, no algoritmo, o valor de p estará no intervalo [2, ⌊√n⌋], visto que se p\*p > n, consequentemente p > √n.

### Conclusão

Quando o valor de p ultrapassar o valor de √n, o algoritmo se encerra, e teremos o array `primos[]` definido. Com isso, podemos verificar se um número menor ou igual a n é primo em tempo constante.

Abaixo está uma visualização do funcionamento do algoritmo.

<p align="center">
   <img src="/img/crivo_eratostenes.gif" width="480" alt="crivo">
</p>

Crivo de Eratóstenes. Fonte: https://pt.wikipedia.org/wiki/Ficheiro:New_Animation_Sieve_of_Eratosthenes.gif