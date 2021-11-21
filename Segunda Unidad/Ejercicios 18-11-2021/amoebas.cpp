#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int m, n;
    cin>>m>>n;
    char map[100][101];
    for (int i = 0; i < m; i++) 
        cin >> map[i];
    const int size_ = 100 * 101;
    char visited[size_];
    memset(visited, 0, (size_t)size_);

    int cont = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == '#' && !visited[i * n + j])
            {
                int x = i, y = j;
                int val = 0;
                while (!visited[val = x * n + y])
                {
                    visited[val] = 1;
                    int break_loops = 0;
                    for (int a = -1; a < 2; a++)
                    {
                        for (int b = -1; b < 2;  b++)
                        {
                            if (a != 0 || b != 0)
                            {
                                int _val = (x+a) * n + (y+b);
                                if (_val < 0 || _val >= size_) continue;
                                if (map[x+a][y+b] == '#' && !visited[_val])
                                {
                                    x += a;
                                    y += b;
                                    break_loops = 1;
                                }
                            }
                            if (break_loops) break;
                        }
                        if (break_loops) break;
                    }
                }
                cont++;
            }
        }
    }
    cout<<cont;
    return 0;
}