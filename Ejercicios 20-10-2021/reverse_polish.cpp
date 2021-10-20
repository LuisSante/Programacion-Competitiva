#include<bits/stdc++.h>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<string> pila;
    for(int i = 0; i < tokens.size();i++){
        if(tokens[i] == "+"){
            string elem1 = pila.top();
            pila.pop();
            string elem2 = pila.top();
            pila.pop();
            string result = to_string(stoi(elem1) + stoi(elem2));
            pila.push(result);
        }

        else if(tokens[i] == "-"){
            string elem1 = pila.top();
            pila.pop();
            string elem2 = pila.top();
            pila.pop();
            string result = to_string(stoi(elem1) - stoi(elem2));
            pila.push(result);
        }

        else if(tokens[i] == "/"){
            string elem1 = pila.top();
            pila.pop();
            string elem2 = pila.top();
            pila.pop();
            string result = to_string(stoi(elem1) / stoi(elem2));
            pila.push(result);
        }

        else if(tokens[i] == "*"){
            string elem1 = pila.top();
            pila.pop();
            string elem2 = pila.top();
            pila.pop();
            string result = to_string(stoi(elem1) * stoi(elem2));
            pila.push(result);
        }

        else{
            pila.push(tokens[i]);
        }
    }

    return stoi(pila.top());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> tokens = {"2","1","+","3","*"};
    //vector<string> tokens = ["4","13","5","/","+"]
    //vector<string> tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
    cout<<evalRPN(tokens)<<endl;
    return 0;
}