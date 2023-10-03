# Algoritmos e Estruturas de dados

Algoritmo, do latim _algorismus_, em Ciência da Computação, é um conjunto de instruções - cálculos, comparações, repetições, processamentos a serem seguidos por um sistema a fim de encontrar uma resposta/solução para um determinado problema. Além disso, o caminho até a solução deve ser o mais eficiente possível para otimizar o uso de tempo e armazenamento.

Por sua vez, Estrutura de dados se refere à maneira com que as informações estão dispostas dentro de um sistema. Arrays, strings, filas e árvores são exemplos de estruturas de dados, e são utilizadas de acordo com a necessidade e/ou conveniência de suas aplicações.

O objetivo deste repositório é mostrar alguns algoritmos que podem ser implementados para solucionar problemas gerais ou específicos, buscando sempre uma boa performance. Cada algoritmo está comentado para melhor compreensão de seu funcionamento.

Este projeto é inspirado no repositório **[Algorithms](https://github.com/williamfiset/Algorithms)** de William Fiset e no livro _Competitive Programmer’s Handbook_ de Antti Laaksonen. Os grafos utilizados foram feitos no site **[Graph Online](https://graphonline.ru)**.

# Linguagens

Os algoritmos deste repositório estão disponíveis nas seguintes linguagens:

<img src="https://skillicons.dev/icons?i=c,cpp,js" alt="c-cpp-javascript">

# Conteúdo

## Estruturas de dados

## Conceitos gerais

### Range queries

- Prefix sum (soma de prefixos para calcular soma em um intervalo) **- O(N+Q)** 

## Grafos

### Geral

- Depth-first search (componentes conexos em um grafo) **- O(V+E)**
- Depth-first search e Flood fill (componentes conexos em uma matriz) **- O(N*M)**

### Menor caminho

- **[Breadth-first search (menor caminho em um grafo não valorado)](src/grafos/bfs_menor_caminho_grafo) - O(V+E)**
- Breadth-first search (menor caminho em uma matriz) **- O(N*M)**
- Floyd-Warshall (menor caminho entre todos os pares de vértices) **- O(V<sup>3</sup>)**
