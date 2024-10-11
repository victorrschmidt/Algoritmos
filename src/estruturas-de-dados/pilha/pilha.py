# --------------------------------------------------------------------------------
# PILHA
# --------------------------------------------------------------------------------

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

stk.append(5)
# [1, 5]


# deque[-1]
# Retorna o elemento prioritário (topo) da pilha

stk[-1]
# 5


# deque.pop()
# Remove e retorna o elemento prioritário (topo) da pilha

stk.pop()
# 5

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
