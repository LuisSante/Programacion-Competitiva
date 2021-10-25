#include<bits/stdc++.h>
using namespace std;

void solution(string cad){
    deque<char> d;
	for(int i=0 ; i<cad.size() ; i++){
		if(cad[i] == '#'){
			d.pop_back();
		}
		else{
			d.push_back(cad[i]);
		}
    }
    
    string cad2 = "";
    for(auto it = d.begin() ; it != d.end() ; it++){
    	cad2 += *it;
	}
	
	cout<<cad2<<endl;
}

int main(){
    string cad = "abc#de##f#ghi#jklmn#op#";
    solution(cad);
    return 0;
}
