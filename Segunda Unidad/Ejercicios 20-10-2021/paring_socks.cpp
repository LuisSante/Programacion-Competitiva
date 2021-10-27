#include<iostream>
#include<stack>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

int main(){
    int N , x, mov = 0;
    stack<int> socks, socks_aux;
    cin>>N;

    int N2 = 2 * N;
    while(N2--){
        cin>>x;
        socks.push(x);
    }
    
    while(!socks.empty()){
        mov++;
        if(socks_aux.empty()){
            socks_aux.push(socks.top());
            socks.pop();
            continue;
        }

        if(socks.top() == socks_aux.top()){
            socks.pop();
            socks_aux.pop();
            continue;
        }

        socks_aux.push(socks.top());
        socks.pop();
    }

    if(socks_aux.empty()) {
        cout << mov << endl;
    }
    else {
        cout << "impossible" << endl;
    }

    return 0;
}