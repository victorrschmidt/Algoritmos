# Algoritmos e Estruturas de dados

Algoritmo, do latim _algorismus_, em Ciência da Computação, é um conjunto de instruções - cálculos, comparações, repetições, processamentos a serem seguidos por um sistema a fim de encontrar uma resposta/solução para um determinado problema.

Por sua vez, Estrutura de dados se refere à maneira com que as informações estão dispostas dentro de um sistema. Arrays, strings, filas e árvores são exemplos de estruturas de dados, e são utilizadas de acordo com a necessidade ou conveniência de suas aplicações.

O objetivo deste repositório é mostrar alguns algoritmos e estruturas de dados que podem ser implementados para solucionar problemas gerais ou específicos, buscando sempre uma boa performance. Cada arquivo está comentado para melhor compreensão de seu funcionamento.

Este projeto é inspirado no repositório [**Algorithms**](https://github.com/williamfiset/Algorithms) de William Fiset e no livro [_Competitive Programmer’s Handbook_](https://cses.fi/book/book.pdf) de Antti Laaksonen. Os grafos utilizados foram feitos no site [**Graph Online**](https://graphonline.ru).

Caso você encontre algum erro em algum arquivo, sinta-se à vontade para reportá-lo e/ou criar um PR.

# Linguagens

Os algoritmos deste repositório estão disponíveis nas seguintes linguagens:

<img src="https://skillicons.dev/icons?i=cpp,js,py" alt="cplusplus-javascript-python">

# Conteúdo

## Estruturas de dados

- [**Pilha (Stack)**](src/estruturas_de_dados/pilha)
- [**Fila (Queue)**](src/estruturas_de_dados/fila)
- [**Set**](src/estruturas_de_dados/set)
- [**Map**](src/estruturas_de_dados/map)

## Grafos

### Geral

- [**Depth-first search (componentes conexos em um grafo)**](src/grafos/geral/dfs_componentes_conexos_grafo) **- O(v+e)**
- [**Depth-first search e Flood fill (componentes conexos em uma matriz)**](src/grafos/geral/dfs_componentes_conexos_matriz) **- O(n*m)**

### Menor caminho

- [**Breadth-first search (menor caminho em um grafo não valorado)**](src/grafos/menor_caminho/bfs_menor_caminho_grafo) **- O(v+e)**
- [**Breadth-first search (menor caminho em uma matriz)**](src/grafos/menor_caminho/bfs_menor_caminho_matriz) **- O(n*m)**

## Matemática

### Números primos

- [**Teste de primalidade**](src/matematica/numeros_primos/primalidade) **- O(√n)**
- [**Crivo de Eratóstenes**](src/matematica/numeros_primos/crivo_eratostenes) **- O(n*log(log(n)))**
