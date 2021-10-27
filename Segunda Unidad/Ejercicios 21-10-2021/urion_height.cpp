#include<bits/stdc++.h>
using namespace std;

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;
    int size_city;
    while(N--){

        cin>>size_city;
        int arr_height[size_city]={0};
        for(int i = 0; i < size_city ; i++){
            cin>>arr_height[i];
        }

        sort(arr_height, arr_height+size_city);

        for(int j = 0 ; j < size_city ; j++){
            cout<<arr_height[j];
            if(j != size_city-1)
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}