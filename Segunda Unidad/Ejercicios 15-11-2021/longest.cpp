#include<iostream>
#include<algorithm>

using namespace std;

int sub_seq(string cad1, int i, string cad2, int j){
    int result{ };
    if(i == 0 || j == 0) return 0;

    else if(cad1[i] == cad2[j]) sub_seq(cad1,i-1,cad2,j-1)+1;

    else{
        int q1 = sub_seq(cad1,i-1,cad2,j);
        int q2 = sub_seq(cad1,i,cad2,j-1);

        result = max(q1,q2);
    }
    return result;
}

int main(){
    string cad1 = "abcdefghij";
    string cad2 = "ecdgi";
    int i = 0;
    int j = 0;
    cout<<sub_seq(cad1,i,cad2,j); 
    return 0;
}