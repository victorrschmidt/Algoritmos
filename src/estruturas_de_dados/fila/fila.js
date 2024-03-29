// --------------------------------------------------------------------------------
// FILA
// --------------------------------------------------------------------------------

/*
Fila (queue) é uma estrutura de dados utilizada para armazenar um conjunto de elementos
que são organizados na ordem que são inseridos, sendo os mais "antigos" com maior
prioridade, e os mais "novos" com menor prioridade. A fila é utilizada quando é necessário
armazenar e analisar um conjunto de dados em ordem.

e.g.

 [5, 4, 3, 8, 9, 2]
  ^              ^
cabeça         cauda
(head)         (tail)


Quanto mais à esquerda, mais antigo é o elemento, consequentemente, com maior prioridade.
O elemento mais à esquerda é chamado de "cabeça", e o elemento mais à direita é chamado de
"cauda".


Para acessar e remover o elemento mais antigo, desenfileiramos o mesmo (dequeue).

5 <- [4, 3, 8, 9, 2]
      ^           ^
    cabeça      cauda
    (head)      (tail)

*Remover o 5 da fila.


Para adicionar um novo elemento, enfileiramos o mesmo (enqueue).

 [4, 3, 8, 9, 2, 1] <-
  ^              ^
cabeça         cauda
(head)         (tail)

*Adicionar o 1 na fila.


O Javascript não possui um objeto nativo do tipo queue. Para implementar esse tipo de estrutura,
é possível utilizar um array e os métodos do mesmo.
*/

// ----------------------------------------
// Inicialização
// ----------------------------------------

// Utilizando o construtor []

let q = [];
// []

// ----------------------------------------
// Métodos
// ----------------------------------------

// queue de exemplo
let q = [];


// queue.length
// Retorna a quantidade de elementos presentes na fila

q.length;
// 0


// queue.push(item)
// Adiciona o item à fila (cauda)

q.push(1);
// [1]


// q.shift()
// Remove e retorna o elemento prioritário (cabeça) da fila

q.shift();
// 1

// ----------------------------------------
// Iteração
// ----------------------------------------

// Iterar através de uma fila consiste em acessar seus elementos utilizando seus métodos.

// queue de exemplo
let q = [];

q.push(5);
q.push(2);
q.push(3);
q.push(1);
q.push(4);

while (q.length) {
    console.log(q.shift());
}

// 5
// 2
// 3
// 1
// 4