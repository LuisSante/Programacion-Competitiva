#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int maxN = 2e5;
    int n, A[maxN] , nl[maxN];

    cin>>n;
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

