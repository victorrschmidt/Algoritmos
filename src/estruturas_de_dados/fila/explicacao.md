# Fila (_queue_)

Fila é uma estrutura de dados utilizada para armazenar um conjunto de elementos que são organizados na ordem em que são inseridos, sendo os mais "antigos" com a maior prioridade, e os mais "novos" com a menor prioridade. A fila é utilizada quando é necessário armazenar e analisar um conjunto de dados nessa ordem.

## Exemplo:

```cpp
 {5, 4, 3, 8, 9, 2}
  ^              ^
cabeça         cauda
(head)         (tail)
```

Quanto mais à esquerda, mais antigo é o elemento, consequentemente, com maior prioridade. O elemento mais à esquerda é chamado de "cabeça", e o elemento mais à direita é chamado de "cauda".

Para acessar e remover o elemento mais antigo, desenfileiramos o mesmo (_dequeue_).

```cpp
5 <- {4, 3, 8, 9, 2}
      ^           ^
    cabeça      cauda
    (head)      (tail)
```

- Remover o $5$ da fila.

Para adicionar um novo elemento, enfileiramos o mesmo (_enqueue_).

```cpp
 {4, 3, 8, 9, 2, 1} <-
  ^              ^
cabeça         cauda
(head)         (tail)
```

- Adicionar o $1$ na fila.

## Complexidade de tempo

Todas as operações em uma fila possuem complexidade de tempo de $O(1)$.