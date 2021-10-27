#include<bits/stdc++.h>

using namespace std;

vector<int> B;
void square(vector<int> A){
    for(auto x:A){
        B.push_back(x*x);
    }
    sort(B.begin(),B.end());
}

void print(){
    for(auto x:B){
        cout<<x<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> A{-4,-3,1,2,3};
    square(A);
    print();
    return 0;
}