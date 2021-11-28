#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct PlanetsKingdoms {
	int n;
    vector<vector<int>> matrix_adj, ajd2;
	vector<int> all, compare, compr; 
    vector<bool> vis;
	void init(int n){ 
		this -> n = n;
		matrix_adj.resize(n);
		ajd2.resize(n);
		compare = vector<int>(n,-1);
		vis.resize(n);
	}

	void aux_(int x, int y) {
		matrix_adj[x].push_back(y);
		ajd2[y].push_back(x);
	}

	void dfs(int x) {
		vis[x] = 1; 
		for(int y : matrix_adj[x]) 
			if (!vis[y]) dfs(y);
		all.push_back(x); 
    }

	void dfs2(int x, int v){
		compare[x] = v;
		for(int y : ajd2[x]) if (compare[y] == -1) dfs2(y,v);
	}

	void foo() {
		for(int i=0; i<n; i++) 
			if (!vis[i]) 
				dfs(i);

		reverse(begin(all), end(all));
		for(int x : all) 
			if (compare[x] == -1){
				dfs2(x,x), 
				compr.push_back(x);
			}
	}
};

int main() {

	int n, m, a, b;
	cin >> n >> m;

	PlanetsKingdoms PK;
	PK.init(n);
	while(m--) {
		cin >> a >> b;
		PK.aux_(--a, --b);
	}
	PK.foo();

	int array[200000];
	int ids = 0;
	for(int i=0; i<n; i++) {
		if(!array[PK.compare[i]]) {
			array[PK.compare[i]] = ++ids;
		}
	}
	cout << ids << '\n';
	for(int i=0; i<n; i++) {
		cout << array[PK.compare[i]] << " \n"[i==n-1];
	}

}