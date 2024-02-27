// --------------------------------------------------------------------------------
// BREADTH FIRST SEARCH - MENOR CAMINHO EM UMA MATRIZ
// --------------------------------------------------------------------------------

/*
* Complexidade: O(N*M)
*
* - Onde N e M são as dimensões da matriz.
*
* Temos o seguinte problema: Estamos presos em uma caverna, começando na posição inicial 'C', e 
* queremos determinar o menor número de passos necessários para chegar até a saída da caverna 'F'.
* Podemos atravessar todos os espaços vazios '.', e não podemos atravessar os espaços com pedras '#'.
* Podemos nos mover para cima, para a direita, para baixo e para a esquerda.
*
* A ideia do algoritmo é visitar todas as células adjacentes à célula inicial,
* depois visitar todas as células adjacentes à essas, e assim sucessivamente.
* Cada camada de busca corresponde a um movimento - a distância mínima possível
* entre a célula inicial e a célula que está sendo visitada.
* 
* Assim, é possível determinar a menor distância entre a célula inicial e
* a célula final (considerando que cada movimento tem peso 1).
*
* Perceba que a matriz é basicamente um grafo, onde cada célula possui ligação 
* com suas células adjacentes. As céluas adjacentes são: a célula de cima, da direita, 
* de baixo e da esquerda.
*
* Abaixo está a representação de uma célula (meio) e suas adjacências:
*
*            | (x, y-1) |
* -----------------------------------
*  (x-1, y)  |  (x, y)  |  (x+1, y)  
* -----------------------------------
*            | (x, y+1) |
*
* Ou seja, para analisar as células adjacentes, basta alterar o valor de X ou Y.
* Para a célula de cima, diminuímos o Y em 1.
* Para a célula da direita, aumentamos o X em 1.
* Para a celula de baixo, aumentamos o Y em 1.
* Para a célula da esquerda, diminuímos o X em 1.
*
* Então, temos a seguinte notação para as células:
*
* Célula do meio = V
*
* Célula de cima = A
* A(X) = V(X) e A(Y) = V(Y) - 1
* 
* Célula da direita = B
* B(X) = V(X) + 1 e B(Y) = V(Y)
*
* Célula de baixo = C
* C(X) = V(X) e C(Y) = V(Y) + 1
*
* Célula da esquerda = D
* D(X) = V(X) - 1 e D(Y) = V(Y)
*
* Podemos armazenar a variação dos valores de X e Y em dois arrays:
* x[] = [-1,0,1,0]
* y[] = [0,1,0,-1]
*
* Obs: Estamos considerando uma matriz representada por um computador,
* logo os valores de Y são crescentes de cima para baixo, diferente da
* representação em um plano cartesiano.
*
* A matriz utilizada de exemplo está no mesmo diretório deste arquivo.
*/

const L = 6;  // Quantidade de linhas da matriz de exemplo
const C = 8;  // Quantidade de colunas da matriz de exemplo

let matriz = [  // Matriz de exemplo
    ['C','.','#','.','.','.','.','#'],
    ['.','.','.','.','#','#','#','.'],
    ['.','#','.','.','.','#','.','.'],
    ['#','.','.','#','.','#','F','#'],
    ['.','.','#','#','.','.','.','.'],
    ['#','.','.','.','.','.','.','#']
];

let posL = 0;  // Posição inicial Y (linha)
let posC = 0;  // Posição inicial X (coluna)

// Função bfs
function bfs() {
    const adjL = [-1,0,1,0];  // Valores a serem somados na posição Y (linha)
    const adjC = [0,1,0,-1];  // Valores a serem somados na posição X (coluna)

    let visitado = Array.from(Array(L), () => Array(C).fill(false));  // Matriz de células visitadas (todas as células inicializadas como 'false')
    visitado[posL][posC] = true;  // Definir a célula inicial como visitada

    let fila = [];  // Fila para verificar cada célula adjacente na matriz
    fila.push([posL, posC]);  // Adicionar a célula inicial na fila ( [eixo X, eixo Y] )

    let c_restantes = 1;  // Células restantes na camada de busca (inicialmente só com a célula inicial). Será utilizado para determinar o número de células em cada camada de busca
    let distancia = 0;  // Contador de distância até a célula final

    while (fila.length) {  // Iteração para cada célula na fila
        let l = fila[0][0];  // Pegar a posição Y (linha) da célula
        let c = fila[0][1];  // Pegar a posição X (coluna) da célula
        fila.shift();  // Remover a célula da fila

        if (matriz[l][c] == 'F') {  // Se essa célula é a célula final
            return distancia;  // Retornar a distância entre a célula inicial e final
        }

        for (let i = 0; i < 4; i++) {  // Iteração para cada célula adjacente à célula que está sendo visitada
            let ll = l + adjL[i];  // Posição Y (linha) da célula a ser visitada
            let cc = c + adjC[i];  // Posição X (coluna) da célula a ser visitada

            if (ll < 0 || cc < 0) continue;  // Se as posições Y ou X da célula não estão na matriz (saíram dos limites da matriz, menores que 0)
            if (ll >= L || cc >= C) continue;  // Se as posições Y ou X da célula não estão na matriz (saíram dos limites da matriz, maiores que o tamanho da matriz)
            if (visitado[ll][cc]) continue;  // Se a célula já foi visitada
            if (matriz[ll][cc] == '#') continue;  // Se a célula é inacessível (pedra)

            // Se qualquer uma das condições acima for verdadeira, a iteração reinicia

            fila.push([ll, cc]);  // Adicionar a célula à fila
            visitado[ll][cc] = true;  // Agora visitamos essa célula
        }

        c_restantes--;  // Diminuir o número de células na camada de busca

        if (c_restantes == 0) {  // Se foram analisadas todas as células nessa camada de busca
            c_restantes = fila.length;  // A próxima camada de busca tem todas as células na próxima camada (tamanho atual da fila)
            distancia++;  // Como teremos que analisar outra camada de busca, a distância aumenta em 1
        }
        
    }

    return -1;  // Não existe caminho possível entre a célula inicial e final
}

console.log(bfs());  // 11