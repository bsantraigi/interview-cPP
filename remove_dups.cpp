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

Node* remove(Node* head, int value){
    Node *n = head;
    if(n->value == value){
        return head->next;
    }
    
    while(n->next != nullptr){
        
        if(n->next->value == value){
            n->next = n->next->next;
            return n;
        }
        n = n->next;
    }
    return nullptr;
}

int main(){
    Node* head = new Node(5); // Points to the first node of linked list
    int nums[] = {5, 4, 0, 6, 4, 5, 5, 9, 0};
    int N = 9;
    for(int i = 1; i < N; i++){
        head->append(nums[i]);
    }
    
    printList(head);
    
    Node* ptFix = head;
    while(ptFix!=nullptr){
        Node* temp = ptFix->next;
        while(temp != nullptr){
            temp = remove(temp, ptFix->value);
        }
        ptFix = ptFix->next;
    }
    
    printList(head);
    
    return 0;
}
