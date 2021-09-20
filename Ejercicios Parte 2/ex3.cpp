#include<iostream>
#include<list>
#include<ctime>

using namespace std;

list<int> linked;

void recopilacion_datos(string expresion){
    for(int i = 0 ; expresion[i] != '\0' ; i++){
        if(expresion[i] >= '0' && expresion[i] <= '9'){
            linked.push_back(atoi(expresion[i]));
        }
    }
}

void suma(list<int> linked){
    
}

int main(){
    string expresion;
    cin>>expresion;
    return 0;
}