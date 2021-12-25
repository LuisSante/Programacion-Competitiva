//https://open.kattis.com/problems/oddmanout
#include<iostream>
#include<map>
#include<iterator>

using namespace std;

typedef long long ll;

int main(){
    int n, G;
    cin>>n;
    for(int i=0;i<n;i++){
        map<ll,int> invitados;
        cin>>G;
        for(int j=0 ; j<G ; j++){
            ll temp;
            cin>>temp;
            invitados[temp]++;
        }

        for(auto value:invitados){
            if(value.second == 1) 
                cout<<"Case #"<<i+1<<": "<<value.first<<endl;
        }
    }
    return 0;
}