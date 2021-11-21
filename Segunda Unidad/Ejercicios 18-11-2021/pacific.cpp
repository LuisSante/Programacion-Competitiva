#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iterator>

using namespace std;

vector<vector<int>> pacificAtlantic(vector<vector<int>> &M){
    vector<vector<int>> ans;
    if (M.empty())
        return ans;
    int y = M.size(), x = M[0].size();
    vector<char> dp(y * x);
    for (int i = 0; i < y; i++){
        dfs(M, dp, i, 0, 1, 0);
        dfs(M, dp, i, x - 1, 2, 0);
    }
    for (int i = 0; i < x; i++){
        dfs(M, dp, 0, i, 1, 0);
        dfs(M, dp, y - 1, i, 2, 0);
    }
    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++)
            if (dp[i * x + j] == 3)
                ans.push_back({i, j});
    return ans;
}

void dfs(const vector<vector<int>> &M, vector<char> &dp, int i, int j, int w, int h){
    int y = M.size(), x = M[0].size(), ij = i * x + j, newh = M[i][j];
    
    if ((dp[ij] & w) || M[i][j] < h)
        return;
    dp[ij] += w;
    if (i + 1 < y) dfs(M, dp, i + 1, j, w, newh);
    if (i > 0) dfs(M, dp, i - 1, j, w, newh);
    if (j + 1 < x) dfs(M, dp, i, j + 1, w, newh);
    if (j > 0) dfs(M, dp, i, j - 1, w, newh);
}

int main(){
    vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> aux = pacificAtlantic(heights);
    
    return 0;
}