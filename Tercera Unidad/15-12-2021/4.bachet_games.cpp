#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main(){
    int n, m;
    while( cin >> n >> m ){

        vector<int> v;

        vector<bool> array(n,false);

        for( int i = 0; i < m; ++i ){
            int j;
            cin >> j;
            v.push_back(j);
            array[j-1] = true;        
        }
        for( auto it = array.begin(); it != array.end(); ++it){
            if(!(*it)){
                for(auto it2 = v.begin(); it2 != v.end(); ++it2){      
                    if(it + *it2 < array.end()){                    
                    auto pos = *(it + *it2);
                    pos = true;
                    }
                }
            }
        }
       if(array[n-1]){                                              
           cout << "Stan wins" << endl;
       } else {
           cout << "Ollie wins" << endl;
       }
    }
    return 0;
}