/*#include<bits/stdc++.h>

using namespace std;

void vector_aleatorio(int *A, int size_){
    srand(time(0));
    for (int i=0; i<size_; i++){
        *(A+i) = rand()% size_;
    }
}

int pivot(int *A, int size_){
    vector<int> sum_suf;
    vector<int> sum_pre;
    int sum = 0;
    for (int i=0; i<size_; i++){
        sum_suf[i] += A[i];
    }


}

void print(int *A, int size_){
    for (int i=0; i<size_; i++){
        cout <<*(A+i)<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size_, sum = 0, leftsum = 0;
    cin>>size_;

    int *A = new int[size_];
    vector_aleatorio(A, size_);
    print(A, size_);
    cout<<endl;

 

    return 0;
}*/