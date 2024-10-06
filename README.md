# Algoritmos e Estruturas de dados

# Introdução

Algoritmo, em Ciência da Computação, é uma sequência de instruções - cálculos, comparações, repetições e processamentos - a serem seguidas por um sistema a fim de determinar a resposta/solução para um determinado problema.

Além disso, estrutura de dados é a forma à qual as informações estão dispostas dentro do sistema. Arrays, strings, filas e árvores são exemplos de estruturas de dados, e são utilizadas de acordo com a necessidade ou conveniência de suas aplicações.

O objetivo deste projeto é catalogar e explicar diferentes algoritmos e estruturas de dados, como também mostrar suas implementações para processar diferentes tipos de problemas.

# Fontes

Este repositório está atrelado ao site [**Algoritmos e Estruturas de dados**](https://victorrschmidt.gitbook.io/algoritmos), cuja estrutura segue o mesmo padrão. Sinta-se à vontade para reportar ou submeter um PR caso encontre um erro em algum arquivo.

Este projeto é inspirado no repositório [**Algorithms**](https://github.com/williamfiset/Algorithms) de William Fiset e no livro [_Competitive Programmer’s Handbook_](https://cses.fi/book/book.pdf) de Antti Laaksonen.

# Conteúdo

## Estruturas de dados
- [**Set**](src/estruturas_de_dados/set/explicacao.md)
- [**Map**](src/estruturas_de_dados/map/explicacao.md)
- [**Fila (Queue)**](src/estruturas_de_dados/fila/explicacao.md)
- [**Pilha (Stack)**](src/estruturas_de_dados/pilha/explicacao.md)

## Ordenação (sorting)
- [**Busca binária**](src/sorting/busca_binaria/explicacao.md) **- $O(\log(n))$**

## Programação dinâmica
- [**Generalização**](src/programacao_dinamica/generalizacao/explicacao.md)

## Grafos
### Componentes conexos
- [**Depth-first search (componentes conexos em um grafo)**](src/grafos/componentes_conexos/dfs_componentes_conexos_grafo/explicacao.md) **- $O(v + e)$**
- [**Depth-first search/Flood fill (componentes conexos em uma matriz)**](src/grafos/componentes_conexos/dfs_componentes_conexos_matriz/explicacao.md) **- $O(n \cdot m)$**
### Menor caminho
- [**Breadth-first search (menor caminho em um grafo não valorado)**](src/grafos/menor_caminho/bfs_menor_caminho_grafo/explicacao.md) **- $O(v + e)$**
- [**Breadth-first search (menor caminho em uma matriz)**](src/grafos/menor_caminho/bfs_menor_caminho_matriz/explicacao.md) **- $O(n \cdot m)$**

## Matemática
- [**Exponenciação rápida**](src/matematica/exponenciacao_rapida/explicacao.md) **- $O(\log(e))$**
### Números primos
- [**Primalidade**](src/matematica/numeros_primos/primalidade/explicacao.md) **- $O(√n)$**
- [**Crivo de Eratóstenes**](src/matematica/numeros_primos/crivo_eratostenes/explicacao.md) **- $O(n \cdot \log(\log(n)))$**