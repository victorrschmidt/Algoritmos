// --------------------------------------------------------------------------------
// FILA
// --------------------------------------------------------------------------------

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

q.push(3);
// {1, 3}


// q.front()
// Retorna o elemento prioritário (cabeça) da fila

q.front();
// 1


// q.back()
// Retorna o elemento menos prioritário (cauda) da fila

q.back();
// 3


// q.pop()
// Remove o elemento prioritário (cabeça) da fila

q.pop();

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
