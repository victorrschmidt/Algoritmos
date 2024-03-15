// --------------------------------------------------------------------------------
// PILHA
// --------------------------------------------------------------------------------

/*
Pilha (stack) é uma estrutura de dados utilizada para armazenar um conjunto de elementos
que são organizados na ordem que são inseridos, sendo os mais "novos" com maior prioridade,
e os mais "antigos" com menor prioridade. A pilha é utilizada quando é necessário 
armazenar e analisar um conjunto de dados em ordem.

e.g.

[4, 2, 1, 8, 6, 3]
                ^
               topo
               (top)


Quanto mais à direita, mais novo é o elemento, consequentemente, com maior prioridade.
O elemento mais à direita é chamado de "topo".


Para acessar e remover o elemento mais novo, desenfileiramos o mesmo (pop).

[4, 2, 1, 8, 6] -> 3
             ^
           topo
           (top)

*Remover o 3 da pilha.

    
Para adicionar um novo elemento, enfileiramos o mesmo (push).

[4, 2, 1, 8, 6, 5] <- 
                ^
              topo
              (top)

*Adicionar o 5 na pilha.


O Javascript não possui um objeto nativo do tipo stack. Para implementar esse tipo de estrutura, 
é possível utilizar um array e os métodos do mesmo.
*/

// ----------------------------------------
// Inicialização
// ----------------------------------------

// Utilizando o construtor []

let stk = [];
// []

// ----------------------------------------
// Métodos
// ----------------------------------------

// stack de exemplo
let stk = [];


// stack.length
// Retorna a quantidade de elementos presentes na pilha

stk.length;
// 0


// stack.push(item)
// Adiciona o item à pilha (topo)

stk.push(1);
// [1]


// stack.pop()
// Remove e retorna o elemento prioritário (topo) da pilha

stk.pop();
// 1

// ----------------------------------------
// Iteração
// ----------------------------------------

// Iterar através de uma pilha consiste em acessar seus elementos utilizando seus métodos.

// stack de exemplo
let stk = [];

stk.push(5);
stk.push(2);
stk.push(3);
stk.push(1);
stk.push(4);

while (stk.length) {
    console.log(stk.pop());
}

// 4
// 1
// 3
// 2
// 5