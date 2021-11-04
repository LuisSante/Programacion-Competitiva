#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int DFS(vector<vector<int>>& grid, int i , int j){
    if(i<0 || i>= grid.size() || j<0 || j>= grid[i].size() || grid[i][j] == 0) return 0;

    grid[i][j] = 0 ; 
    return (1 + DFS(grid,i+1,j) + DFS(grid,i-1,j) + DFS(grid,i,j+1) + DFS(grid,i,j-1));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> grid;

    return 0;
}   