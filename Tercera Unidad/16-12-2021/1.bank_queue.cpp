#include <iostream>
#include <queue>
#include <set>
using namespace std;

typedef pair<int,int> pii;

int N,T,c,t;

int main() {
    
    cin >> N >> T;
    priority_queue<pii> q;

    for (int i = 0; i < N; ++i) {
        cin >> c >> t;
        q.push(pii(c,t));
    }

    set<int> s;
    for (int t = 0; t < T; ++t) 
        s.insert(t);

    int ret=0;

    while(!q.empty() && !s.empty()) {
        int c = q.top().first;
        int tmax = q.top().second;

        q.pop();
        auto it = s.upper_bound(tmax);
        if (it==s.begin()) 
            continue;
        --it;
        ret += c;
        s.erase(it);
    }
    cout << ret << endl;
}