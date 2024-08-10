# Breadth first search - Menor caminho em um grafo não valorado

Complexidade de tempo: **$O(v + e)$**  
Complexidade de espaço: **$O(v)$**  

- Onde $v$ e $e$ são, respectivamente, a quantidade de vértices e arestas do grafo.

# Explicação

A ideia do algoritmo é visitar todos os vértices adjacentes ao vértice de origem, depois visitar todos os outros adjacentes a esses e assim sucessivamente. Cada camada de busca corresponde a um movimento - a distância mínima possível entre o vértice que está sendo visitado e o vértice de origem. Dessa forma, é possível determinar a menor distância entre o vértice de origem e todos os outros vértices do grafo (considerando que cada aresta tem peso $1$).

A distância entre o vértice de origem e cada um dos vértices será armazenada em um array de inteiros $dist[]$. Como inicialmente não sabemos as distâncias, iremos definir todas como $-1$. A distância até a origem é sempre $0$. Armazenaremos a distância até cada vértice $v$ em $dist[v]$ (onde $v$ é o número do vértice).

Para cada vértice processado, iremos adicioná-lo a uma fila (queue), que prioriza os primeiros vértices adicionados. Sendo assim, a busca é feita em largura, processando primeiro os vértices na menor profundidade (depht).

Para evitar que um vértice seja processado mais de uma vez (e possivelmente gerar um loop infinito), iremos também definir um array booleano $visitado[]$, inicializado inteiramente como $false$. Ao processar um vértice $v$, marcaremos $visitado[v]$ como $true$. Assim, somente os vértices não-visitados serão processados.

Para cada vértice $v$ (com exceção do vértice de origem), iremos chegar neste partir de outro vértice $u$, portanto, a distância até $v$ será a distância até $u + 1$.

$$u \to v \implies dist[v] = dist[u] + 1$$

No fim, teremos o array definido com todas as distâncias e, as distâncias que estiverem ainda como $-1$ indicam que aquele vértice não é conexo com o vértice de origem. Assim, podemos verificar a menor distância entre o vértice de origem e qualquer outro vértice do grafo em $O(1)$.

Abaixo está um exemplo de um grafo e o funcionamento do algoritmo em questão, com o vértice de origem sendo o $0$.

<p align="center">
   <img src="https://github.com/victorrschmidt/Algoritmos/blob/main/img/bfs_menor_caminho_grafo_1.png" width="480" alt="bfs-img">
</p>

<p align="center">
   <img src="https://github.com/victorrschmidt/Algoritmos/blob/main/img/bfs_menor_caminho_grafo_2.gif" width="480" alt="bfs-gif">
</p>
