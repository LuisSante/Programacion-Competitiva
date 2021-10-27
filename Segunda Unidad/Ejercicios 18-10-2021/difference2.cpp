#include<iterator>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N , K , x;
    cin>>N>>K;

    map<int, int> mp;
    while(N--){
        cin>>x;
        mp[x] = (mp[x] != 0) ? mp[x] + 1 : 1;
        mp[x+1000] = (mp[x+1000] != 0) ? mp[x+1000] -1 : -1;
    }

    vector<int> diff(mp.size(),0);
    int cont = 0;

    for(auto it = mp.begin(); it != mp.end(); it++){
        if(it == mp.begin()){
            diff[cont] = it->second;
        }

        else{
            diff[cont] = diff[cont-1] + it->second;
        }

        cont++;
    }

    for(int i = 0 ; i< diff.size(); i++){
        cout << diff[i] << " ";
    }
    cout<<endl;

    cout<<*max_element(diff.begin(), diff.end())/K<<endl;
    return 0;
}