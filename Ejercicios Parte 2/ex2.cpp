#include<iostream>
#include<list>
#include<ctime>
#include<algorithm>
#include<map>

using namespace std;

void print(list<int> linked){
    for(list<int>::iterator it = linked.begin(); it != linked.end(); it++){
        cout << *it << " ";
    }
}

void delete_duplicate(list<int> linked){
    for(list<int>::iterator it = linked.begin(); it != linked.end(); it++){
        int cont = 0;
        for(list<int>::iterator it2 = linked.begin(); it2 != linked.end(); it2++){
            if(*it == *it2){
                cont++;
                cout<<cont<<" ";
                if(cont >= 2){
                    linked.remove(*it);
                }
            }
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"numero de elementos: ";cin>>n;
    list<int> linked;

    for(int i=0;i<n;i++){ 
        linked.push_back(rand()%10);
    }
    print(linked);
    delete_duplicate(linked);
    cout<<endl;
    //print(linked);
    return 0;
}