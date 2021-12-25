//https://open.kattis.com/problems/megainversions

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll; 

void acumular(vector<ll>& vec, ll i, ll d){
  for(; i < vec.size(); i |= i+1) vec[i] += d;
}

ll sum(vector<ll>& vec, ll i){
  ll cont = 0;
  for(; i > 0; i &= i-1) cont += vec[i-1];
  return cont;
}

ll cont(vector<ll>& vec, ll i){
  return sum(vec, vec.size()) - sum(vec, i);
}

int main() {
  ll n;
  cin >> n;

  vector<ll> vec(n+1, 0);
  vector<ll> vec2(n+1, 0);
  vector<ll> vec3(n+1, 0);

  for(ll i = 0; i < n; i++) {
    int n;
    cin >> n;
    ll s1 = cont(vec, n+1);
    ll s2 = cont(vec2, n+1);

    acumular(vec, n, 1);
    acumular(vec2, n, s1);
    acumular(vec3, n, s2);
  }
  cout << cont(vec3, 0) << endl;
}