#include<bits/stdc++.h>

using namespace std;

int sub_array(vector<int> A, int k){
    int cont = 0 , sum = 0;

    unordered_map<int,int> map_;
    map_[0] = 1;

    for(auto item:A){
        sum = (sum + item) % k;

        if(sum < 0 ){
            sum += k;
        }
        cont += map_[sum];
        ++map_[sum];
    }

    return cont;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> A{4,5,0,-2,-3,1};
    int k=5;

    cout<<sub_array(A,k);
    return 0;
}