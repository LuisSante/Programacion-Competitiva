#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;
/*[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]*/

int DFS(vector<vector<int>>& grid, int i , int j){
    if(i<0 || i>= grid.size() || j<0 || j>= grid[i].size() || grid[i][j] == 0) return 0;

    grid[i][j] = 0 ; 
    return (1 + DFS(grid,i+1,j) + DFS(grid,i-1,j) + DFS(grid,i,j+1) + DFS(grid,i,j-1));
}

int maxAreaOfIsland(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    int max_area_ = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                max_area_ = max(max_area_ , DFS(grid,i,j));
            }
        }
    }
    return max_area_;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    cout<<maxAreaOfIsland(grid);
    return 0;
}   