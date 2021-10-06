#include<bits/stdc++.h>

using namespace std;

long sum_max_array(long A[], int n) {
    long sum_max = A[0];
    long sum_current = A[0];

    for (int i = 1; i < n; i++) {
        sum_current = max(A[i], sum_current + A[i]);
        if (sum_current > sum_max) {
            sum_max = sum_current;
        }
    }

    return sum_max;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dato;
    int n;
    cin>>n;
    long A[n];

    for(int i = 0; i < n; i++){
        cin>>dato;
        A[i] = dato;
    }
    
    cout<<sum_max_array(A,n);
    return 0;
}