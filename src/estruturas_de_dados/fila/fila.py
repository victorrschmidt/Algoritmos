# --------------------------------------------------------------------------------
# FILA
# --------------------------------------------------------------------------------

'''
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


Em Python, é recomendado utilizar a estrutura "deque" para implementar uma fila, por ser
mais rápida e eficiente.
'''

from collections import deque  # É necessário importar o namespace deque do módulo collections

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

while len(q):
    print(q.popleft())

# 5
# 2
# 3
# 1
# 4