#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> kmp_pre(string cad1){
    vector<int> table(cad1.size() + 1, -1);
    for( int i = 1; i <= cad1.size(); i++ ){
        int pos = table[i - 1];

        while( pos != -1 && cad1[pos] != cad1[i - 1] ){
            pos = table[pos];
        }
        table[i] = pos + 1;
    }
    return table;
}

void kmp_search(string cad1, string cad2, vector<int> table){
    int index1 = 0;
    int index2 = 0;

    int size_cad2 = (int)cad2.size();
    int size_cad1 = (int)cad1.size();

    while( index1 < size_cad2 ){
        while( index2 != -1 && (index2 == size_cad1 || cad1[index2] != cad2[index1]) )
            index2 = table[index2];

        index2++;
        index1++;

        if( index2 == size_cad1 ){
            cout << index1 - size_cad1 << " ";
        }
    }
    cout << "\n";
}


int main() {
    char buffer[1048576];
    cin.rdbuf()->pubsetbuf(buffer, sizeof(buffer));

    int x,y,z;
    string cad1, cad2;
    while ( getline(cin,cad1) ) {
        getline(cin, cad2);
        kmp_search(cad1, cad2, kmp_pre(cad1));
    }
}