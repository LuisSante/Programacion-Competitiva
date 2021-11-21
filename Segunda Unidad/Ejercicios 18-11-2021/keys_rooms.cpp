#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<iterator>
#include<set>

using namespace std;
// i = rooms and rooms[i] = key
//First intent 55/64 cases
/*bool canVisitAllRooms(vector<vector<int>>& rooms){
    int cont = 1;
    for(int i=0; i<rooms.size(); i++){
        for(int j=0; j<rooms[i].size(); j++){
            if(rooms[i][j] == i+1){
                cont++;
            }
        }
    }
    if(cont == rooms.size())
        return true;
    return false;
}*/

//100% cases
bool canVisitAllRooms(vector<vector<int>>& rooms){
    set<int> visited;
    stack<int> s{};
    visited.insert(0);

    for(const auto value:rooms[0]) s.push(value);
    while(!s.empty()){
        int aux = s.top();
        s.pop();
        if(visited.find(aux) == visited.end()){
            visited.insert(aux);
            for(const auto value:rooms[aux]) s.push(value);
        }
    }
    return (visited.size() == rooms.size());
}

int main(){
    //vector<vector<int>> rooms = {{1},{2},{3},{}};
    vector<vector<int>> rooms = {{1,3},{3,0,1},{2},{0}};
    cout<<canVisitAllRooms(rooms);
    return 0;
}