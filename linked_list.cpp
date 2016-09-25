#include <bits/stdc++.h>

using namespace std;
class Node{
    public:
        Node* next = nullptr;
        int value;
        
        Node(int d){
            value = d;
        }
        
        Node* append(int new_d){
            Node *n = this;
            while(n->next != nullptr){
                n = n->next;
            }
            n->next = new Node(new_d);
            return n->next;
        }
};

void printList(Node *head){
    Node *n = head;
    while(n != nullptr){
        cout << n->value << ", ";
        n = n->next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(0); // Points to the first node of linked list
    for(int i = 1; i < 5; i++){
        head->append(i*i);
    }
    
    printList(head);
    return 0;
}