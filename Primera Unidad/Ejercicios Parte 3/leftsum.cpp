#include<bits/stdc++.h>

using namespace std;

int pivot(int A[], int size_){
    int sum = 0;
    int leftsum = 0;
    for (int i=0; i<size_; i++){
        sum += A[i];
    }

    for(int i=0; i<size_; i++){
        if(leftsum == (sum - leftsum - A[i])) return i;
        leftsum += A[i];
    }

    return -1;
}

void print(int A[], int size_){
    for (int i=0; i<size_; i++){
        cout <<A[i]<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size_ = 6;
    int A[] = {1,7,3,6,5,6};
    print(A, size_);
    cout<<'\n';
    cout<<pivot(A, size_);


    return 0;
}