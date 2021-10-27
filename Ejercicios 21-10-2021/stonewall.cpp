#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int solution(vector<int>& H){
    int cont = 0;
    stack<int> height;

    for(auto h:H){
        while(!height.empty() && h < height.top())
            height.pop();

        if(height.empty() || h > height.top()){
            height.push(h);
            ++cont;
        }   
    }

    return cont;
}

int main(){
    vector<int> H = {8,8,5,7,9,8,7,4,8};
    cout<<solution(H);
    return 0;
}