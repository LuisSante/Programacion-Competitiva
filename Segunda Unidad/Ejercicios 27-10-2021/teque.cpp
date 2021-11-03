#include<iostream>
#include<queue>
#include<algorithm>
#include<iterator>
#include<vector>
#include<string>

using namespace std;

typedef deque<long long> dq;

dq d;

int get(int value){
    if(value < d.size()) {
        return d[value];
	}
	value -= d.size();
	return d[value];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;

    string name;
    int value;

    while(N--){
        cin>>name>>value;
        if(name == "push_back") d.push_back(value);
        else if(name == "push_front") d.push_front(value);
        else if(name == "push_middle") d.insert(begin(d)+(d.size()+1)/2,value);
        else if(name == "get") cout<<get(value)<<" ";
    }
    return 0;
}    