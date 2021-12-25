//ejercicio https://open.kattis.com/problems/trendingtopic

#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<iterator>
#include<algorithm>

using namespace std;

vector<string> words[7];
map<string, int> _vec;
map<int, set<string>> vec_aux_text;
int day = 0;

void text(){
    for(string words_vector : words[day]){
        _vec[words_vector]--;
        if(_vec[words_vector] == 0)
            _vec.erase(words_vector);
    }

    words[day].clear();
    string word_;

    cin>>word_;
    while(word_ != "</text>"){
        if(word_.length() >= 4){
            words[day].push_back(word_);
            _vec[word_]++;
        }
        cin >> word_;
    }
    day=(day+1)%7;    
}

void top(){
    int N; 
    string temp; 
    cin >> N >> temp;

    vec_aux_text.clear();

    for(auto value : _vec){
        if(value.second > 0)
            vec_aux_text[value.second].insert(value.first);
    }

    int cont=0;
    cout<<"<top "<<N<<">"<<endl;
    for(auto value = vec_aux_text.rbegin(); cont<N && value != vec_aux_text.rend(); ++value) {
        for(auto word_ : value->second){
            cout<<word_<<" "<<value->first<<endl;
            cont++;
        }
    }
    cout<<"</top>"<<endl;    
}

int main(){
    string cad; 
    while(cin>>cad){
        if(cad=="<text>")
            text();
        else
            top();
    }
}