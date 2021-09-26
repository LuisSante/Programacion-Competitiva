#include<bits/stdc++.h>

using namespace std;

int sub_array(vector<int> A, int k , int begin , int end){
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> A{4,5,0,-2,-3,1};
    int k=5;

    int begin = 0;
    int end = A.size()-1;

    cout<<sub_array(A,k,begin,end)<<'\n';
    return 0;
}