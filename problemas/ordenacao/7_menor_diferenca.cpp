#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Dado um vetor de inteiros não-negativos v, retorne um par de inteiros 
//cuja diferença é a menor possível dentre todas as diferenças possíveis
//entre dois elementos do vetor.
//Exemplo: v = {10, 14, 4, 7}
//menor_diferenca(v) = {4, 7}
//O vetor de entrada não deve ser modificado.
pair<int,int> menor_diferenca(vector<int> &v){
    std::sort(v.begin(),v.end());
    int pri = v.at(0);
    int seg = v.at(1);
    int dif = pri-seg;
    pair<int,int> p;
    for (size_t i = 0; i < v.size()-1; i++)
    {
        pri = v.at(i);
        for (size_t j = 0; j < v.size()-1; j++)
        {
            seg = v.at(j);
            if((pri-seg)<dif){
                dif= pri-seg;
                p = {pri,seg};
            }
        }
        
    }
    return p;
}

int main(){
    vector<int> v = {10, 14, 4, 7};

    pair<int,int> res = menor_diferenca(v);

    cout << res.first << " " << res.second << "\n";

    return EXIT_SUCCESS;
}