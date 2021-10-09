#include <bits/stdc++.h>
using namespace std;    

vector<int> solution(string& S,vector<int>& P , vector<int>& Q){
    vector<int> result;
    vector<int> A(S.size(),0);
    vector<int> C(S.size(),0);
    vector<int> G(S.size(),0);
    vector<int> T(S.size(),0);
    int a = 0,c = 0,g = 0,t = 0;

    for(int i=0; S[i]!='\0' ; i++){
        if(S[i] == 'A')a++;
        else if(S[i] == 'C')c++;
        else if(S[i] == 'G')g++;
        else if(S[i] == 'T')t++;

        A[i] = a; C[i] = c ; G[i] = g ; T[i] = t;
    } 

    int size_P = P.size();
    for(int i=0; i<size_P;i++){
        if(P[i] == Q[i]){

            if(S[P[i]] == 'A')result.push_back(1);
            else if(S[P[i]] == 'C')result.push_back(2);
            else if(S[P[i]] == 'G')result.push_back(3);
            else if(S[P[i]] == 'T')result.push_back(4);
        }

        else if(A[P[i]] < A[Q[i]] || S[P[i]] == 'A')result.push_back(1);
        else if(C[P[i]] < C[Q[i]] || S[P[i]] == 'C')result.push_back(2);
        else if(G[P[i]] < G[Q[i]] || S[P[i]] == 'G')result.push_back(3);
        else if(T[P[i]] < T[Q[i]] || S[P[i]] == 'T')result.push_back(4);
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S ="CAGCCTA";
    vector<int> P = {2,5,0};
    vector<int> Q = {4,5,6};
    vector<int> rpta = solution(S, P, Q);
    for(int i = 0; i < rpta.size();i++){
        cout<<rpta[i]<<" ";
    }
    return 0;
}

