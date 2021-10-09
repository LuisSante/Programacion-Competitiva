#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void reverse(ll A[], ll size_, ll range_a, ll range_b){
    ll last = range_b-1;
    ll medium = floor((range_a-1 + range_b-1)/2);
    for(int i = range_a-1; i <= medium; i++){
        ll temp = A[i];
        A[i] = A[last];
        A[last] = temp;
        last--;
    }
}

ll sum_array(ll A[], ll size_, ll a , ll b){
    ll sum = 0;
    for(int i=a-1; i<=b-1; i++){
        sum+=A[i];
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll size_, queries;
    cin>>size_>>queries;
    ll A[size_];
    for(int i=0; i<size_; i++){
        cin>>A[i];
    }

    int querie;
    ll range_a, range_b, a ,b;
    while(queries--){
        cin>>querie;

        if(querie == 1){
            cin>>range_a>>range_b;
            reverse(A,size_,range_a ,range_b);
        }

        else if(querie == 2){
            cin>>a>>b;
            cout<<sum_array(A,size_,a ,b)<<endl;
        }
    }

    return 0;
}