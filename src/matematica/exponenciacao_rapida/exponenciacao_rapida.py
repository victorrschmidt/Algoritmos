# --------------------------------------------------------------------------------
# EXPONENCIAÇÃO RÁPIDA
# --------------------------------------------------------------------------------

def fpow(b: int, e: int) -> int:
    if e == 0:  # Caso base: b^0 é igual a 1
        return 1
    if e & 1:  # Se o expoente for ímpar, retornar b * b^(e-1)
        return b * fpow(b, e - 1)
    p = fpow(b, e // 2)  # Se o expoente for par, definir p como b^(e/2)
    return p*p  # Retornar p*p = b^(e/2) * b^(e/2)

# ----------------------------------------
# UTILIZANDO MÓDULO
# ----------------------------------------

MOD = 42

def fpow(b: int, e: int) -> int:
    global MOD

    if e == 0:  # Caso base: b^0 é igual a 1
        return 1
    if e & 1:  # Se o expoente for ímpar, retornar b * b^(e-1) % mod
        return b * fpow(b, e - 1) % MOD
    p = fpow(b, e // 2) % MOD  # Se o expoente for par, definir p como b^(e/2) % mod
    return p*p % MOD  # Retornar p*p % mod = b^(e/2) * b^(e/2) % mod
