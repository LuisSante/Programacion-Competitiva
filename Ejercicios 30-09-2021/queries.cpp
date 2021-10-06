#include <bits/stdc++.h>
using namespace std;

int size_;

void update(int A[], int k, int u){
    for(int i = 1; i <= size_; i++){
        if(i == k){
            A[i] = u;
        }
    }
}

int maximo(int B[], int tam){
    int max_ = B[0];
    for(int i = 1; i < tam; i++){
        if(B[i] > max_){
            max_ = B[i];
        }
    }

    return max_;
}

void sum_prefix(int A[], int prefix[] , int range_a, int range_b){
    int index;
    prefix[0] = 0;
    for(int i = range_a; i <= range_b; i++){
        index = i- range_a + 1;
        prefix[index] = prefix[index-1] + A[i];
    }   
}

int maximum_sum_prefix(int A[], int prefix[], int range_a, int range_b){
    sum_prefix(A, prefix, range_a, range_b);

    int _size_new = range_b - range_a + 1;
    
    int number_max = maximo(prefix , _size_new);

    return number_max;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int queries; cin>> size_ >>queries;
    int A[size_];

    for(int i=1; i<=size_; i++){
        cin>>A[i];
    }

    int querie, range_a , range_b;
    int prefix[range_b - range_a + 1];
    int k , u;//pos_reemplazo valor_reemplazar
    for(int i=1; i<=queries; i++){
        cin>>querie;

        if(querie==1){
            cin>> k >> u;
            update(A,k,u);
        }

        else if(querie == 2){
            cin >> range_a >> range_b ;
            cout<<maximum_sum_prefix(A,prefix,range_a,range_b)<<endl;
        }
    }
}