#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void max_sum_range(ll A[], ll it_1 , ll it_2 , ll tam){
    ll B[tam] = {0};
    B[0] = A[0];

    for(ll i = 1 ; i< tam; i++){
        B[i] = A[i] + B[i-1];
    }

    multiset<ll> s1;
    s1.insert(0);
    ll cont = -INFINITY;

    cont = max(cont,B[it_1-1]);
    int flag = 0;

    for(ll i = it_1 ; i<tam ;i++ ){
        if(i-it_2 >= 0){
            if(flag == 0){
                auto it = s1.find(0);
                s1.erase(it);
                flag = 1;
            }
        }

        if(i-it_1 >= 0){
            s1.insert(B[i-it_1]);
        }

        cont = max(cont,B[i] - *s1.begin());

        if(i-it_2 >= 0){
            auto it = s1.find(B[i-it_2]);
            s1.erase(it);
        }
    }
    cout<<cont<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, it_1 , it_2;
    cin>>n>>it_1>>it_2;
    ll A[n];
    for(ll i = 0; i < n; i++){
        cin>>A[i];
    }
    max_sum_range(A,it_1,it_2,n);
    return 0;
}

