// --------------------------------------------------------------------------------
// set
// --------------------------------------------------------------------------------

// ----------------------------------------
// Inicialização
// ----------------------------------------

// Utilizando o construtor Set()

let st = new Set();
// {}

let st = new Set([1, 2, 3]);
// {1, 2, 3}

let st = new Set(["cabra", "macaco", "galo"]);
// {'cabra', 'macaco', 'galo'}

let st = new Set([null, true, false]);
// {null, true, false}

// A função recebe um único parâmetro - um objeto iterável, ou seja,
// os valores devem estar entre colchetes além dos parênteses dentro da função.
// Se colocarmos uma string fora de colchetes, será criado um set com cada char da mesma.

let st = new Set("porco");
// {'p', 'o', 'r', 'c'}

// ----------------------------------------
// Métodos
// ----------------------------------------

// set de exemplo
let st = new Set(["rato", "boi", "tigre", "coelho", "serpente"]);

// set.size
// Retorna o número de elementos contidos no set

st.size;
// 5

// set.has()
// Retorna true se o elemento v está contido no set, e false em caso contrário

st.has("serpente");
// true

st.has("cavalo");
// false

// set.add(v)
// Adiciona o elemento v ao set

st.add("dragão");
// {'rato', 'boi', 'tigre', 'coelho', 'serpente', 'dragão'}

// set.delete(v)
// Remove o elemento v se o mesmo existir no set

st.delete("tigre");
// {'rato', 'boi', 'coelho', 'serpente'}

// set.clear()
// Remove todos os elementos do set

st.clear();
// {}

// ----------------------------------------
// Iteração
// ----------------------------------------

// Para iterar através dos elementos de um set, podemos utilizar 
// o método set.values(), que retorna um iterador do mesmo

// set de exemplo
let st = new Set([1, 2, 3, 4, 5]);

for (let v of st.values()) {
    console.log(v);
}

// 1
// 2
// 3
// 4
// 5