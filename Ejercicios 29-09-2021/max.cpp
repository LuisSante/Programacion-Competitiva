#include<bits/stdc++.h>

using namespace std;

vector<int> maximum;
vector<int> aux_aux;

int mayor(vector<int> aux){
    int max = aux[0];
    for(size_t i = 1; i < aux.size(); i++){
        if(aux[i] > max){
            max = aux[i];
        }
    }
    return max;
}

void array_max(vector<int>& nums, int k){
    for(size_t i = 0; i < nums.size()-2; i++){
        int _mayor;
        for(size_t j = i; j < k+i; j++){
            aux_aux.push_back(nums[j]);
        }
        _mayor = mayor(aux_aux);
        maximum.push_back(_mayor);
        aux_aux.clear();
    }
}

void print(const vector<int> maximum){
    for(size_t i = 0; i < maximum.size(); i++){
        cout<<maximum[i]<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums{1,3,-1,-3,5,3,6,7};
    int k=3;

    array_max(nums,k);
    print(maximum);
    return 0;
}
