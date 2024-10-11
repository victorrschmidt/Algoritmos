# Set

Set é uma estrutura de dados utilizada para armazenar um conjunto de elementos distintos (do mesmo tipo de dado, em _C++_). A vantagem de utilizar o set é que o mesmo permite acessar um elemento arbitrário em seu conjunto (verificar a presença ou ausência do elemento), sem precisar iterar todo o objeto.

Os sets são implementados internamente através de uma [árvore binária (_binary tree_)](/src/estruturas_de_dados/arvore_binaria/explicacao.md). Dessa forma, além de manter o conjunto de elementos, também é possível acessá-los de forma ordenada através de seu iterador.

## Complexidade de tempo

- Inserção, remoção e pesquisa (_lookup_): **$O(\log(n))$**, onde $n$ é o número de elementos presentes no set.
- Outras: **$O(1)$**
