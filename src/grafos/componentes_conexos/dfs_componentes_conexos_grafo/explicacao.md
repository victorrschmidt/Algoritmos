# Depht-first search - Componentes conexos em um grafo não direcionado

Complexidade de tempo: **$O(v + e)$**  
Complexidade de espaço: **$O(v)$**  

- Onde $v$ e $e$ são, respectivamente, a quantidade de vértices e arestas do grafo.

## Explicação

Na Teoria dos grafos, componente conexo é um subgrafo formado por um conjunto de vértices que respeitam a seguinte condição: para cada par de vértices $u$ e $v$, existe ao menos um caminho possível entre $u$ e $v$. Encontrar os componentes conexos de um grafo é um problema que pode ser resolvido com o algoritmo de _Depht-first search_.

A ideia do algoritmo é visitar um vértice adjacente ao vértice de origem, depois visitar outro adjacente a esse e assim sucessivamente, fazendo uma busca em profundidade até chegarmos em um "beco sem saída". Quando não houver mais vértices para visitar, iremos voltar ao que estava sendo visitado anteriormente (_backtracking_) e procurar outro para visitar.

O algoritmo utiliza recursividade, onde a função chama a si mesma conforme visitamos outros vértices, colocando as chamadas mais antigas em uma prioridade menor, priorizando as chamadas mais recentes.

Quando todos os vértices possíveis forem visitados dessa forma, podemos afirmar que todos pertencem ao mesmo grupo, pois conseguimos chegar até eles de alguma forma a partir do vértice de origem. Para determinar quais são os vértices que pertencem a esse grupo, temos um array de inteiros $componente[\ ]$ de tamanho $v$, onde para cada visita iremos armazenar o número do grupo do vértice $v$ em $componente[v]$.

Além disso, para evitar que um vértice seja processado mais de uma vez (e possivelmente gerar um loop infinito), iremos também definir um array booleano $visitado[\ ]$, inicializado inteiramente como _false_. Ao processar um vértice $v$, marcaremos $visitado[v]$ como _true_. Assim, somente os vértices não-visitados serão processados.

Para grafos desconexos temos mais de um grupo e, caso nem todos os vértices tenham sido visitados, iniciaremos outra busca em profundidade a partir do primeiro vértice não visitado na ordem (considerando que os vértices são numerados de $0$ até $v-1$), assim determinando o grupo ao qual cada vértice do grafo pertence.

Abaixo está um exemplo de um grafo com $4$ componentes.

<p align="center">
   <img src="/img/dfs_componentes_conexos_grafo.png" width="480" alt="matriz-caminho">
</p>
