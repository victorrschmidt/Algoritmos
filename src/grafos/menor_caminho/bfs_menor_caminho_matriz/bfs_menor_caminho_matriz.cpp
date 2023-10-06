// --------------------------------------------------------------------------------
// BREADTH FIRST SEARCH - MENOR CAMINHO EM UMA MATRIZ
// --------------------------------------------------------------------------------

/*
*            | (x, y-1) |
* -----------------------------------
*  (x-1, y)  |  (x, y)  |  (x+1, y)  
* -----------------------------------
*            | (x, y+1) |
*
*
* x[] = {-1,0,1,0}
* y[] = {0,1,0,-1}
*
* Obs: Estamos considerando uma matriz representada por um computador,
* logo os valores de Y são crescentes de cima para baixo, diferente da
* representação em um plano cartesiano.
*/

#include <bits/stdc++.h>
using namespace std;

const int L = 6;  // Quantidade de linhas da matriz
const int C = 8;  // Quantidade de colunas da matriz

char matriz[L][C] = {  // Matriz
    {'C','.','#','.','.','.','.','#'},
    {'.','.','.','.','#','#','#','.'},
    {'.','#','.','.','.','#','.','.'},
    {'#','.','.','#','.','#','F','#'},
    {'.','.','#','#','.','.','.','.'},
    {'#','.','.','.','.','.','.','#'}
};

int posL = 0;  // Posição inicial Y (linha)
int posC = 0;  // Posição inicial X (coluna)

int adjL[] = {-1,0,1,0};  // Valores a serem somados na posição Y (linha)
int adjC[] = {0,1,0,-1};  // Valores a serem somados na posição X (coluna)

int bfs(){

    bool visitado[L][C];  // Matriz de células visitadas

    for(int i = 0; i < L; i++){
        for(int j = 0; j < C; j++){
            visitado[i][j] = false;  // Matriz de células visitadas (todas as células inicializadas como 'false')
        }
    }

    visitado[posL][posC] = true;  // Definir a célula inicial como visitada

    queue<pair<int,int>> fila;  // Fila para verificar cada célula adjacente na matriz
    fila.push(make_pair(posL,posC));  // Adicionar a célula inicial na fila ( {eixo X,eixo Y} )

    int c_restantes = 1;  // Células restantes na camada de busca (inicialmente só com a célula inicial). Será utilizado para determinar o número de células em cada camada de busca
    int distancia = 0;  // Contador de distância até a célula final

    while(!fila.empty()){  // Iteração para cada célula na fila
        int l = fila.front().first;  // Pegar a posição Y da célula (linha)
        int c = fila.front().second;  // Pegar a posição X da célula (coluna)
        fila.pop();  // Remover a célula da fila

        if(matriz[l][c] == 'F'){  // Se essa célula é a célula final
            return distancia;  // Retornar a distância entre a célula inicial e final
        }

        for(int i = 0; i < 4; i++){  // Iteração para cada célula adjacente à célula que está sendo verificada
            int ll = l+adjL[i];  // Posição Y (linha) da célula a ser verificada
            int cc = c+adjC[i];  // Posição X (coluna) da célula a ser verificada

            if(ll < 0 || cc < 0) continue;  // Se as posições Y ou X da célula não estão na matriz (saíram dos limites da matriz, menores que 0)
            if(ll >= L || cc >= C) continue;  // Se as posições Y ou X da célula não estão na matriz (saíram dos limites da matriz, maiores que o tamanho da matriz)
            if(visitado[ll][cc]) continue;  // Se a célula já foi visitada
            if(matriz[ll][cc] == '#') continue;  // Se a célula é inacessível (pedra)

            // Se qualquer uma das condições acima for verdadeira, a iteração reinicia

            fila.push(make_pair(ll,cc));  // Adicionar a célula à fila
            visitado[ll][cc] = true;  // Agora visitamos essa célula
        }

        c_restantes--;  // Diminuir o número de células na camada de busca
        if(c_restantes == 0){  // Se foram analisados todas as células nessa camada de busca
            c_restantes = fila.size();  // A próxima camada de busca tem todas as células na próxima camada (tamanho atual da fila)
            distancia++;  // Como teremos que analisar outra camada de busca, a distância aumenta em 1
        }
    }

    return -1;  // Não existe caminho possível entre a célula inicial e final
}

int main(){
    bfs();  // 11


    return 0;
}