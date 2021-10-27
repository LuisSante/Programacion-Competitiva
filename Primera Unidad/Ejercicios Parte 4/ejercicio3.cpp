#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string& S,vector<int>& P , vector<int>& Q){
    vector<int> impact_factors,result;

    for(int i = 0 ; S[i] != 0 ; i++){
        if(S[i] == 'A') impact_factors.push_back(1);
        else if(S[i] == 'C') impact_factors.push_back(2);
        else if(S[i] == 'G') impact_factors.push_back(3);
        else if(S[i] == 'T') impact_factors.push_back(4);
    } 

    for(size_t i = 0; i < P.size(); i++){
        result.push_back(*min_element(impact_factors.begin()+P[i] , impact_factors.begin()+Q[i]+1));
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S ="CAGCCTA";
    vector<int> P = {2,5,0};
    vector<int> Q = {4,5,6};
    vector<int> rpta;
    rpta = solution(S,P,Q);
    for(int i = 0 ; i < rpta.size(); i++){
        cout<< rpta[i]<< " ";
    }
    return 0;
}