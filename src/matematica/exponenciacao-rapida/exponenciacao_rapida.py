# Função recursiva para calcular b**e
def potencia(b: int, e: int) -> int:
    # Caso base: b**0 é igual a 1
    if e == 0:
        return 1

    # Se o expoente for ímpar
    if e & 1:
        # Retornar b * b**(e-1)
        return b * potencia(b, e - 1)

    # Se o expoente for par, definir p = b**(e/2)
    p = potencia(b, e // 2)

    # Retornar p*p = b**(e/2) * b**(e/2)
    return p*p
