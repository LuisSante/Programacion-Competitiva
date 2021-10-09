#include <bits/stdc++.h>
using namespace std;

int solution(vector<int>& A){
    int i = 0;
    int size_ = A.size();

    double min_avg = (A[0] + A[1]) / 2.0;
    int idex_min = 0;
    

    for (i = 2; i < size_; i++){
        double avg_two = (A[i - 1] + A[i]) / 2.0;
        double avg_three = (A[i - 2] + A[i - 1] + A[i]) / 3.0;
        
        if (avg_two < min_avg){
            idex_min = i - 1;
            min_avg = avg_two;
        }
        if (avg_three < min_avg){
            idex_min = i - 2;
            min_avg = avg_three;
        }
    }
    return idex_min;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> A = {4 , 2, 2, 5, 1, 5, 8};
    cout<<solution(A);

    return 0;
}