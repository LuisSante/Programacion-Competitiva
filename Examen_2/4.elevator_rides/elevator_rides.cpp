#include<iostream>
#include<algorithm>

using namespace std;

int elevator_rides(int A[], int n, int k){
    pair<int, int> dp[1<<20]; //USAMOS OPERADORES DE BITS(TAMAÑO)
    dp[0] = {0, k+1};
    for (int i = 1; i < (1<<n); i++) {
        dp[i] = {25, 0};
        for (int j = 0; j < n; j++) {
            if (i>>j & 1){ //USAMOS OPERADORES DE BITS
                auto [c, w] = dp[i^(1<<j)];
                if (w + A[j] > k) {
                    c++;
                    w = min(A[j], w);
                }
                else
                    w += A[j];
                dp[i] = min(dp[i], {c, w});
            }
        }
    }
    return dp[(1<<n)-1].first;
}

int main(){    
    int n, k; 
    cin>>n>>k;
    int A[20];
    for (int i = 0; i < n; i++)
        cin>>A[i];
    cout<<elevator_rides(A,n,k);
}