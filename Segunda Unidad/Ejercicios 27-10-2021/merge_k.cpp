#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<queue>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    
    struct Comp{
        bool operator()(const ListNode* a, const ListNode* b){
            return a->val > b->val;
        }
    };
    
    priority_queue<ListNode*, vector<ListNode*> , Comp> pq;

    for(ListNode* x : lists) {
        pq.push(x);
    }

    ListNode* head = nullptr, *tail  = nullptr;
    while(!pq.empty()){
        ListNode* aux = pq.top();
        pq.pop();

        if (head == nullptr) {
            head = tail = aux;
        }
        else {
            tail->next = aux;
            tail = aux;
        }

        if (aux->next != nullptr) {
            pq.push(aux->next);
        }
    }
    return head;
}

void print(ListNode* node){
    while (node != nullptr){
        cout << node->val << "->";
        node = node->next;
    }
    cout << "nullptr";
}

int main(){
    int k=3;
    vector<ListNode*> lists(k);

    lists[0] = new ListNode(1);
    lists[0]->next = new ListNode(4);
    lists[0]->next->next = new ListNode(5);
 
    lists[1] = new ListNode(1);
    lists[1]->next = new ListNode(3);
    lists[1]->next->next = new ListNode(4);
 
    lists[2] = new ListNode(2);
    lists[2]->next = new ListNode(6);
    ListNode* root = mergeKLists(lists);
    print(root);
    return 0;
}