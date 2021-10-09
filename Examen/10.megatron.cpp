#include <bits/stdc++.h>
using namespace std;    

typedef long long ll;

void megatron(int A[], ll aux[],int P, int M){

    int flag = 0;
    ll sum = 0, max_ = -1 , total = 9999999999999;

    aux[0] = 0;
        
    for(int i=1; i<=P;i++){
        cin>>A[i];
        sum += A[i];
        aux[i] = sum;
    }

    int index_aux = 0;
    sum = 0;

    for(int i=1 ; i<=P;i++){
        if(flag == 1){
            i--;
        }

        sum = aux[i] - aux[index_aux];
        flag = 0;

        if(sum > M){

            flag = 1;
            index_aux++;
        }

        if(max_ < (i - index_aux)){
            max_ =(i - index_aux);
            total = sum;
        }

        else if(max_ == (i - index_aux)){
            if(total > sum)
                total = sum;
        }
    }

    if(max_==0)
        total=0;

    if(total==9999999999999)
        cout<<"0 0\n";

    else
        cout<<total<<" "<<max_<<endl;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;cin>>T;

    while(T--){

        int P,M;
        cin>>P>>M;
        int A[P+9];
        ll aux[P+9];

        megatron(A,aux,P,M);
    }
    return 0;
}

