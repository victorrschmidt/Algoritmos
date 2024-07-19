# --------------------------------------------------------------------------------
# PILHA
# --------------------------------------------------------------------------------

'''
Pilha (stack) é uma estrutura de dados utilizada para armazenar um conjunto de elementos
que são organizados na ordem que são inseridos, sendo os mais "novos" com a maior prioridade,
e os mais "antigos" com a menor prioridade. A pilha é utilizada quando é necessário
armazenar e analisar um conjunto de dados em ordem.

Exemplo de pilha:

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


Em Python, é recomendado utilizar a estrutura "deque" para implementar uma pilha, por ser
mais rápida e eficiente.
'''

from collections import deque  # É necessário importar a classe deque do módulo collections

# ----------------------------------------
# Inicialização
# ----------------------------------------

# Utilizando o construtor deque()

stk = deque()
# []

# ----------------------------------------
# Métodos
# ----------------------------------------

# stack de exemplo
stk = deque()


# len(deque)
# Retorna a quantidade de elementos presentes na pilha

len(stk)
# 0


# deque.append(item)
# Adiciona o item à pilha (topo)

stk.append(1)
# [1]


# deque.pop()
# Remove e retorna o elemento prioritário (topo) da pilha

stk.pop()
# 1

# ----------------------------------------
# Iteração
# ----------------------------------------

# Iterar através de uma pilha consiste em acessar seus elementos utilizando seus métodos.

# stack de exemplo
stk = deque()

stk.append(5)
stk.append(2)
stk.append(3)
stk.append(1)
stk.append(4)

while stk:
    print(stk.pop())

# 4
# 1
# 3
# 2
# 5
