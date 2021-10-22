#include<bits/stdc++.h>

using namespace std;

int solution(vector<int>& A, vector<int>& B){

    stack<int> rio_abajo;
    int dead = 0;
    for(int i = 0; i < A.size(); i++){//no importa que tamaño tomar
        if(B[i] == 1){
            rio_abajo.push(A[i]);
        }
        else{//si no ingresa al "else" es porque todos los peces van en direccion 1
            while(!rio_abajo.empty()){
                dead++;
                if(A[i] > rio_abajo.top())
                    rio_abajo.pop();
                else
                    break;
            }
        }
    }

    return A.size()-dead;
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> A={4,3,2,1,5};//tamaños de peces
    vector<int> B={0,1,0,0,0};//direcciones de peces 0 / 1
    cout<<solution(A,B);
    return 0;
}