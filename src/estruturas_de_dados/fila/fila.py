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
