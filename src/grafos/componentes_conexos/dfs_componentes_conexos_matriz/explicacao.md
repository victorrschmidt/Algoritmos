/*
Complexidade de tempo: O(n*m)
Complexidade de espaço: O(1)

- Onde n e m são as dimensões da matriz.

Flood fill - preenchimento por inundação é um algoritmo utilizado para determinar
a conectividade entre vértices de um grafo a partir de um vértice de origem e,
por sua vez, alterar uma informação de cada vértice pertencente a esse grupo conexo.

Esse algoritmo é utilizado, por exemplo, na ferramenta de balde de tinta do
Microsoft Paint, onde todos os pixels de mesma cor e que estejam ligados ao
pixel selecionado têm sua cor alterada.

No exemplo deste algoritmo, temos uma matriz, com as áreas modificáveis '.' e as
áreas fixas '#'. A partir disso, queremos modificar uma determinada área dessa
matriz a partir de uma célula arbitrária, modificando o valor de todas as células
modificáveis e adjacentes à essa por 'V' (utilizando o mesmo conceito do balde do Paint).

A ideia do algoritmo é visitar todas as células adjacentes à célula de origem e
verificar se estas são modificáveis. Em caso positivo, alteramos seu valor e
visitamos todas as células adjacentes à essa, assim repetindo o ciclo inicial.

O algoritmo utiliza recursividade, onde a função chama a si mesma conforme
visitamos outros vértices, colocando as chamadas mais antigas em uma prioridade
menor, priorizando as chamadas mais recentes.

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
*/