#include<bits/stdc++.h>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int cont = 0;
    for(size_t i=0 ; i < nums.size() ; i++){
        int sum = 0;
        for(size_t j=i; j < nums.size() ; j++){
            sum += nums[j];
            
            if(sum == k){
                cont++;
            }
        }
    }
    return cont;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> A{1,1,1};
    int k=2;

    cout<<subarraySum(A,k);
    return 0;
}