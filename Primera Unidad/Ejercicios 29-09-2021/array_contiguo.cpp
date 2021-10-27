
// ### PRIMERA IDEA
/*#include<bits/stdc++.h>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    vector<int> sumas;
    for(size_t i = 0; i < nums.size(); i++){
        int sum = 0;
        for(size_t j = i; j < k+i; j++){
            sum += nums[j];
            sumas.push_back(sum);
        }
    }

    int mayor = sumas[0];
    for(int i = 1; i < sumas.size() ; i++){
        if(mayor < sumas[i]){
            mayor = sumas[i];
        }
    }

    return mayor;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> A{2,3,4,1,5};
    int k=3;

    cout<<subarraySum(A,k);
    return 0;
}*/

// ### SEGUNDA IDEA

#include<bits/stdc++.h>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int sum = 0;
    for(size_t i = 0; i < k; i++){
        sum+=nums[i];
    }

    int mayor_actual = sum;
    for(size_t i=k ; i<nums.size() ; i++){
        mayor_actual += nums[i];
        mayor_actual -= nums[i-k];

        if(mayor_actual > sum){
            sum = mayor_actual;
        }
    }

    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums{2,3,4,1,5};
    int k=3;

    cout<<subarraySum(nums,k);
    return 0;
}

