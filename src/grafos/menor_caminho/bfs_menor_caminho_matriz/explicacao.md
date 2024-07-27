# Breadth first search - Menor caminho em uma matriz

Complexidade de tempo: **$O(n \cdot m)$**  
Complexidade de espaço: **$O(n \cdot m)$**  

- Onde $n$ e $m$ são as dimensões da matriz.

## Explicação

Temos o seguinte problema: Estamos presos em uma caverna, começando na posição inicial 'C', e queremos determinar o menor número de passos necessários para chegar até a saída da caverna 'F'. Podemos atravessar todos os espaços vazios '.', e não podemos atravessar os espaços com pedras '#'. Podemos nos mover para cima, para a direita, para baixo e para a esquerda.

```cpp
{'C','.','#','.','.','.','.','#'},
{'.','.','.','.','#','#','#','.'},
{'.','#','.','.','.','#','.','.'},
{'#','.','.','#','.','#','F','#'},
{'.','.','#','#','.','.','.','.'},
{'#','.','.','.','.','.','.','#'}
```

Esse é um problema trivial que pode ser resolvido utilizando o conceito de grafo e de busca em largura (bfs).

A ideia do algoritmo é visitar todas as células adjacentes à célula inicial, depois visitar todas as células adjacentes à essas, e assim sucessivamente. Cada camada de busca corresponde a um movimento - a distância mínima possível entre a célula inicial e a célula que está sendo visitada.

Para cada célula processada, iremos adicioná-la a uma fila (queue), que prioriza as primeiras células adicionadas. Sendo assim, a busca é feita em largura, processando primeiro as células na menor profundidade (depht). Além disso, criaremos uma matriz booleana $visitado[\ ][\ ]$ inicializada inteiramente como $false$. Ao processar uma célula $c$, marcaremos $visitado[i_{c}][j_{c}]$ como $true$. Assim, somente as células não-visitadas serão processadas.

Assim, é possível determinar a menor distância entre a célula inicial e a célula final (considerando que cada movimento tem peso 1).

Perceba que a matriz é basicamente um grafo, onde cada célula possui ligação (arestas) com suas células adjacentes. As células adjacentes são: a célula de cima, da direita, de baixo e da esquerda.

Abaixo está a representação de uma célula e suas adjacências:

```math
\begin{pmatrix}
  \cdots & i-1,\ j & \cdots \\\\
  i,\ j-1 & i,\ j & i,\ j+1 \\\\
  \cdots  & i+1,\ j  & \cdots
\end{pmatrix}
```

Em resumo, para analisar as células adjacentes, basta alterar o valor de $i$ ou $j$.

Podemos armazenar a variação dos valores de $i$ e $j$ (começando pela célula de cima, e seguindo no sentido horário) em dois arrays:

$$vi[\ ] = [-1,\ 0,\ 1,\ 0]$$

$$vj[\ ] = [0,\ 1,\ 0,\ -1]$$

Assim, para saber os valores de $i$ e $j$ de uma célula adjacente, basta adicionar os valores dos arrays em uma posição $k$. Considerando $c$, $d$, $b$ e $e$ como as células de cima, direita, baixo e esquerda, temos a seguinte notação para os valores de $i$ e $j$ de cada.

$$i_{c} = i + vi[0],\ j_{c} = j + vj[0]$$

$$i_{d} = i + vi[1],\ j_{d} = j + vj[1]$$

$$i_{b} = i + vi[2],\ j_{b} = j + vj[2]$$

$$i_{e} = i + vi[3],\ j_{e} = j + vj[3]$$

Colocando o algoritmo em prática, é possível determinar o menor caminho entre duas células da matriz. Abaixo está um dos caminhos ótimos possíveis para a matriz utilizada de exemplo no início.

<p align="center">
   <img src="https://github.com/victorrschmidt/Algoritmos/blob/main/img/bfs_menor_caminho_matriz_1.png" width="480" alt="matriz-caminho">
</p>
