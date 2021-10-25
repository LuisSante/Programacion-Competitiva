#include<queue>
#include<iostream>
#include<vector>

using namespace std;

void solution(vector<vector<int>>& A){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A[i].size(); j++){
            pq.push(A[i][j]);
        }
    }

    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }

}

int main(){
    vector<vector<int>> A = {{1,4,5},{1,3,4},{2,6}};
    solution(A);
    return 0;
}