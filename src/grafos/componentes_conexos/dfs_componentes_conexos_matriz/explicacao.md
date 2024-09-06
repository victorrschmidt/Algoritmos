# Depht-first search/Flood fill - Componentes conexos em uma matriz

Complexidade de tempo: **$O(n \cdot m)$**  
Complexidade de espaço: **$O(n \cdot m)$**  

- Onde $n$ e $m$ são as dimensões da matriz.

Flood fill - preenchimento por inundação é um algoritmo utilizado para determinar a conectividade entre vértices de um grafo a partir de um vértice de origem e, por sua vez, alterar uma informação específica de cada vértice pertencente a esse grupo.

Esse algoritmo é utilizado, por exemplo, na ferramenta de balde de tinta do Microsoft Paint, onde todos os pixels de mesma cor e que estejam ligados ao pixel selecionado têm sua cor alterada.

No exemplo a seguir, temos uma matriz, com as áreas modificáveis '.' e as áreas fixas '#'. A partir disso, queremos modificar uma determinada área dessa matriz a partir de uma célula arbitrária, modificando o valor de todas as células modificáveis e adjacentes à essa por 'V' (utilizando o mesmo conceito do balde de tinta do Paint).

```cpp
{'#','.','.','#','#','#','.','#','#','.','#','#'},
{'#','#','.','#','#','.','.','.','#','#','#','.'},
{'.','#','#','.','.','#','.','.','.','.','.','#'},
{'#','.','.','#','.','.','.','.','#','#','#','#'},
{'.','#','.','#','.','#','.','.','#','.','.','#'},
{'.','.','#','#','#','#','#','.','#','.','.','.'},
{'.','.','#','.','.','#','.','.','#','.','.','#'},
{'.','.','#','.','.','#','#','#','.','.','.','#'},
{'.','#','.','#','.','.','.','#','#','.','#','.'},
{'#','#','.','.','.','.','#','.','.','.','.','.'}
```

A ideia do algoritmo é visitar uma célula adjacente à célula de origem, depois visitar outra adjacente à essa e assim sucessivamente, fazendo uma busca em profundidade até chegarmos em um "beco sem saída". Quando não houver mais células para visitar, iremos voltar a que estava sendo visitada anteriormente (_backtracking_) e procurar outra para visitar.

O algoritmo utiliza recursividade, onde a função chama a si mesma conforme visitamos outras células, colocando as chamadas mais antigas em uma prioridade menor, priorizando as chamadas mais recentes.

Perceba que a matriz é basicamente um grafo, onde cada célula possui ligação (arestas) com suas células adjacentes. As células adjacentes são, nesse caso: a célula de cima, da direita, de baixo e da esquerda.

Abaixo está a representação de uma célula e suas adjacências:

```math
\begin{bmatrix}
  \cdots & i-1,\ j & \cdots \\\\
  i,\ j-1 & i,\ j & i,\ j+1 \\\\
  \cdots  & i+1,\ j  & \cdots
\end{bmatrix}
```

Em resumo, para analisar as células adjacentes, basta alterar o valor de $i$ ou $j$ da célula $c$.

Podemos armazenar a variação dos valores de $i$ e $j$ (começando pela célula de cima, e seguindo no sentido horário) em dois arrays:

$$vi[\ ] = [-1,\ 0,\ 1,\ 0]$$

$$vj[\ ] = [0,\ 1,\ 0,\ -1]$$

Assim, para saber os valores de $i$ e $j$ de uma célula adjacente à célula $c$, basta adicionar os valores dos arrays em uma posição $k$. Considerando $s$, $d$, $b$ e $e$ como as células de cima, direita, baixo e esquerda, temos a seguinte notação para os valores de $i$ e $j$ de cada.

$$s_{i} = c_{i} + vi[0],\ s_{j} = c_{j} + vj[0]$$

$$d_{i} = c_{i} + vi[1],\ d_{j} = c_{j} + vj[1]$$

$$b_{i} = c_{i} + vi[2],\ b_{j} = c_{j} + vj[2]$$

$$e_{i} = c_{i} + vi[3],\ e_{j} = c_{j} + vj[3]$$

Abaixo está o resultado da matriz após utilizar o algoritmo em questão, nas coordenadas $i = 2$, $j = 6$ ($0$-indexada).

```cpp
{'#','.','.','#','#','#','V','#','#','.','#','#'},
{'#','#','.','#','#','V','V','V','#','#','#','.'},
{'.','#','#','V','V','#','V','V','V','V','V','#'},
{'#','.','.','#','V','V','V','V','#','#','#','#'},
{'.','#','.','#','V','#','V','V','#','.','.','#'},
{'.','.','#','#','#','#','#','V','#','.','.','.'},
{'.','.','#','.','.','#','V','V','#','.','.','#'},
{'.','.','#','.','.','#','#','#','.','.','.','#'},
{'.','#','.','#','.','.','.','#','#','.','#','.'},
{'#','#','.','.','.','.','#','.','.','.','.','.'}
```