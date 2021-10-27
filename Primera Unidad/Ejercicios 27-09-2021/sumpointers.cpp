#include<bits/stdc++.h>

using namespace std;

void sum(int A[], int target, int n){
    int f_pointer = 0;
    int l_pointer = n-1;
    int suma;
    while((suma = A[f_pointer] + A[l_pointer]) != target && f_pointer != l_pointer){
        if(suma < target){
            f_pointer++;
        }

        else if(suma > target){
            l_pointer--;
        }
    }
    cout<<f_pointer<<" "<<l_pointer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A[]={1,2,7,9,11};
    int target = 11;

    /*int A[]={-1,1,2,3,5};
    int target = 5;*/

    /*int A[] = {2,7,11,15};
    int target = 9;*/
    
    int n = sizeof(A)/sizeof(A[0]);
    sum(A,target,n);
    return 0;
}