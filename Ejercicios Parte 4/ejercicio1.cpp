#include<bits/stdc++.h>

using namespace std;

int solution(int A[], int n){
    unsigned long cont_pair = 0;
    int cont_este = 0;
    for(int i = 0; i < n; i++){

        if(A[i]==0){
            cont_este++;
        }

        else if (A[i]==1){
            cont_pair += cont_este;
        }

        if(cont_pair > 1000000000) return -1;
    }
    return cont_pair;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int A[]={0,1,0,1,1};
    int size = sizeof(A) / sizeof(A[0]);
    int n_pases = solution(A,size);
    cout << "Pases: " << n_pases << endl;
    return 0;
}