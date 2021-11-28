#include<iostream>
#include<map>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

/*
* input 2 4 5 1 3
* ouput 2 3 3 1 1 
*/

void kaka(map<int,int> index, vector<int> deletes){
    for(size_t i=0; i<index.size(); ++i){
        auto x = index.find(deletes[i]);
        index.erase(x);
        cout<<x->first<<" ";

    }
}

int main(){
    int n;
    cin>>n;
    map<int,int> index;
    vector<int> deletes;
    int data;
    for(int i=0;i<n;i++){
        cin>>data;
        deletes.push_back(data);
    }

    for(int i=1 ; i<=n ; ++i){
        index.insert(make_pair(i,i));
    }
    kaka(index,deletes);

    return 0;
}