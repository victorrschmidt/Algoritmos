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
'''

from queue import Queue  # É necessário importar o namespace Queue do módulo queue

# ----------------------------------------
# Inicialização
# ----------------------------------------

# Utilizando o construtor Queue()

q = Queue()
# []

# ----------------------------------------
# Métodos
# ----------------------------------------

# queue de exemplo
q = Queue()


# queue.qsize()
# Retorna a quantidade de elementos presentes na fila

q.qsize()
# 0


# queue.empty()
# Retorna True se a fila estiver vazia (queue.qsize() == 0), e False em caso contrário

q.empty()
# True


# queue.put(item)
# Adiciona o item à fila (cauda)

q.put(1)
# [1]


# q.get()
# Remove e retorna o elemento prioritário (cabeça) da fila

q.get()
# 1

# ----------------------------------------
# Iteração
# ----------------------------------------

# Iterar através de uma fila consiste em acessar seus elementos utilizando seus métodos.

# queue de exemplo
q = Queue()

q.put(5)
q.put(2)
q.put(3)
q.put(1)
q.put(4)

while not q.empty():
    print(q.get())

# 5
# 2
# 3
# 1
# 4