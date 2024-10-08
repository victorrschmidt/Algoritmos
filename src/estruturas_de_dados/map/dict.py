# --------------------------------------------------------------------------------
# DICT
# --------------------------------------------------------------------------------

# ----------------------------------------
# Inicialização
# ----------------------------------------

# Utilizando a função dict()

dt = dict()
# {}

dt = dict(um=1, dois=2, tres=3)
# {'um': 1, 'dois': 2, 'tres': 3}

# Padrão (chave=valor, ..., chave=valor)
# Neste tipo de inicialização, as chaves só podem ser do tipo string

dt = dict([('um', 1), ('dois', 2), ('tres', 3)])
# {'um': 1, 'dois': 2, 'tres': 3}

dt = dict([(1, 10), (2, 20), (3, 30)])
# {1: 10, 2: 20, 3: 30}

# Padrão ([(chave, valor), ..., (chave, valor)]])


# Colocando os valores entre chaves

dt = {}
# {}

dt = {'um': 1, 'dois': 2, 'tres': 3}
# {'um': 1, 'dois': 2, 'tres': 3}

# ----------------------------------------
# Métodos
# ----------------------------------------

# dict de exemplo
dt = {'ichi': 1, 'ni': 2, 'san': 3, 'yon': 4, 'go': 5}


# len(dict)
# Retorna a quantidade de chaves presentes no dict

len(dt)
# 5


# dict[chave]
# Retorna o valor atribuído à chave

dt['ichi']
# 1

# Também é possível fazer atribuição dessa forma
dt['ichi'] = 2
dt['ichi'] -= 1


# chave in dict
# Retorna True se a chave está definida no dict, e False em caso contrário

'san' in dt
# True

'roku' in dt
# False


# chave not in dict
# Retorna True se a chave não está definida no dict, e False em caso contrário

'nana' not in dt
# True

'ni' not in dt
# False


# del dict[chave]
# Remove a chave do dict. Se a chave não está definida, é levantado um KeyError

del dt['go']
# {'ichi': 1, 'ni': 2, 'san': 3, 'yon': 4}


# dict.clear()
# Remove todas as chaves presentes no dict

dt.clear()
# {}


# list(dict)
# Retorna uma lista com as chaves do dict

list(dt)
# ['ichi', 'ni', 'san', 'yon', 'go']

# ----------------------------------------
# Iteração
# ----------------------------------------

# Para iterar através dos elementos de um dict, podemos utilizar
# o método dict.items(), que retorna um iterador do mesmo. Cada elemento
# do iterador será uma tupla no formato (chave, valor).

# dict de exemplo
dt = {'bulbassauro': 1, 'charmander': 4, 'squirtle': 7}

for chave, valor in dt.items():
    print(f"{chave}: {valor}")

# bulbassauro: 1
# charmander: 4
# squirtle: 7
