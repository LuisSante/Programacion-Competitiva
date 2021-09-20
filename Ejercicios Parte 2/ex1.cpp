#include<iostream>
#include<string>

using namespace std;

//se supone que al ser un anagrama tienen el mismo tamaño
bool anagrama(string word_o , string word_s){
    int cont = 0;
    if(word_o.size() == word_s.size()){
        for(int i = 0; word_o[i] != '\0' ; i++){
            for(int j = 0; word_s[j] != '\0'; j++){
                if(word_o[i] == word_s[j]){
                    cont++;
                }
            }
        }

    }

    if(cont != word_o.size()){
        return false;
    }

    else if(cont == word_o.size()){
        return true;
    }

}

int main(){
    string word_o = "delira";
    string word_s = "lidera";
    cout<<anagrama(word_o, word_s);
    return 0;
}