# --------------------------------------------------------------------------------
# PRIMALIDADE
# --------------------------------------------------------------------------------

'''
Complexidade: O(√n)

- Onde n é o número a ser verificado.

Um número primo é um número natural maior que 1 que só é divisível por 1 e por ele mesmo.
Em contrapartida, um número composto é um número natural maior que 1 e que possui um ou mais
divisores, além do 1 e ele mesmo.

Uma das propriedades dos números compostos (n) é que estes podem ser representados pelo produto
a * b onde a, b < n. Esta propriedade se confirma pelo fato de que, como mostrado anteriormente,
todo número composto possui pelo menos um divisor (fator) que não seja o 1 ou ele mesmo.
Além disso, ou a ou b tem que ser menor ou igual a √n, pois √n * √n = n.

Tendo isso em mente, para um número ser considerado composto, este deve possuir pelo menos um
divisor no intervalo [2, √n]. Dessa forma, para um número ser considerado primo, a definição
anterior deve ser falsa, ou seja, um número primo não pode possuir nenhum divisor no intervalo
[2, √n].

O teste de primalidade é um algoritmo que verifica se um dado número n possui algum divisor no
intervalo [2, √n]. Em caso negativo, o número é primo.
'''

from math import sqrt  # Importar a função sqrt (raiz quadrada)

def primo(n):
    if n < 2:  # Caso especial: um número para ser primo precisa ser maior que 1
        return False

    for i in range(2, int(sqrt(n)) + 1):  # Iteração para cada número no intervalo [2, √n]
        if n % i == 0:  # Se n é divisível por i
            return False  # O número não é primo

    return True  # O número é primo
