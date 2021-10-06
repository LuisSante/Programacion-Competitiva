#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> nums2;

    int it, low, high;
    
    if(nums.size()<3){
        return nums2;
    }
    sort(nums.begin(),nums.end());
    for(it = 0 ; it < nums.size() -2; it++){
        low = it + 1;
        high = nums.size() -1;

        while(low < high){
            if( it != 0 && nums[it] == nums[it-1]){
                break;
            }

            else if((nums[low] + nums[high] + nums[it]) == 0){
                vector<int> triplet;
                triplet.push_back(nums[low]);
                triplet.push_back(nums[high]);
                triplet.push_back(nums[it]);
                nums2.push_back(triplet);

                while(low < high && nums[low] == nums[low+1]) low++;
                while(low < high && nums[high] == nums[high-1]) high--;

                low++;
                high--;
            }

            else if((nums[low] + nums[high]) > -nums[it]){
                high--;
            }
            else if((nums[low] + nums[high]) < -nums[it]){
                low++;
            }
        }
    }

    return nums2;        
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> al;

    al = threeSum(nums);
    for(int i = 0; i < al.size(); i++){

    }
    return 0;
}