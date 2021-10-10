#include <bits/stdc++.h>
using namespace std;    

typedef long long ll;

void isPalindrome(char A[], ll size_ , ll a , ll b){
    int same = 0;
    int retro = b-1;
    for(int i = a-1 ; i <= b-1 ; i++){
        if(A[i] == A[retro]){
            same++;
        }
        retro--;
    }    
    if(ceil(b-a+1) == same) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll size_, queries;
    cin>>size_>>queries;
    char A[size_];
    for(int i=0; i<size_; i++){
        cin>>A[i];
    }

    int querie;
    ll k, a ,b;
    char x;
    while(queries--){
        cin>>querie;

        if(querie == 1){
            cin>>k>>x;
            A[k-1] = x;
        }

        else if(querie == 2){
            cin>>a>>b;
            isPalindrome(A,size_ ,a ,b);
        }
    }
    return 0;
}