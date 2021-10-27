#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size_;
    int queries;
    cin>>size_>>queries;

    vector<int> D(size_ , 0);

    int range_A, range_B;
    while(queries--){
        cin>>range_A>>range_B;
        int aux = range_A-1;
        int aux2 = range_B-1;
        D[aux]++;
        D[aux2+1]--;
    }

    for(int i=1 ; i < size_; i++){
        D[i] = D[i-1] + D[i];
    }

    sort(D.begin(), D.end());

    if(size_%2 == 0){
        cout<< (D[(size_/2) - 1] + D[size_/2])/2 <<endl;
    }
    else{
        cout<< D[(size_/2) - 1];
    }

    return 0;
}