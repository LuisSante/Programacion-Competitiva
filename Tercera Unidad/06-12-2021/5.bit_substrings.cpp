#include<iostream>

using namespace std;

#define SIZE 1e5

void printArray(int A[],int n){
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
}
 
int Bit_Substrings(int A[],int n){
    int B[1000001];    
    B[0]=0;
 
    for(int i=1;i<n+1;i++){
        B[i]=B[i-1]+A[i-1];
    }
 
    int ANS[1000001];  
    for(int i=0;i<n+1;i++) ANS[i]=0;

    for(int size=0;size<n+1;size++){  
        for(int i=1,j=i+size;j<n+1;i++,j++){
            int unos=0;
            if(B[i]!=B[i-1]) unos++;
            unos+=B[j]-B[i];
            ANS[unos]++;
            
        }
        
    }
    printArray(ANS,n+1);
    
    return 0;    
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string S;
    cin>>S;
    int n = S.size();
    int A[1000001];
    for(int i=0;i<n;i++)
        A[i] = S[i] - '0';
    
    Bit_Substrings(A,n);
 
    return 0;
}