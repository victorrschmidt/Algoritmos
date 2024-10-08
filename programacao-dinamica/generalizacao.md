# Generalização

## Fibonacci top-down

{% tabs %}
{% tab title="C++" %}
```cpp
#include <iostream>
#include <vector>
using namespace std;

// Limite arbitrário de exemplo
int N = 10;

// Array de memorização
vector<int> dp(N+1);

// Array para verificar se um estado
// arbitrário da dp já foi calculado.
vector<bool> calculado(N+1);

// Função recursiva para calcular os números de fibonacci de 1 até n
int fib(int n) {
    // Se o estado n da dp já foi calculado
    if (calculado[n]) {
        // Retornar o estado n da dp
        return dp[n];
    }

    // Definir o estado n da dp como a soma dos estados n-2 e n-1
    dp[n] = fib(n-2) + fib(n-1);

    // Definir o estado n como 'calculado'
    calculado[n] = true;

    // Retornar o estado n da dp
    return dp[n];
}

int main() {
    dp[1] = 0;  // Caso base => fib(1) = 0
    dp[2] = 1;  // Caso base => fib(2) = 1
    calculado[1] = true;
    calculado[2] = true;

    fib(N);  // Chamar a função para o último estado da dp (limite)

    // dp[1...N] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34}

    return 0;
}
```
{% endtab %}

{% tab title="Python" %}
```python
# Limite arbitrário de exemplo
N = 10

# Lista de memorização
dp = [0 for i in range(N+1)]

# Lista para verificar se um estado
# arbitrário da dp já foi calculado.
calculado = [False for i in range(N+1)]

# Função recursiva para calcular os números de fibonacci de 1 até n
def fib(n: int) -> int:
    # Se o estado n da dp já foi calculado
    if calculado[n]:
        # Retornar o estado n da dp
        return dp[n]

    # Definir o estado n da dp como a soma dos estados n-2 e n-1
    dp[n] = fib(n-2) + fib(n-1)

    # Definir o estado n como 'calculado'
    calculado[n] = True

    # Retornar o estado n da dp
    return dp[n]

dp[1] = 0  # Caso base => fib(1) = 0
dp[2] = 1  # Caso base => fib(2) = 1
calculado[1] = True
calculado[2] = True

# Chamar a função para o último estado da dp (limite)
fib(N)

# dp[1...N] = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
```
{% endtab %}
{% endtabs %}



## Fibonacci bottom-up

{% tabs %}
{% tab title="C++" %}
```cpp
#include <iostream>
#include <vector>
using namespace std;

// Limite arbitrário de exemplo
int N = 10;

// Array de tabulação
vector<int> dp(N+1);

int main() {
    dp[1] = 0;  // Caso base => fib(1) = 0
    dp[2] = 1;  // Caso base => fib(2) = 1

    // Iteração para cada estado da dp (com exceção dos casos base)
    for (int i = 3; i <= N; i++) {
        // O i-ésimo estado da dp (i-ésimo número de fibonacci)
        // é a soma dos dois estados anteriores.
        dp[i] = dp[i-2] + dp[i-1];
    }

    // dp[1...N] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34}

    return 0;
}
```
{% endtab %}

{% tab title="Python" %}
```python
# Limite arbitrário de exemplo
N = 10

# Lista de tabulação
dp = [0 for i in range(N+1)]

dp[1] = 0  # Caso base => fib(1) = 0
dp[2] = 1  # Caso base => fib(2) = 1

# Iteração para cada estado da dp (com exceção dos casos base)
for i in range(3, N+1):
    # O i-ésimo estado da dp (i-ésimo número de fibonacci)
    # é a soma dos dois estados anteriores.
    dp[i] = dp[i-2] + dp[i-1]

# dp[1...N] = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
```
{% endtab %}
{% endtabs %}
