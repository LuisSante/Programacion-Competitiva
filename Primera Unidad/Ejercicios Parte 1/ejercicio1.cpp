#include<iostream>
#include<vector>

using namespace std;

int maxproduct(const vector<int> entrada){
    int mayor_f = entrada[0];
    int mayor_s;
    int prod;
    for(size_t i=0; i<entrada.size(); i++){
        if(entrada[i] > mayor_f){
            mayor_s = mayor_f;
            mayor_f = entrada[i];
        }      
    }
    prod = mayor_f * mayor_s;
    return prod;
}

int main(){
    int n;
    int token;
    cin>>n;
    vector<int> entrada;
    for(int i=0; i<n; i++){
        cin>>token;
        entrada.push_back(token);
    }

    cout<<maxproduct(entrada);
    return 0;
}