// --------------------------------------------------------------------------------
// MAP
// --------------------------------------------------------------------------------

/*
Map é uma estrutura de dados utilizada para armazenar um conjunto de elementos que
podem ser acessados através de suas respectivas chaves. Essa função de acesso é conhecida
como função hash. A vantagem do map é que o mesmo permite atribuir uma informação à uma
chave de acesso de um tipo arbitrário (número, string, boolean), facilitando a associação
entre duas informações distintas.
*/

#include <map>  // É necessário incluir a biblioteca homônima

// ----------------------------------------
// Inicialização
// ----------------------------------------

// Utilizando o construtor map<tipo_de_dado_chave, tipo_de_dado_valor>

map<int, int> mp;
map<char, int> mp;
map<string, string> mp;
// {}

map<string, int> mp{{"um", 2}, {"dois", 2}, {"tres", 3}};
// {"um": 1, "dois": 2, "tres": 3}

map<int, int> mp{{1, 10}, {2, 20}, {3, 30}};
// {1: 10, 2: 20, 3: 30}

// Um map só pode possuir chaves de um único de tipo de dado e valores de um único tipo de dado

// ----------------------------------------
// Métodos
// ----------------------------------------

// map de exemplo
map<string, int> mp{{"ichi", 1}, {"ni", 2}, {"san", 3}, {"yon", 4}, {"go", 5}};


// map.size()
// Retorna a quantidade de chaves no map

mp.size();
// 5


// map.empty()
// Retorna 1 se o map estiver vazio (mp.size() == 0), e 0 em caso contrário

mp.empty();
// 0


// map[chave]
// Retorna o valor atribuído à chave

mp["ichi"];
// 1

// Também é possível fazer atribuição dessa forma
dt["ichi"] = 2;
dt["ichi"]--;


// map.count(chave)
// Retorna 1 se a chave está definida no map, e 0 em caso contrário

mp.count("san");
// 1

mp.count("roku");
// 0


// map.erase(chave)
// Remove a chave se a mesma existir no map

mp.erase("go");
// {"ichi": 1, "ni": 2, "san": 3, "yon": 4}


// map.clear()
// Remove todas as chaves do map

mp.clear();
// {}

// ----------------------------------------
// Iteração
// ----------------------------------------

// Para iterar através dos elementos de um map, podemos utilizar
// o range-based loop, que retorna um iterador do mesmo. Cada elemento
// do iterador será um pair no formato {chave, valor}.

// map de exemplo
map<string, int> mp{{"bulbassauro", 1}, {"charmander", 4}, {"squirtle", 7}};

for (auto [chave, valor] : mp) {
    std::cout << chave << ": " << valor << '\n';
}

// bulbassauro: 1
// charmander: 4
// squirtle: 7
