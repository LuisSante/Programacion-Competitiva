#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

typedef unsigned long long ull;

int main(){
    ull n;
    cin >> n;

    vector<ull> potencias;
    ull data;
    for(int i=0; i<64; ++i){
        data = pow(3,i);
        potencias.push_back(data);
    }

    while( n > 0 ) {
        --n;
        cout << "{";
        bool first = true;
        for ( int i = 0; i < 64; ++i ) {
            if ( (1ll << i) & n ) {
                if (!first) {
                    cout << ",";
                }
                first = false;
                cout << " " << potencias[i];
            }
        }

        cout << " }" << endl;
        cin >> n;
    }
    return 0;
}