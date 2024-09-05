# --------------------------------------------------------------------------------
# EXPONENCIAÇÃO RÁPIDA
# --------------------------------------------------------------------------------

def potencia(b: int, e: int) -> int:
    if e == 0:  # Caso base: b^0 é igual a 1
        return 1
    if e & 1:  # Se o expoente for ímpar, retornar b * b^(e-1)
        return b * potencia(b, e - 1)
    p = potencia(b, e // 2)  # Se o expoente for par, definir p = b^(e/2)
    return p*p  # Retornar p*p = b^(e/2) * b^(e/2)

# ----------------------------------------
# UTILIZANDO MÓDULO
# ----------------------------------------

MOD = 42

def potencia_mod(b: int, e: int) -> int:
    global MOD

    if e == 0:  # Caso base: b^0 é igual a 1
        return 1
    if e & 1:  # Se o expoente for ímpar, retornar b * b^(e-1) % mod
        return b * potencia_mod(b, e - 1) % MOD
    p = potencia_mod(b, e // 2)  # Se o expoente for par, definir p = b^(e/2)
    return p*p % MOD  # Retornar p*p % mod = b^(e/2) * b^(e/2) % mod
