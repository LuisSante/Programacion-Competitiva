//https://open.kattis.com/problems/burrowswheeler
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll _size = 2e5;
vector<ll> suffix_arr,position;
ll N,index;
string cad;

bool menor(ll a, ll b){
    if(a<b) return true;
    return false;
}

bool compare(ll a, ll b){
    if (position[a] != position[b]) return menor(position[a],position[b]);
    a+=index;
    b+=index;
    return (a<N &&b<N)? menor(position[a],position[b]):a>b;
}

vector<ll> suff_arr(){
    N = cad.size();
    for (ll i = 0; i < N; i++){
        suffix_arr.push_back(i);
        position.push_back(cad[i]);
    }
    ll vector_aux[_size];
    for (index = 1;; index <<= 1) {
        sort(suffix_arr.begin(), suffix_arr.end(), compare);
        for (ll i = 0; i < N-1; i++) vector_aux[i+1] = vector_aux[i] + compare(suffix_arr[i], suffix_arr[i+1]);
        for (ll i = 0; i < N; i++) position[suffix_arr[i]] = vector_aux[i];
        if (vector_aux[N - 1] == N - 1) break;
    }
    return suffix_arr;
}

int main(){
    while(getline(cin,cad)){
        cad+=cad;
        suff_arr();
        for(int i = 0; i < N; i++){
            if(suffix_arr[i] < N/2) cout<<cad[suffix_arr[i] + N/2 - 1];
        }
        cout<<endl;
        suffix_arr.clear();
        position.clear();
        istream& ignore (streamsize n = 1, int delim = EOF);
    }
    return 0;
}