# --------------------------------------------------------------------------------
# FILA
# --------------------------------------------------------------------------------

from collections import deque  # É necessário importar a classe deque do módulo collections

# ----------------------------------------
# Inicialização
# ----------------------------------------

# Utilizando o construtor deque()

q = deque()
# []

# ----------------------------------------
# Métodos
# ----------------------------------------

# queue de exemplo
q = deque()


# len(deque)
# Retorna a quantidade de elementos presentes na fila

len(q)
# 0


# deque.append(item)
# Adiciona o item à fila (cauda)

q.append(1)
# [1]

q.append(3)
# [1, 3]


# deque[0]
# Retorna o elemento prioritário (cabeça) da fila

q[0]
# 1


# deque[-1]
# Retorna o elemento menos prioritário (cauda) da fila

q[-1]
# 3


# deque.popleft()
# Remove e retorna o elemento prioritário (cabeça) da fila

q.popleft()
# 1

# ----------------------------------------
# Iteração
# ----------------------------------------

# Iterar através de uma fila consiste em acessar seus elementos utilizando seus métodos.

# queue de exemplo
q = deque()

q.append(5)
q.append(2)
q.append(3)
q.append(1)
q.append(4)

while q:
    print(q.popleft())

# 5
# 2
# 3
# 1
# 4
