# --------------------------------------------------------------------------------
# CRIVO DE ERATÓSTENES
# --------------------------------------------------------------------------------

'''
Complexidade: O(n*log(log(n)))

- Onde n é o número limite a ser considerado
'''

def crivo(n):
    primos = [True for i in range(n+1)]

    primos[0] = primos[1] = False  # Casos especiais: 0 e 1 não são primos
    
    p = 2
    
    while p * p <= n:
        if primos[p]:
            for i in range(p * p, n+1, p):
                primos[i] = False
        p += 1
        
    return primos

print(crivo(15))
# [False, False, True, True, False, True, False, True, False, False, False, True, False, True, False, False]
#    0      1      2     3     4      5     6      7     8      9     10     11    12     13    14     15