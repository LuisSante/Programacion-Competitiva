#include<bits/stdc++.h>

using namespace std;

int minAddToMakeValid(string s) {
    stack<char> paren;
    int cont = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(')
            paren.push(s[i]);

        else{
            if(!paren.empty() && s[i] == ')')
                paren.pop();
    
            else
                cont++;
        }
    }
    cont+=paren.size();
    return cont;
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //string s = "())";
    string s = "(((";
    //string s = "()";
    //string s = "()))((";

    cout<<minAddToMakeValid(s);
    return 0;
}