//https://open.kattis.com/problems/collatz

#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

vector<ll> solution(ll x_0){
    vector<ll> vec;
    vec.push_back(x_0);

    while(x_0 != 1){
        if(x_0 % 2 == 0) x_0 = x_0/2;//par
        else x_0 = (3*x_0) + 1;

        vec.push_back(x_0);
    }
    return vec;
}

int search_coincidence(vector<ll> vec , ll x_0){
    for(size_t i = 0; i < vec.size(); i++){
        if(vec[i] == x_0){
            return i;
        }
    }
    return -1;
}

int main(){
    ll A,B;
    ll position_A;
    ll position_B;

    while(cin>>A>>B){
        if(A == 0 && B == 0) break;

        vector<ll> coincidence_A = solution(A);
        vector<ll> coincidence_B = solution(B);

        for(size_t i = 0 ; i < coincidence_A.size(); i++){
            ll same = search_coincidence(coincidence_B , coincidence_A[i]);
            position_A = i;
            position_B = same;
            if(same != -1) break;
        }

        cout<<A<<" needs "<<position_A<<" steps, "<<B<<" needs "<<position_B<<" steps, they meet at "<<coincidence_A[position_A]<<endl;
    }
    return 0;
}