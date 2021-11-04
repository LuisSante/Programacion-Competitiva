#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;
//1 es decimal
//0 es binario

void message(vector<vector<int>>& grid, int dom_f, int dom_c,int ran_f, int ran_c){
    int item_A = grid[dom_f+1][dom_c+1];
    int item_B = grid[ran_f+1][ran_c+1];
    
    if(item_A == item_B && item_A == 0) cout<<"binary"<<endl;
    else if(item_A == item_B && item_A == 1) cout<<"decimal"<<endl;
    else cout<<"neither"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int f , c;
    cin>>f>>c;
    int data;
    vector<vector<int>> grid(f,vector<int>(c,0));
    for(int i = 0; i <f; i++){
        for(int j = 0; j <c; j++){
            cin>>grid[i][j];
        }
    }

    int queries;
    cin>>queries;
    while(queries--){
        int dom_f, dom_c;
        int ran_f, ran_c;
        cin>>dom_f>>dom_c;
        cin>>ran_f>>ran_c;
        message(grid,dom_f, dom_c,ran_f, ran_c);
    }
    return 0;
}   