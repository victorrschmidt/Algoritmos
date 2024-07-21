
/*
Complexidade de tempo: O(v+e)
Complexidade de espaço: O(v)

- Onde v e 'e' são, respectivamente, a quantidade de vértices e arestas do grafo.

A ideia do algoritmo é visitar todos os vértices adjacentes ao vértice de origem,
depois visitar todos os outros adjacentes a esses e assim sucessivamente.
Cada camada de busca corresponde a um movimento - a distância mínima possível
entre o vértice que está sendo visitado e o vértice de origem.

Assim, é possível determinar a menor distância entre o vértice de origem e
todos os outros vértices do grafo (considerando que cada aresta tem peso 1).
A distância do vértice de origem até cada um dos vértices será armazenada
no array dist[]. Como inicialmente não sabemos a distância até cada vértice,
iremos definir todas as distâncias como -1. Conforme fazemos a travessia
no grafo, armazenamos a distância até o vértice u em dist[u] (onde u é o número do vértice).

No final, teremos o array definido com todas as distâncias e, as distâncias
que estiverem ainda como -1 indicam que aquele vértice não é conexo
com o vértice de origem. Assim, podemos verificar a menor distância entre
o vértice de origem e qualquer outro vértice do grafo em O(1).

O grafo utilizado de exemplo está no mesmo diretório deste arquivo.
*/