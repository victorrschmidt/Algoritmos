# --------------------------------------------------------------------------------
# CRIVO DE ERATÓSTENES
# --------------------------------------------------------------------------------

'''
Complexidade: O(n*log(log(n)))

- Onde n é o número limite a ser considerado.

O Crivo de Eratóstenes é um algoritmo antigo utilizado para encontrar números primos 
no intervalo [0, n], onde n é um número natural arbitrário utilizado como limite.

O algoritmo funciona da seguinte forma:

Início

    Primeiro definimos um número natural n como o limite para o intervalo [0, n].

    Em seguida, geramos uma lista booleana primos[] de tamanho n+1 contendo todos os valores 
    definidos como True. Ela será utilizada para armazenar a informação de primalidade de
    um número, ou seja, para saber se um número arbitrário x é primo, bastar verificar em
    primos[x] (x deve pertencer ao intervalo [0, n]).
    
    Os números 0 e 1 são casos especiais, e são definidos como False no início do algoritmo.

Funcionamento

    Supomos que o número limite n = 10.
    
    Definimos um ponteiro P que será utilizado para iterar através os elementos de primos[].
    Inicialmente, P = 2, o primeiro número primo.
    
    Em seguida, iremos definir como False todos os múltiplos de P no intervalo [P * P, n].

    
    [False, False, True, True, False, True, False, True, False, True, False]
       0      1      2     3     4      5     6      7     8      9    10
                                 ^            ^            ^           ^
    

    Após isso, iremos incrementar o valor de P em 1, ou seja, P = 3.

    Iremos verificar que primos[P] é True, logo faremos o mesmo processo, definir como
    False todos os múltiplos de P no intervalo [P * P, n].

    
    [False, False, True, True, False, True, False, True, False, False, False]
       0      1      2     3     4      5     6      7     8      9     10
                                                                  ^


    Após isso, iremos incrementar o valor de P em 1, ou seja, P = 4.

    Observe que P * P > n, ou seja, o valor de P agora ultrapassa o intervalo limitado por n.
    Ou seja, no algoritmo, o valor de P estará no intervalo [2, √n], visto que se P > √n,
    consequentemente P * P > n.

Terminus

    Quando o valor de P ultrapassar o valor de √n, o algoritmo se encerra, e teremos a lista
    primos[] definida. Com isso, podemos responder se um número arbitrário x é primo em O(1).

Uma visualização do funcionamento do algoritmo pode ser vista no link abaixo:
https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes#/media/File:Animation_Sieve_of_Eratosth.gif
'''

from math import sqrt  # Importar a função sqrt (raiz quadrada)

def crivo(n):
    primos = [True for i in range(n+1)]  # Lista de primos com todos os elementos inicializados como True

    primos[0] = primos[1] = False  # Casos especiais: 0 e 1 não são primos
    
    for p in range(2, int(sqrt(n)) + 1):  # Iteração de p no intervalo [2, √n]
        if not primos[p]:  # Se o número não é primo
            continue  # Continuar a iteração
        
        for i in range(p * p, n+1, p):  # Iteração de i (múltiplos de p) no intervalo [p * p, n]
            primos[i] = False  # Definir o número como não-primo

    return primos  # Retornar a lista

print(crivo(14))

# [False, False, True, True, False, True, False, True, False, False, False, True, False, True, False]
#    0      1      2     3     4      5     6      7     8      9     10     11    12     13    14
#                primo primo        primo        primo                      primo        primo