#include<iostream>

using namespace std;

//forma de fibonacci matricial
unsigned long long fibo_matricial(unsigned long long n){
    unsigned long long h,i,j,k,aux;
    h = 1; 
    i = 1;
    j = 0; 
    k = 0;
    while(n>0){
        if(n%2 != 0){
            aux = (h*j);
            j = (h*i) + (j*k) + aux;
            i = (i*k) + aux; 
        }
        aux = (h*h);
        h = (2*h*k) + aux;
        k = (k*k) + aux;
        n = (n/2);
    }
    return j;
}

int main(){
    unsigned long long n = 1000;
    cout<<"fibo( "<<n<<")"<<fibo_matricial(n)<<endl;
    return 0;
}