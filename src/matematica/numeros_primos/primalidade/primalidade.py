# --------------------------------------------------------------------------------
# PRIMALIDADE
# --------------------------------------------------------------------------------

'''
Complexidade de tempo: O(√n)
Complexidade de espaço: O(1)

- Onde n é o número a ser verificado.

Um número primo é um número inteiro maior que 1 que só é divisível por 1 e por ele mesmo.
Em contrapartida, um número composto é um número inteiro maior que 1 e que possui
um ou mais divisores, além do 1 e ele mesmo.

Uma das propriedades dos números compostos é que: dado um número composto n, esse pode ser representado
pelo produto de dois inteiros a e b, onde a ou b é diferente de 1 ou n. Essa propriedade se confirma
pelo fato de que, como mostrado anteriormente, todo número composto possui pelo menos um divisor (fator)
que não seja o 1 ou ele mesmo.

Por exemplo, a fatoração dos números compostos 8 e 9:

1 x 8       1 x 9
2 x 4       3 x 3
4 x 2       9 x 1
8 x 1

Perceba que os fatores se invertem em certo ponto, onde o primeiro fator passa a ser maior que o segundo.
Esse ponto é simplesmente √n, já que por definição, √n * √n = n, então quando o primeiro fator alcança
o primeiro número maior ou igual a √n, o segundo fator passa a ser menor ou igual ao primeiro fator,
assim repetindo os fatores.

Tendo isso em mente, para um número ser considerado composto, este deve possuir pelo menos um divisor
no intervalo [2, √n]. Dessa forma, para um número ser considerado primo, a definição anterior
deve ser falsa, ou seja, um número primo não pode possuir nenhum divisor no dado intervalo.

O teste de primalidade é um algoritmo que verifica se um dado número n possui algum divisor no
intervalo [2, √n]. Em caso negativo, o número é primo.
'''

def primo(n):
    if n < 2:  # Caso especial: um número para ser primo precisa ser maior que 1
        return False

    i = 2

    while i*i <= n:  # Iteração para cada número no intervalo [2, √n]
        if n % i == 0:  # Se n é divisível por i
            return False  # O número não é primo
        i += 1

    return True  # O número é primo
