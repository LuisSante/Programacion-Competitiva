#include<bits/stdc++.h>

using namespace std;

void insertion_sort(int Aux[], int n){
    int i, key, j;

    for (i = 1; i < n; i++){
        key = Aux[i];
        j = i - 1;

        while (j >= 0 && Aux[j] > key){
            Aux[j + 1] = Aux[j];
            j = j - 1;
        }
        Aux[j + 1] = key;
    }
}


void print(int Aux[], int n){
    for(int i = 0 ; i <n; i++){
        cout<<Aux[i]<<" ";
    }
}

template<class GenericClass>
class Node{
    public:
        GenericClass data;
        Node* right;
        Node* left;

        Node()=default;
        Node(GenericClass data){
            this -> data = data;
            this -> right = nullptr;
            this -> left = nullptr;
        }

        bool is_leaf(){//es hoja
            if(left == nullptr && right == nullptr){
                return true;
            }
            return false;
        }
};

template<class GenericClass>
class BST{
    public:
        Node<GenericClass>* root;
        BST(){
            root = nullptr;
        }

        bool isEmpty(){
            if(root == nullptr){
                return true;
            }
            return false;
        }

        GenericClass _root(){
            return root -> data ;
        }

        Node<GenericClass>* insert(Node<GenericClass>* aux , GenericClass new_data){

            //si esta vacio
            if(aux == nullptr){
                aux = new Node<GenericClass>(new_data);
                aux -> left = nullptr;
                aux -> right = nullptr;
                return aux;
            }

            else{

                //si es menor va por la izquierda
                if(new_data < aux -> data){
                    aux -> left = insert(aux -> left, new_data);
                }

                //si es mayor va por la derecha
                else if(new_data > aux -> data){
                    aux -> right = insert(aux -> right, new_data);
                }

                return aux;
            }
        }

        void insert(GenericClass new_data){
            root = insert(root,new_data);
        }

        bool operator>(const BST<GenericClass>& a) const{
            return a.root < *this;
        }
};

int main(){	
    BST<int> bst;
    int A[] = {1,2,5,6,3,4,7,9};
    int size_ = sizeof(A)/sizeof(A[0]);
    insertion_sort(A,size_);
    print(A, size_);

    for(int i=0; i<size_; i++){
        bst.insert(A[i]);
    }

    cout<<"\n";

    if(bst.isEmpty()){
        cout<<"Arbol binario vacio";
    }else{cout<<"Arbol binario con nodos insertados";}
}