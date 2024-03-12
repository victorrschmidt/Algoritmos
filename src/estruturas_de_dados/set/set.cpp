// --------------------------------------------------------------------------------
// SET
// --------------------------------------------------------------------------------

/*
Set é uma estrutura de dados utilizada para armazenar um conjunto de elementos distintos 
(do mesmo tipo de dado, em C++). A vantagem do set é que o mesmo permite acessar um elemento 
arbitrário em seu conjunto (verificar a presença ou ausência do elemento), sem precisar 
iterar todo o objeto.
*/

#include <set>  // É necessário incluir a biblioteca homônima

// ----------------------------------------
// Inicialização
// ----------------------------------------

// Utilizando o construtor set<tipo_de_dado>

set<int> st;
set<char> st
set<string> st;
// {}

set<int> st({1, 2, 3});
// {1, 2, 3}

set<string> st({"cabra", "macaco", "galo"});
// {"cabra", "macaco", "galo"}

set<bool> st({true, false});
// {1, 0}

// O construtor só pode receber um único parâmetro - uma lista de elementos, ou seja,
// os valores devem estar entre chaves além dos parênteses do construtor.

// ----------------------------------------
// Métodos
// ----------------------------------------

// set de exemplo
set<string> st({"rato", "boi", "tigre", "coelho", "serpente"});


// set.size()
// Retorna o número de elementos contidos no set

st.size();
// 5


// set.contains(v)
// Retorna true se o elemento v está contido no set, e false em caso contrário

st.contains("serpente");
// true

st.contains("cavalo");
// false


// set.insert(v)
// Adiciona o elemento v ao set

st.insert("dragão");
// {"rato", "boi", "tigre", "coelho", "serpente", "dragão"}


// set.erase(v)
// Remove o elemento v se o mesmo existir no set

st.erase("tigre");
// {"rato", "boi", "coelho", "serpente"}


// set.clear()
// Remove todos os elementos do set

st.clear();
// {}

// ----------------------------------------
// Iteração
// ----------------------------------------

// Para iterar através dos elementos de um set, podemos utilizar 
// o range-based loop, que retorna um iterador do mesmo

// set de exemplo
set<int> st({1, 2, 3, 4, 5});

for (auto v : st) {
    std::cout << v << '\n';
}

// 1
// 2
// 3
// 4
// 5