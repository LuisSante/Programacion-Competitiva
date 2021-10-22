#include<bits/stdc++.h>

using namespace std;

const int rango = 2e5;

int solution(string& S){
    stack<char> brackets;
    char find_;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == '(' || S[i] == '{' || S[i] == '['){
            brackets.push(S[i]);
            continue;
        }

        if(brackets.empty()){
            return 0;
        }

        switch (S[i])
        {
        case ')':
            find_ = brackets.top();
            brackets.pop();
            if(find_ == '{' || find_ == '[')return 0;
            break;
        
        case '}':
            find_ = brackets.top();
            brackets.pop();
            if(find_ == '(' || find_ == '[') return 0;
            break;

        case ']':
            find_ = brackets.top();
            brackets.pop();
            if(find_ == '(' || find_ == '{') return 0;
            break;
        }
    }

    if(!brackets.empty())
        return 0;
    return 1;
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin>>S;
    cout<<solution(S);
    return 0;
}