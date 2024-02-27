# --------------------------------------------------------------------------------
# DEPTH FIRST SEARCH E FLOOD FILL - COMPONENTES CONEXOS EM UMA MATRIZ
# --------------------------------------------------------------------------------

# Complexidade: O(N*M)
#
# - Onde N e M são as dimensões da matriz.

# O grafo utilizado de exemplo está no mesmo diretório deste arquivo.


L = 10
C = 10

matriz = [
    [],
    [],
    [],
    [],
    [],
    [],
    [],
    [],
    [],
    []
]

adjL = (-1,0,1,0)
adjC = (0,1,0,-1)

# Função Flood Fill
def floodFill(x, y):
    matriz[x][y] = 'V'

    for i in range(4):
        l = x + adjL[i]
        c = y + adjC[i]

        if l >= 0 and c >= 0 and l < L and c < C and matriz[l][c] == '.':
            floodFill(l, c)
        
    
