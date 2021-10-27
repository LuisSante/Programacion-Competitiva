#include<bits/stdc++.h>

using namespace std;

const int max_ = 1e5;

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, data;
    int impares[max_] ,pares[max_];
    int index_p=0 , index_i=0;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>data;

        if(data % 2 == 0){
            pares[index_p] = data;
            index_p++;
        }
        else{
            impares[index_i] = data;
            index_i++;
        }
    }
    sort(pares, pares + index_p);
    sort(impares, impares + index_i);

    for(int i=0; i<index_p; i++){
        cout<<pares[i]<<endl;
    }

    for(int i=0; i<index_i; i++){
        cout<<impares[index_i - 1 - i]<<endl;
    }

    return 0;
}