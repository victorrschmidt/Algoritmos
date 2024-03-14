# --------------------------------------------------------------------------------
# PILHA
# --------------------------------------------------------------------------------

'''
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
'''

from collections import deque

# ----------------------------------------
# Inicialização
# ----------------------------------------

# ----------------------------------------
# Métodos
# ----------------------------------------

# ----------------------------------------
# Iteração
# ----------------------------------------
