#include<bits/stdc++.h>

using namespace std;

/*
se implemento un arbol AVL ya que
tiene las caracteristicas de un arbol binario
pero este viene a ser uno balanceado 
*/ 

template<class GenericClass>
class Node{
    public:
        GenericClass data;
        int height;
        Node* right;
        Node* left;

        Node()=default;

        Node(GenericClass data){
            this -> data = data;
            this -> height = height;
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
class AVL{
    public:
        //cada uno para cada tipo de recorrido
        Node<GenericClass>* root;
        AVL(){
            root = nullptr;
        }
        
        //maximo para actualizar alturas
        int max(int x , int y){
            if(x > y)
                return x;
            else 
                return y;
        }

        bool isEmpty(){
            if(root == nullptr){
                return true;
            }
            return false;
        }

        //sacar altura 
        int _height(Node<GenericClass>* aux){
            if(aux == nullptr){
                return -1;
            }
            return aux -> height;
        }

        GenericClass _root(){
            return root -> data ;
        }
        
        Node<GenericClass>* right_rotation(Node<GenericClass>* aux){//rotacion derecha
            Node<GenericClass>* aux2 = aux -> left;
            Node<GenericClass>* aux3 = aux2 -> right;

            aux2 -> right = aux;
            aux -> left = aux3;

            aux -> height = max( _height(aux -> left), _height(aux -> right)) + 1;
            aux2 -> height = max( _height(aux2 -> left), _height(aux2 -> right)) + 1;

            return aux2;
        }

        Node<GenericClass>* left_rotation(Node<GenericClass>* aux2){//rotacion izquierda
            Node<GenericClass>* aux = aux2 -> right;
            Node<GenericClass>* aux3 = aux -> left;

            aux -> left = aux2;
            aux2 -> right = aux3;

            aux2 -> height = max( _height(aux2 -> left), _height(aux2 -> right)) + 1;
            aux -> height = max( _height(aux -> left), _height(aux -> right)) + 1;

            return aux;
        }

        //retorna del fe
        int getBalance(Node<GenericClass>* aux){
            if(aux == nullptr){
                return 0;
            }

            else{
                return _height(aux -> left) - _height(aux -> right);
            }
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

                //si en todo caso hay dos nodos que coinciden
                else{
                    return aux;
                }
            }

            int balance = getBalance(aux);
            aux -> height = 1 + max(_height(aux -> left), _height(aux -> right));

            // se sabe que el fe debe estar entre -1 0 1 
            //simple right
            if(balance > 1 && new_data < aux -> left -> data){
                return right_rotation(aux);
            }

            //simple left
            if(balance < -1 && new_data > aux -> right -> data){
                return left_rotation(aux);
            }
            
            //double rotation left-right
            if(balance > 1 && new_data > aux -> left -> data){
                aux -> left = left_rotation(aux -> left);
                return right_rotation(aux);
            }

            //double rotation right-left
            if(balance < -1 && new_data < aux -> right -> data){
                aux -> right = right_rotation(aux -> right);
                return left_rotation(aux);
            }
            return aux;
        }

        void insert(GenericClass new_data){
            root = insert(root,new_data);
        }

        bool getBalance_AVL(AVL avl_aux){
            Node<GenericClass>* aux = avl_aux.root;
            if(avl_aux.getBalance(aux) < 1){
                return true;
            }
            return false;
        }
};

int main(){

    AVL<int> avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);
    cout<<avl.getBalance_AVL(avl)<<'\n';

    if(avl.getBalance_AVL(avl) == true){
        cout<<"arbol balanceado";
    }else{cout<<"arbol no balanceado";}
    return 0;
}