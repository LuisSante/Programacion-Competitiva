#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main() {
    double A[1000001];
    A[0] = 0;
    for (int i = 1; i <= 1000000; i++)
        A[i] = A[i - 1] + log10(i);
    int num;
    while (cin >> num)
        cout << (int)A[num] + 1 << '\n';
    return 0;
}