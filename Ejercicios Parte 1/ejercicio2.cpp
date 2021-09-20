#include<iostream>
#include<vector>

using namespace std;

ostream& operator<<(ostream& output, const vector<int>& vec){
    for (auto& iter : vec)
    {
        output << iter << " ";
    }
    return output;
}

vector<int> bucles(const vector<int> entrada, int tam){
    vector<int> buc;
    vector<int> vec_end;
    for (size_t i=0; i<entrada.size(); i++){
        buc.push_back(0);
    }
    
    for (size_t i=0; i<entrada.size(); i++){
        buc[entrada[i]]++;
    }

    for (size_t i=0; i<entrada.size(); i++){
        if(buc[i]>1)
            vec_end.push_back(i);
    }

    return vec_end;
}

int main(){
    int n;
    cin>>n;
    vector<int> entrada;
    int token;

    for(int i=0; i<n; i++){
        cin>>token;
        entrada.push_back(token);
    }

    cout<<bucles(entrada,n);
    return 0;
}