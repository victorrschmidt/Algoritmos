/*
Fila (queue) é uma estrutura de dados utilizada para armazenar um conjunto de elementos
que são organizados na ordem que são inseridos, sendo os mais "antigos" com a maior
prioridade, e os mais "novos" com a menor prioridade. A fila é utilizada quando é necessário
armazenar e analisar um conjunto de dados em ordem.

Exemplo de fila:

 {5, 4, 3, 8, 9, 2}
  ^              ^
cabeça         cauda
(head)         (tail)


Quanto mais à esquerda, mais antigo é o elemento, consequentemente, com maior prioridade.
O elemento mais à esquerda é chamado de "cabeça", e o elemento mais à direita é chamado de
"cauda".


Para acessar e remover o elemento mais antigo, desenfileiramos o mesmo (dequeue).

5 <- {4, 3, 8, 9, 2}
      ^           ^
    cabeça      cauda
    (head)      (tail)

*Remover o 5 da fila.


Para adicionar um novo elemento, enfileiramos o mesmo (enqueue).

 {4, 3, 8, 9, 2, 1} <-
  ^              ^
cabeça         cauda
(head)         (tail)

*Adicionar o 1 na fila.
*/