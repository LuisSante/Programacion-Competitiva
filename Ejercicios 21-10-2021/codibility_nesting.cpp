#include<bits/stdc++.h>

using namespace std;

int solution(string& s){
    stack<char> paren;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(')
            paren.push(s[i]);

        if(paren.empty()){
            return 0;
        }

        else{
            if(!paren.empty() && s[i] == ')'){
                paren.pop();
            }
        }
    }

    if(paren.empty())
        return 1;
    return 0;
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s = "(() (()) ())";
    cout<<solution(s);
    return 0;
}