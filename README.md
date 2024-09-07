# Algoritmos e Estruturas de dados

Algoritmo, do latim _algorismus_, em Ciência da Computação, é um conjunto de instruções - cálculos, comparações, repetições, processamentos a serem executados por um sistema a fim de encontrar uma resposta/solução para um determinado problema.

Por sua vez, Estrutura de dados se refere à maneira com que as informações estão dispostas dentro do sistema. Arrays, strings, filas e árvores são exemplos de estruturas de dados, e são utilizadas de acordo com a necessidade ou conveniência de suas aplicações.

O objetivo deste repositório é mostrar alguns algoritmos e estruturas de dados que podem ser implementados para solucionar diferentes tipos de problemas, buscando sempre uma boa performance. Cada algoritmo possui um arquivo com a explicação do seu funcionamento.

Este projeto é inspirado no repositório [**Algorithms**](https://github.com/williamfiset/Algorithms) de William Fiset e no livro [_Competitive Programmer’s Handbook_](https://cses.fi/book/book.pdf) de Antti Laaksonen. Os grafos utilizados foram criados através do site [**Graph Online**](https://graphonline.ru).

Caso você encontre algum erro em algum arquivo, sinta-se à vontade para reportá-lo e/ou criar um PR.

# Linguagens

Os algoritmos deste repositório estão disponíveis nas seguintes linguagens:

<img src="https://skillicons.dev/icons?i=cpp,py" alt="cplusplus-python">

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
- [**Teste de primalidade**](src/matematica/numeros_primos/primalidade/explicacao.md) **- $O(√n)$**
- [**Crivo de Eratóstenes**](src/matematica/numeros_primos/crivo_eratostenes/explicacao.md) **- $O(n \cdot \log(\log(n)))$**
