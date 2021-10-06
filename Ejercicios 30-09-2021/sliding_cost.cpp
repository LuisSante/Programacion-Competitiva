//IDEA N°1 COSTO DEMASIADO ALTO

/*#include<bits/stdc++.h>

using namespace std;

vector<int> v;
vector<int> costos_;

int cost_(vector<int> v){
    vector<int>::iterator low = min_element(v.begin() , v.end());
    vector<int>::iterator high = max_element(v.begin() , v.end());
    
    int medium;
    for(size_t i = 0; i < v.size(); i++){
        if(v[i] > *low && v[i] < *high){
            medium = v[i];
        }
    }

    int cost_current;
    cost_current = (*high - medium) + (medium - *low);
    return cost_current;

}

vector<int> sliding_cost(int A[], int size_total, int size_partial){
    for(int i = 0; i < size_total-size_partial+1; i++){
        int costo; 
        for(int j = i; j < size_partial+i; j++){
            v.push_back(A[j]);
        }
        costo = cost_(v);
        costos_.push_back(costo);
        v.clear();
    }
}

void print(const vector<int> costos){
    for(size_t i = 0; i < costos.size(); i++){
        cout<<costos[i]<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size_total;
    int size_partial;
    cin>>size_total;
    cin>>size_partial;

    int A[size_total];
    int dato;
    for(int i = 0; i < size_total; i++){
        cin>>dato;
        A[i] = dato;
    }    
    sliding_cost(A, size_total, size_partial);
    print(costos_);

    return 0;
}*/


//IDEA N°2 EFICIENTE
//100% CASES

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>  
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<int,
        null_type,
        less_equal<int>,
        rb_tree_tag,
        tree_order_statistics_node_update> 
    ordered_multiset;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n , m;
    cin >> n >> m;
    
    ll A[n];

    for(int i = 0; i < n; ++i){
        cin>>A[i];
    }

    ordered_multiset st;

    for(int i = 0; i < m; ++i){
        st.insert(A[i]);
    }

    ll P = *st.find_by_order((m+1)/2-1);
    ll d = 0;

    for(int i=0 ; i < m ; ++i) d+=abs(A[i]-P);
    cout<<d<<" ";

    for(int i = 0; i < n-m; ++i){
        st.erase(st.find_by_order(st.order_of_key(A[i])));
        st.insert(A[i+m]);
        ll p = *st.find_by_order((m+1)/2-1);
        d += abs(p-A[i+m])-abs(P-A[i]);

        if(!(m&1)) d -= p - P; 
        P = p;
        cout<<d<<" ";
    }
    
    return 0;
}