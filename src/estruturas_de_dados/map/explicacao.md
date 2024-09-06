# Map

Map é uma estrutura de dados utilizada para armazenar um conjunto de elementos que possuem uma "chave de acesso". A vantagem do map é que o mesmo permite atribuir uma informação à uma chave de acesso de um tipo arbitrário (número, string, vetor), facilitando a associação entre duas informações distintas.

Os maps são implementados internamente através de uma [árvore binária (_binary tree_)](/src/estruturas_de_dados/arvore_binaria/explicacao.md). Dessa forma, além de manter o conjunto de elementos, também é possível acessá-los de forma ordenada (com base na chave) através de seu iterador.

## Complexidade de tempo

- Inserção, remoção e pesquisa (_lookup_): **$O(log(n))$**, onde $n$ é o número de elementos presentes no map.
- Outras: **$O(1)$**
