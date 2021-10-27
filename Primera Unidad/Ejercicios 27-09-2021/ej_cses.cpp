#include<bits/stdc++.h>

using namespace std;

void sum(int A[], int target, int size_array){
    int f_pointer = 0;
    int l_pointer = size_array-1;
    int suma;
    while((suma = A[f_pointer] + A[l_pointer]) != target && f_pointer != l_pointer){
        if(suma < target){
            f_pointer++;
        }

        else if(suma > target){
            l_pointer--;
        }
    }

    if((suma = A[f_pointer] + A[l_pointer]) == target && f_pointer != l_pointer){
        cout<<f_pointer+1<<" "<<l_pointer+1<<endl;
    }

    else {
        cout<<"IMPOSSIBLE";
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size_array , target;
    cin>>size_array>>target;

    cout<<'\n';

    int A[size_array];
    for(int i=0; i<size_array; i++){
        cin>>A[i];
    }

    sum(A,target,size_array);
    return 0;
}