#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


//Dado um vetor de inteiros não-negativos v, retorne um vetor com os k inteiros
//mais próximos de x.
//O vetor de entrada não deve ser modificado.
//Exemplo: v = {10, 14, 4, 7, 6, 8, 12, 3, 5, 9}
//k_mais_proximos(v, 7, 3) = {6, 7, 8} (ou outra permutação)
vector<int> k_mais_proximos(vector<int> &v, int x, int k){
    if (k <= 0) return {};
    if (v.size() <= k) return v; // retorna todo vetor se k >= tamanho

    // cria uma cópia para não modificar o vetor original
    vector<int> s = v;

    // ordena pelo critério de distância absoluta a x
    sort(s.begin(), s.end(), [x](int a, int b) {
        return abs(a - x) < abs(b - x);
    });

    // pega os primeiros k elementos
    s.resize(k);
    return s;
}

int main(){
    vector<int> v = {10, 14, 4, 7, 6, 8, 12, 3, 5, 9};

    vector<int> res = k_mais_proximos(v, 7, 3);

    for(auto i : res){
        cout << i << " ";
    }
    cout << "\n";

    return EXIT_SUCCESS;
}