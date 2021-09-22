#include<bits/stdc++.h>

using namespace std;

int A[10]={1,5,7,8,91};
int B[5]={2,44,67,2,3};
const int sizeA = sizeof(A)/sizeof(A[0]);
const int sizeB = sizeof(B)/sizeof(B[0]);

void insertion_sort(int Aux[], int n){
    int i, key, j;

    for (i = 1; i < n; i++){
        key = Aux[i];
        j = i - 1;

        while (j >= 0 && Aux[j] > key){
            Aux[j + 1] = Aux[j];
            j = j - 1;
        }
        Aux[j + 1] = key;
    }
}

void copiar_sort(){
    for(int i = 0 ; i < sizeA ; i++){
        A[i + sizeB] = B[i];
    }

    insertion_sort(A, sizeA);
}

void print(){
    for(int i = 0 ; i < sizeA; i++){
        cout<<A[i]<<" ";
    }
}

int main(){
    copiar_sort();
    print();
    return 0;
}