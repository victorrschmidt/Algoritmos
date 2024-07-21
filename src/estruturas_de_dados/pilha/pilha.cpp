// --------------------------------------------------------------------------------
// PILHA
// --------------------------------------------------------------------------------

#include <stack>  // É necessário incluir a biblioteca homônima

// ----------------------------------------
// Inicialização
// ----------------------------------------

// Utilizando o construtor stack<tipo_de_dado>

stack<int> stk;
stack<char> stk;
stack<string> stk;
// {}

// ----------------------------------------
// Métodos
// ----------------------------------------

// stack de exemplo
stack<int> stk;


// stack.size()
// Retorna a quantidade de elementos presentes na pilha

stk.size();
// 0


// stack.empty()
// Retorna 1 se a pilha estiver vazia (stack.size() == 0), e 0 em caso contrário

stk.empty();
// 1


// stack.push(item)
// Adiciona o item à pilha (topo)

stk.push(1);
// {1}


// stack.top()
// Retorna o elemento prioritário (topo) da pilha

stk.top();
// 1


// stack.pop()
// Remove o elemento prioritário (topo) da pilha

stk.pop();
// {}

// ----------------------------------------
// Iteração
// ----------------------------------------

// Iterar através de uma pilha consiste em acessar seus elementos utilizando seus métodos.

// stack de exemplo
stack<int> stk;

stk.push(5);
stk.push(2);
stk.push(3);
stk.push(1);
stk.push(4);

while (!stk.empty()) {
    std::cout << stk.top() << '\n';
    stk.pop();
}

// 4
// 1
// 3
// 2
// 5
