# --------------------------------------------------------------------------------
# SET
# --------------------------------------------------------------------------------

# ----------------------------------------
# Inicialização
# ----------------------------------------

# Utilizando a função set()

st = set()
# set()

st = set((1, 2, 3))
# {1, 2, 3}

st = set(('cabra', 'macaco', 'galo'))
# {'cabra', 'macaco', 'galo'}

# A função recebe um único parâmetro - um objeto iterável, ou seja,
# os valores devem estar entre parênteses além dos parênteses da função.
# Se colocarmos uma string fora de parênteses, será criado um set com cada char da mesma.

st = set('porco')
# {'p', 'o', 'r', 'c'}


# Colocando os valores entre chaves

st = {1, 2, 3}
# {1, 2, 3}

st = {None, True, False}
# {None, True, False}

# Para inicializar um set vazio, é necessário utilizar a função set(), pois se
# colocarmos um conjunto vazio entre chaves, o Python reconhece o objeto como um dict.

st = {}
type(st)
# <class 'dict'>

# ----------------------------------------
# Métodos
# ----------------------------------------

# set de exemplo
st = set(('rato', 'boi', 'tigre', 'coelho', 'serpente'))


# len(set)
# Retorna o número de elementos contidos no set

len(st)
# 5


# v in set
# Retorna True se o elemento v está contido no set, e False em caso contrário

'serpente' in st
# True

'cavalo' in st
# False


# v not in set
# Retorna True se o elemento não está contido no set, e False em caso contrário

'cavalo' not in st
# True

'serpente' not in st
# False


# set.add(v)
# Adiciona o elemento v ao set

st.add('dragão')
# {'rato', 'boi', 'tigre', 'coelho', 'serpente', 'dragão'}


# set.remove(v)
# Remove o elemento v do set. Se o elemento não existe dentro no set, é levantado um KeyError

st.remove('dragão')
# {'rato', 'boi', 'tigre', 'coelho', 'serpente'}


# set.discard(v)
# Remove o elemento v se o mesmo existir no set

st.discard('tigre')
# {'rato', 'boi', 'coelho', 'serpente'}


# set.clear()
# Remove todos os elementos do set

st.clear()
# {}

# ----------------------------------------
# Iteração
# ----------------------------------------

# Para iterar através dos elementos de um set, podemos utilizar
# o range-based loop, que retorna um iterador do mesmo.

# set de exemplo
st = set((1, 2, 3, 4, 5))

for v in st:
    print(v)

# 1
# 2
# 3
# 4
# 5
