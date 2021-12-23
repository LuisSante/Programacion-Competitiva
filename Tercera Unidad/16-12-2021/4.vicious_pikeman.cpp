#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define mod 1000000007

int main() {
    long n, t, A, B, C;
    vector<long> ti;
    long temp;
    cin >> n >> t >> A >> B >> C >> temp;
    ti.push_back(temp);
    for(int i = 1; i < n; i++) 
        ti.push_back((A*ti[i-1]+B)%C+1);

    sort(ti.begin(), ti.end());

    long penalizacion=0, problemas_resueltos=0, t_p=0;
    for(long t_i:ti){
        if(t_i+t_p<=t){
            penalizacion=(penalizacion+t_i+t_p)%mod;
            problemas_resueltos++;
            t_p+=t_i;
        } 
        else{ break;}
    }

    cout<<problemas_resueltos<<" "<<penalizacion<<endl;
    return 0;
}