//compilacion en C++11
#include<vector>
#include<iostream>

#define oo 999999

using namespace std;

int foo(int x, vector<int>& arr){
    int sum = 0;
    while(x > 0){
        int op = (x & (-x));
        sum += arr[x];
        x -= op;
    }
    return sum;
}

void solution(int x, int v,vector<int>& arr ){
    while(x < oo){
        int op = (x & (-x));
        arr[x] += v;
        x += op;
    }
}

int main(){

    int n;
    cin>>n;
    vector<int> arr(oo,0);
    int x;
    int ans;
    for(int i = 1; i <= n; i++){
        cin>>x;
        ans = x - foo(x,arr);
        cout << ans << (i == n ? "\n" : " ");
        solution(x, 1, arr);
    }

    return 0;
}