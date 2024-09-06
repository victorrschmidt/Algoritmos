# Busca binária

Complexidade de tempo: **$O(\log(n))$**  
Complexidade de espaço: **$O(1)$**  

- Onde $n$ é a quantidade de elementos na faixa de busca.

## Explicação

Busca binária

Considere uma função crescente $f(x)$, e que queremos determinar o valor de $x$ tal que $f(x) = k$. Considere também que $x \in [0, \ 10^6]$ e que os valores de $f(x)$ são distintos para cada $x$.

Para encontrar esse valor, poderíamos testar todos os valores para $x$ no dado intervalo. O problema dessa abordagem é que o custo de processamento é linear, e depende do tamanho do intervalo. Para pensar em uma abordagem melhor, podemos considerar o fato de que $f(x)$ é uma função **crescente**, isto é:

$$x < y \implies f(x) < f(y)$$

Vamos testar, de forma arbitrária, o valor do "meio" do intervalo ($5 \cdot 10^5$). Com base nessa escolha, podemos definir as seguintes implicações:

$$f(5 \cdot 10^5) > k \implies f(x) < f(5 \cdot 10^5) \ ∧ \ x < 5 \cdot 10^5 \ ∧ \ x \in [0, \ 5 \cdot 10^5[$$

$$f(5 \cdot 10^5) < k \implies f(x) > f(5 \cdot 10^5) \ ∧ \ x > 5 \cdot 10^5 \ ∧ \ x \in ]5 \cdot 10^5, \ 10^6]$$

- Se a primeira desigualdade for verdadeira, $x$ é menor que o valor do "meio", portanto podemos considerar o intervalo de busca como o início do intervalo original (inclusivo) até o valor do "meio" original (exclusivo)
- Se a segunda desigualdade for verdadeira, $x$ é maior que o valor do "meio", portanto podemos considerar o intervalo de busca como o valor do "meio" original (exclusivo) até o fim do intervalo original (inclusivo)

Em ambos os casos, a quantidade de elementos no intervalo foi reduzida pela metade, e consequentemente o custo de processamento também foi reduzido pela metade.

O processo de escolher o "meio" do intervalo e verificar o valor da função se repete até que o intervalo seja vazio ou o valor de $x$ seja encontrado. Desta forma, ao invés de verificar um valor para $x$ $n$ (tamanho do intervalo original) vezes, podemos verificar somente $\log_2(n)$ vezes, que é a quantidade de vezes que é reduzir o intervalo pela metade até só restar um único elemento. No exemplo acima, para $n = 10^6$, é possível encontrar $x$ em no máximo $20$ iterações.

### Busca binária em array ordenado