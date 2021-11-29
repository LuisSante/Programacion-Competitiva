#include<string>
#include<iostream>
#include<algorithm>

#define moo -99999
#define oo 999

using namespace std;

int memorize[oo][oo];
string cadena;

void _init_(){
	for(int i=0; i<oo; i++){
		for(int j=0; j<oo; j++)
			memorize[i][j] = moo;
	}
}

int solution(int i, int j) {
    if (i > j) {
    	return 0;
	} 
    
    else{
		if (memorize[i][j] == moo) {
	        memorize[i][j] = solution(i, j-1) + 1;
			int aux=i;
			while(aux<j){
				if (cadena[aux] == cadena[j]){
				    int current = solution(i,aux) + solution(aux+1,j-1);
	                memorize[i][j] = min(memorize[i][j], current);
	            }
				aux++;	
			}
    	}
    	return memorize[i][j];
	}
}

int main() {
    int n;
    cin >> n;
    int ans;
    
	cin.ignore();
    
    for(int i=0; i<n; i++){
		_init_();
		getline(cin,cadena);
        int size_ = cadena.size()-1;
		int current = solution(0, size_);
        ans = current*2 + size_+1;
    	cout<<ans<<endl;		
	}
    return 0;
}