//https://open.kattis.com/problems/suffixsorting

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

typedef long long ll;

using namespace std;

const ll _size = 1e5+5;
vector<ll> suffix_arr,position;
ll N,index;
string cad;

void clear(){
    cad.clear();
    suffix_arr.clear();
    position.clear();
}

bool menor(ll a, ll b){
    if(a<b) return true;
    return false;
}

bool compare(ll a, ll b){
    if (position[a] != position[b]) return menor(position[a],position[b]);
    a+=index;
    b+=index;
    return (a<N &&b<N)?menor(position[a],position[b]):a>b;
}

vector<ll> suffix_array(){
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
        suffix_array();
        int N,index_n;
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>index_n;
            cout<<suffix_arr[index_n]<<" ";
        }
        cout<<endl;
        clear();
        cin.ignore();
    }
}

