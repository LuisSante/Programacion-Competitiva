#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int n = grid.size(), m = grid[0].size();
    k = k % (n * m);
    vector<vector<int>> res(n, vector<int>(m));
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++){
            int index = (i * m + j + k) % (n * m);
            res[index / m][index % m] = grid[i][j];
        }
    return res;
}


int main() {

    return 0;
}