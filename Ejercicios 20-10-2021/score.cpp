#include<bits/stdc++.h>

using namespace std;

int score(string s) {
    stack<char> paren;
    int cont = 0;
    for(int i = 0; i < s.size(); i++){
       if(s[i] == '('){
           paren.push(s[i]);
       }
    }
    return cont;
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    return 0;
}