#include<iostream>

using namespace std;

char A[10]="luisa";
char B[5]="hugo";
const int sizeA = sizeof(A)/sizeof(A[0]);
const int sizeB = sizeof(B)/sizeof(B[0]);


void copiar(){
    for(int i = 0 ; A[i] != '\0' ; i++){
        A[i + sizeB] = B[i];
    }
}

void print(){
    for(int i = 0 ; A[i] != '\0' ; i++){
        cout<<A[i];
    }
}

int main(){
    copiar();
    print();
    return 0;
}