#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> aux(nums.size());
    aux[0] = 1;
    for(int i=1 ; i<nums.size() ; i++){
        aux[i] = 1;
        for(int j=0 ; j<i ; j++){
            if(nums[i] > nums[j] && aux[i]<aux[j]+1){
                aux[i] = aux[j] + 1;
            }
        }
    }

    return *max_element(aux.begin(),aux.end());
}

int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout<<lengthOfLIS(nums);
    return 0;
}