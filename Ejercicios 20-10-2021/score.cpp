#include<bits/stdc++.h>

using namespace std;

int score(string s) {
    stack<char> paren;
    int cont = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
           paren.push(cont);
           cont=0;
        }
        else if(s[i] == ')'){
            cont = paren.top()+max(cont*2,1);
            paren.pop();
        }
    }
    return cont;
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "(()(()))";
    cout<<score(s);
    return 0;
}