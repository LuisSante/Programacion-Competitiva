#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<iterator>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> aux;
    for(auto x : asteroids) {
        bool boom = false;
        while(!aux.empty() && x  < 0 && 0 < aux.back()){
            if(aux.back() < -x){
                aux.pop_back();
                continue;
            }else if(aux.back() == -x){
                aux.pop_back();
            }
            boom = true;
            break;
        }

        if(!boom){
            aux.push_back(x);
        }
    }
    return aux;
}

int main(){
    vector<int> asteroids = {5,10,-5};
    vector<int> print = asteroidCollision(asteroids);
    for(int i = 0; i < asteroids.size(); i++) {
        cout<<print[i]<<" ";
    }
    return 0;
}