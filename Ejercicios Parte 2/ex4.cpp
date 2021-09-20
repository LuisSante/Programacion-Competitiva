#include<iostream>
#include<stack>

using namespace std;

void swap(int x, int y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}

stack<int> sort_(stack<int> pila){
    
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << "; ";
        s.pop();
    }
    cout << endl;
}

int main(){
    int n = 10;
    stack<int> pila;
    for(int i=0;i<n;i++){ 
        pila.push(rand()%10);
    }
    printStack(pila);
    sort_(pila);
    printStack(pila);
    return 0;
}