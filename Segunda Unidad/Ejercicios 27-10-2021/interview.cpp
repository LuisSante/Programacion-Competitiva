#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void solution(vector<int>& arr){
    deque<int> d;
    for(auto value:arr) d.push_back(value);
    int res = 0;

    while(d.front() != -1 && d.back() != -1){
        if(d.front() < d.back()){
            res += d.front();
            d.pop_front();
        }

        else{
            res += d.back();
            d.pop_back();
        }
    }
    cout<<res<<endl;
}

int main(){
    vector<int> A = {4,-1,5,2,3};
    solution(A);
    return 0;
}