#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

int row[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int col[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool isSafe(vector<vector<char>> const &mat, int x, int y, char target){
    return (x >= 0 && x < mat.size()) && (y >= 0 && y < mat[0].size())
        && mat[x][y] == target;
}

void floodfill(vector<vector<char>> &mat, int x, int y, char replacement)
{
    if (mat.size() == 0) {
        return;
    }
    queue<pair<int, int>> q;
    q.push({x, y});

    char target = mat[x][y];

    if (target == replacement) {
        return;
    }

    while (!q.empty()){
        pair<int, int> node = q.front();
        q.pop();

        int x = node.first, y = node.second;

        mat[x][y] = replacement;

        for (int k = 0; k < 8; k++){
            if (isSafe(mat, x + row[k], y + col[k], target)){
                q.push({x + row[k], y + col[k]});
            }
        }
    }
}
 
void printMatrix(vector<vector<char>> const &mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++) {
            cout << setw(3) << mat[i][j];
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<char>> mat ={
        { 'Y', 'Y', 'Y', 'G', 'G', 'G', 'G', 'G', 'G', 'G' },
        { 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'G', 'X', 'X', 'X' },
        { 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'X', 'X', 'X' },
        { 'W', 'W', 'W', 'W', 'W', 'G', 'G', 'G', 'G', 'X' },
        { 'W', 'R', 'R', 'R', 'R', 'R', 'G', 'X', 'X', 'X' },
        { 'W', 'W', 'W', 'R', 'R', 'G', 'G', 'X', 'X', 'X' },
        { 'W', 'B', 'W', 'R', 'R', 'R', 'R', 'R', 'R', 'X' },
        { 'W', 'B', 'B', 'B', 'B', 'R', 'R', 'X', 'X', 'X' },
        { 'W', 'B', 'B', 'X', 'B', 'B', 'B', 'B', 'X', 'X' },
        { 'W', 'B', 'B', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
    };

    int x = 3, y = 9;

    char replacement = 'C';

    floodfill(mat, x, y, replacement);
    printMatrix(mat);
 
    return 0;
}