//compilar por c++11
#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

char A[1000005];
int aux1, aux2, l, r, n, res, len;
int B[500];

int main(){
    while (cin>>n && n){
        memset(B, 0, sizeof(B));
        getchar();
        gets(A);
        len = strlen(A);
        aux1 = aux2 = res = 0;
        l = r = 0;
        while (l <= r && r < len){
            while (aux1 <= n && r < len){
                if (B[A[r]] == 0){
                    B[A[r]] = 1;
                    aux1++;
                    if (aux1 > n)
                        break;
                }
                else
                    B[A[r]]++;
                r++;
                aux2++;
            }
            if (aux2 > res)
                res = aux2;
            if (r >= len)
                break;
            while (1)
            {
                B[A[l]]--;
                if (B[A[l]] == 0)
                    break;
                l++;
                aux2--;
            }
            l++;
            aux1--;
            r++;
        }
        cout<<res<<"\n";
    }
    return 0;
}