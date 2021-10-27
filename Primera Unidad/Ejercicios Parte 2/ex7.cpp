#include<iostream>

using namespace std;

void operator_bits(int n){
    auto sign = ((n) & (n-1));

    cout<< sign ;
}

int main(){
    int n;
    cin>>n;
    operator_bits(n);
    return 0;
}