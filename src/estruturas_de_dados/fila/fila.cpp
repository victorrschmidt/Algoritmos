// --------------------------------------------------------------------------------
// FILA
// --------------------------------------------------------------------------------

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

#include <queue>  // É necessário incluir a biblioteca homônima

// ----------------------------------------
// Inicialização
// ----------------------------------------

// Utilizando o construtor queue<tipo_de_dado>

queue<int> q;
queue<char> q;
queue<string> q;
// {}

// ----------------------------------------
// Métodos
// ----------------------------------------

// queue de exemplo
queue<int> q;


// queue.size()
// Retorna a quantidade de elementos presentes na fila

q.size();
// 0


// queue.empty()
// Retorna 1 se a fila estiver vazia (queue.size() == 0), e 0 em caso contrário

q.empty();
// 1


// queue.push(item)
// Adiciona o item à fila (cauda)

q.push(1);
// {1}


// q.front()
// Retorna o elemento prioritário (cabeça) da fila

q.front();
// 1


// q.pop()
// Remove o elemento prioritário (cabeça) da fila

q.pop();
// {}

// ----------------------------------------
// Iteração
// ----------------------------------------

// Iterar através de uma fila consiste em acessar seus elementos utilizando seus métodos.

// queue de exemplo
queue<int> q;

q.push(5);
q.push(2);
q.push(3);
q.push(1);
q.push(4);

while (!q.empty()) {
    std::cout << q.front() << '\n';
    q.pop();
}

// 5
// 2
// 3
// 1
// 4
