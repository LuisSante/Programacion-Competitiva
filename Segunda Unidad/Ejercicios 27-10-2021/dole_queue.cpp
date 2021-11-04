#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxn = 21;
int choosen[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,m;
    while((scanf("%d %d %d",&n,&k,&m)) == 3 && n){
        int left = n,a = 0,b = n+1;
        choosen[0] = 1;
        while(left){
            int cnt = 0;
            while(cnt < k){
                a++;
                if(!choosen[a % (n+1)]) cnt++;
            }
            int ac = a % (n+1);
            left--;
            printf("%3d",ac);
            cnt = 0;
            while(cnt < m){
                if(b == 1) b = 11;
                b--;
                if(!choosen[b]) cnt++;
            }
            if(b != ac){
                left--;
                choosen[b] = 1;
                printf("%3d",b);
            }
            choosen[ac] = 1;
            !left ? putchar('\n') : putchar(',');
        }
    }
    return 0;
}