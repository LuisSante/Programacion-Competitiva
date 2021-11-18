#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int backpack(int n , int C , vi& weight, vi& value){
    int result{};

    if(n == 0 || C == 0){
        result = 0;
    }
    else if(weight[n] > C){
        result = backpack(n-1,C,weight,value);
    }
    else{
        int tmp1 = backpack(n-1,C,weight,value);
        int tmp2 = value[n] + backpack(n-1,C-weight[n],weight,value);
        result = max(tmp1,tmp2);
    }
    return result;
}


int main(){
    int C = 10;
    int n = 5;
    vi weight = {1,2,4,2,5};
    vi value = {5,3,5,3,2};
    cout<<backpack(n,C ,weight,value);
    return 0;
}
