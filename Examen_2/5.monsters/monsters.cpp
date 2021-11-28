#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
#define size_ 1005
using namespace std;

typedef pair<int, int> par;

int N, M;
queue<par> q;
int paths[size_][size_];
par from[size_][size_],A;
int infinite = INT_MAX;
string cadena;
bool _flag__ = false;

void visitar(par node){
	par par_current = from[node.first][node.second];
	if(par_current ==  par(0,0)) 
		return;
	if(par_current.first == node.first+1) 
		cadena.push_back('U');
	if(par_current.first == node.first-1) 
		cadena.push_back('D');
	if(par_current.second == node.second+1) 
		cadena.push_back('L');
	if(par_current.second==node.second-1) 
		cadena.push_back('R');
	visitar(par_current);

}
void verificar(par par_current, par dest){
	int pl = paths[par_current.first][par_current.second];
	if(pl+1<paths[dest.first][dest.second]){
		paths[dest.first][dest.second]  = pl+1;
		q.push(dest);
		from[dest.first][dest.second] = par_current;
	}
}
bool flag = false;
void bfs(){
	while(!q.empty()){
		par loc = q.front(), next; q.pop();
		next = loc; 
		next.first++; 
		verificar(loc, next);
		next = loc; 
		next.first--; 
		verificar(loc, next);
		next = loc; 
		next.second++; 
		verificar(loc, next);
		next = loc; 
		next.second--; 
		verificar(loc, next);
		if(flag && (loc.first == 1 || loc.second == 1 || loc.first == N || loc.second == M)){
			cout << "YES" << endl;
			cout << paths[loc.first][loc.second] << endl;
			visitar(loc);
			_flag__ = true;
			return;
		}
	}
}
int main() {
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		string s;
		cin >> s;
		for(int j = 1; j <= M; j++){
			paths[i][j] = infinite;
			if(s[j-1] == '#') 
				paths[i][j] = 0;
				
			if(s[j-1] == 'M'){
				q.push(par(i,j)); 
				paths[i][j]  = 0;
			}

			if(s[j-1] == 'A'){
				A.first = i; 
				A.second = j;
			}
		}
	}
	bfs();
	flag = true;
	from[A.first][A.second] = par(0,0);
	paths[A.first][A.second] = 0; q.push(A);
	bfs();
	if(_flag__){
		reverse(cadena.begin(), cadena.end());
		cout << cadena << endl;
	}
	else cout << "NO" << endl;
}