#include<iostream>
#include<vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int minFallingPathSum(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();

    vvi dp(n,vi(m,0));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m; j++){
            if( i == 0){
                dp[i][j] = grid[i][j];
            }else{
                int min_ = INT_MAX;
                for(int k=0;k<m;k++){
                    if(k == j) continue;
                    min_ = min(min_,dp[i-1][k]);
                }
                dp[i][j] = min_ + grid[i][j];
            }
        }
    }

    int ans = INT_MAX;
    for(int i=0;i<m;i++){
        ans = min(ans,dp[n-1][i]);
    }
    return ans;
}

int main(){
    vector<vector<int>> grid = {{1,2,3},
                                {4,5,6},
                                {7,8,9}};
    cout<<minFallingPathSum(grid);
    return 0;
}