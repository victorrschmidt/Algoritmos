/*
Complexidade de tempo: O(n*m)
Complexidade de espaço: O(n*m)

- Onde n e m são as dimensões da matriz.

Temos o seguinte problema: Estamos presos em uma caverna, começando na posição inicial 'C', e
queremos determinar o menor número de passos necessários para chegar até a saída da caverna 'F'.
Podemos atravessar todos os espaços vazios '.', e não podemos atravessar os espaços com pedras '#'.
Podemos nos mover para cima, para a direita, para baixo e para a esquerda.

A ideia do algoritmo é visitar todas as células adjacentes à célula inicial,
depois visitar todas as células adjacentes à essas, e assim sucessivamente.
Cada camada de busca corresponde a um movimento - a distância mínima possível
entre a célula inicial e a célula que está sendo visitada.

Assim, é possível determinar a menor distância entre a célula inicial e
a célula final (considerando que cada movimento tem peso 1).

Perceba que a matriz é basicamente um grafo, onde cada célula possui ligação
com suas células adjacentes. As céluas adjacentes são: a célula de cima, da direita,
de baixo e da esquerda.

Abaixo está a representação de uma célula (meio) e suas adjacências:

            | (x, y-1) |
------------------------------------
  (x-1, y)  |  (x, y)  |  (x+1, y)
------------------------------------
            | (x, y+1) |

Ou seja, para analisar as células adjacentes, basta alterar o valor de X ou Y.
Para a célula de cima, diminuímos o Y em 1.
Para a célula da direita, aumentamos o X em 1.
Para a celula de baixo, aumentamos o Y em 1.
Para a célula da esquerda, diminuímos o X em 1.

Então, temos a seguinte notação para as células:

Célula do meio = V

Célula de cima = A
A(X) = V(X) e A(Y) = V(Y) - 1

Célula da direita = B
B(X) = V(X) + 1 e B(Y) = V(Y)

Célula de baixo = C
C(X) = V(X) e C(Y) = V(Y) + 1

Célula da esquerda = D
D(X) = V(X) - 1 e D(Y) = V(Y)

Podemos armazenar a variação dos valores de X e Y em dois arrays:
x[] = {-1,0,1,0}
y[] = {0,1,0,-1}

Obs: Estamos considerando uma matriz representada por um computador,
logo os valores de Y são crescentes de cima para baixo, diferente da
representação em um plano cartesiano.

A matriz utilizada de exemplo está no mesmo diretório deste arquivo.
*/