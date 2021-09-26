#include<bits/stdc++.h>

using namespace std;

int solution(int A, int B, int k){
    int cont = 0;
    for(int i = A ; i <= B ; i++){
        if(i % k == 0){
            cont++;            
        }
    }

    return cont;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int A = 6;
    int B = 11;
    int k = 2;
    int integer = solution(A, B, k);
    cout<<"integer "<<integer<<'\n';
    return 0;
}