// --------------------------------------------------------------------------------
// DEPTH FIRST SEARCH - COMPONENTES CONEXOS EM UM GRAFO
// --------------------------------------------------------------------------------

/*
* Complexidade: O(V+E)
*
*
* O grafo utilizado de exemplo está no mesmo diretório deste arquivo.
*/

const vertices = 12;

let grafo = [
    [5,8,4],
    [7,11],
    [6],
    [],
    [0,8],
    [0],
    [2,9],
    [1,11],
    [0,4],
    [10,6],
    [9],
    [1,7]
];

let id = 0;  // Define o grupo de cada vértice
let componente = Array(vertices);  // Array para identificar o grupo de cada componente
let visitado = Array(vertices).fill(false);  // Array de vértices visitados (todos os elementos inicializados como 'false')

// Função dfs
function dfs(v) {
    visitado[v] = true;  // O vértice passado na função agora é visitado
    componente[v] = id;  // Identificar o id do vértice no array (o grupo ao qual esse vértice pertence é o id atual)

    for (let u of grafo[v]) {  // Iteração para cada vértice adjacente à 'v'
        if (!visitado[u]) {  // Se o vértice 'u' não foi visitado
            dfs(u);  // Chamar a função dfs para 'u'.
        }
    }

}

// Função para identificar os vértices
function encontrarComponentes() {
    for (let i = 0; i < vertices; i++) {  // Iteração para cada vértice no grafo
        if (!visitado[i]) {  // Se o vértice não foi visitado
            id++;  // Aumentar o id (número de grupos)
            dfs(i);  // Chamar a função dfs para esse vértice
        }
    }

}

encontrarComponentes();

// componente = [1, 2, 3, 4, 1, 1, 3, 2, 1, 3, 3, 2]
// id = 4 (4 grupos)