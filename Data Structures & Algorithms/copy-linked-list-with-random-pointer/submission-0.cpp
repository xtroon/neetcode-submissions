/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head) return nullptr;

        Node* newHead = new Node(head->val);
        
        unordered_map<Node*, Node*> hash;
        hash[head] = newHead; 

        Node* temp1 = head->next;
        Node* temp2 = newHead;

        while(temp1){
            Node* newNode = new Node(temp1->val);
            hash[temp1] = newNode;

            temp2->next = newNode;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        temp1 = head;
        temp2 = newHead;

        while(temp1){
            temp2->random = hash[temp1->random];

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return newHead;
    }
};