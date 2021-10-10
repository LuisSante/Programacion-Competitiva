#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n ;
    cin>>n;
    int A[n] , nl[n];
    for(int i = 0; i < n; i++){
        cin>>A[i];
        nl[i] = i-1;
        while(~nl[i] && A[nl[i]] >= A[i]){
            nl[i] = nl[nl[i]];
        }
        cout<<nl[i]+1<<" ";
    }

    return 0;
}

