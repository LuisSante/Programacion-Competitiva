#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int uniquePaths(int m, int n) {
    vector<int> dp(n,1);
    dp[0]=1;
  
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] += dp[j-1];
            cout<<dp[j]<<" ";
        }
    }
  
    return dp[n - 1];
}

int main(){
    int m , n;
    cin>>m>>n;
    cout<<uniquePaths(m, n);
    return 0;
}