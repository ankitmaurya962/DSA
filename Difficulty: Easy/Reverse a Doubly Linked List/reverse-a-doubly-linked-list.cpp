/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        
        Node *curr = head;
        Node* prevHead = NULL;
        while(curr!=NULL){
            Node *previ = curr->prev;
            Node* nexti = curr->next;
            
            //swap
            Node *temp = previ;
            curr->prev = nexti;
            curr->next = temp;
            
            prevHead = curr;
            curr = nexti;
        }
        
        return prevHead;
    }
};