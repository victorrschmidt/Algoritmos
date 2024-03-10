// --------------------------------------------------------------------------------
// MAP
// --------------------------------------------------------------------------------

/*
* Map é uma estrutura de dados utilizada para armazenar um conjunto de elementos que
* podem ser acessados através de suas respectivas chaves. Essa função de acesso é conhecida
* como função hash. A vantagem do map é que o mesmo permite atribuir uma informação à uma
* chave de acesso de um tipo arbitrário (número, string, boolean).
*/

// ----------------------------------------
// Inicialização
// ----------------------------------------

// Utilizando o construtor Map()

let mp = new Map();
// {}

let mp = new Map([["um", 1], ["dois", 2], ["tres", 3]]);
// {'um': 1, 'dois': 2, 'tres': 3}

let mp = new Map([[1, 10], [2, 20], [3, 30]]);
// {1: 10, 2: 20, 3: 30}

// Em Javascript, o map é semelhante a um objeto. Ambos possuem atribuição e acesso
// de valores através da função hash. Porém, o objeto não é performático para adicionar e 
// remover chaves, além de não possuir os métodos de um map.

// Para ver as diferenças entre map e objeto, acesse o link abaixo:
// https://developer.mozilla.org/pt-BR/docs/Web/JavaScript/Reference/Global_Objects/Map#objetos_vs._maps

// ----------------------------------------
// Métodos
// ----------------------------------------

// map de exemplo
let mp = new Map([["ichi", 1], ["ni", 2], ["san", 3], ["yon", 4], ["go", 5]]);


// map.size
// Retorna a quantidade de chaves no map

mp.size;
// 5


// map.set(chave, valor)
// Cria uma chave com o valor especificado

mp.set("roku", 6);
// {'ichi': 1, 'ni': 2, 'san': 3, 'yon': 4, 'go': 5, 'roku': 6}


// map.get(chave)
// Retorna o valor atribuído a chave

mp.get("ichi")
// 1


// map.has(chave)
// Retorna true se a chave está definida no map, e false em caso contrário

mp.has("san");
// true

mp.has("nana");
// false


// map.delete(chave)
// Remove a chave se a mesma existir no map

mp.delete("roku");
// {'ichi': 1, 'ni': 2, 'san': 3, 'yon': 4, 'go': 5}


// map.clear()
// Remove todas as chaves do map

mp.clear();
// {}

// ----------------------------------------
// Iteração
// ----------------------------------------

// Para iterar através dos elementos de um map, podemos utilizar 
// o método map.entries(), que retorna um iterador do mesmo. Cada elemento
// do iterador será um array no formato [chave, valor].

// map de exemplo
let mp = new Map([["bulbassauro", 1], ["charmander", 4], ["squirtle", 7]]);

for (let [chave, valor] of mp.entries()) {
    console.log(`${chave}: ${valor}`);
}

// bulbassauro: 1
// charmander: 4
// squirtle: 7