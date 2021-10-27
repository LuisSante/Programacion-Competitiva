#include <bits/stdc++.h>
using namespace std;

class Node{
    private:
        int elem;
        Node *next;

    public:
        Node(){
            elem = 0;
            next = NULL;
        }

        Node(int a){
            elem = a;
            next = NULL;
        }

        int getElem() { return elem; }
        Node *getNext() { return next; }
        void setElem(int elem_) { elem = elem_; }
        void setNext(Node *next_) { next = next_; }
};

class LinkedList{
    public:
        int size;
        Node *head;
        LinkedList();
        void insertList(int elem_);
        void printList();
};

LinkedList::LinkedList(){
    size = 0;
    head = NULL;
}

void LinkedList::insertList(int elem_){
    Node *new_node = new Node(elem_);
    Node *temp = head;
    if (head == NULL){ //si nuestra lista esta vacia crea un nuevo nodo con el elemento
        head = new_node;
        size++;
    }
    else{
        while (temp->getNext() != NULL)
            temp = temp->getNext(); //ubico a temp en el ultimo elemento de la lista
        temp->setNext(new_node);    //el final de la cola apuntara a nuestro nuevo nodo
        size++;
    }
}

void LinkedList::printList(){
    Node *recorre = head;
    if (head == NULL){
        cout << "***** Lista vacia *****" << endl;
    }

    else{
        while (recorre != NULL){
            cout << recorre->getElem() << " -> "; //recorre la lista e imprime sus elementos
            recorre = recorre->getNext();
        }
    }
}
void sumarL(LinkedList *lista, LinkedList *lista2)
{
    //FUNCION PRINCIPAL
    //suma 2 numeros almacenados en una lista
    Node *tmp = lista->head;
    Node *tmp2 = lista2->head;
    int n1 = 0;
    int n2 = 0;
    while (tmp != NULL)
    {
        n1 += tmp->getElem() * (pow(10, n2));
        n2++;
        tmp = tmp->getNext();
    }

    n2 = 0;
    while (tmp2 != NULL)
    {
        n1 += tmp2->getElem() * (pow(10, n2));
        n2++;
        tmp2 = tmp2->getNext();
    }
}

int main()
{
    LinkedList *lista = new LinkedList;
    LinkedList *lista2 = new LinkedList;
    lista->insertList(3);
    lista->insertList(1);
    lista->insertList(5);
    lista2->insertList(5);
    lista2->insertList(9);
    lista2->insertList(2);
    lista->printList();
    cout << '\n';
    lista2->printList();
    cout << '\n';
    sumarL(lista, lista2);

    return 0;
}