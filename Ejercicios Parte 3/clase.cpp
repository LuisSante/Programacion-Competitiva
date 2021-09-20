#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long n, k; 
    int cont = 0;
 
    cin >> n >> k;
    long *numbers = new long[n];
 
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }
 
    for(int i = 0; i < n; i++){
        if(numbers[i] % k == 0)
            cont++;
    }
 
    cout << cont;

    return 0;
}