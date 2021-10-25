#include<bits/stdc++.h>

using namespace std;

void solution(string cad){

    string res = "";
    bool flag = false;
    queue<char> q;

    for(int i=0; i<cad.size();i++){
        if(cad[i] == '$'){
            while(!q.empty()){
                res+= (flag) ? toupper(q.front()) : tolower(q.front());
                q.pop();
            }
        }

        else if(cad[i] == '@'){
            flag = flag ? false : true;
        }

        else{
            q.push(cad[i]);
        }
    }
}

int main(){
    string cad;
    solution(cad);
    return 0;
}
