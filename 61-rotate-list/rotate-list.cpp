/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* secondLastNode(ListNode* temp){
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        return temp;
    }
    int LengthListNode(ListNode* head){
        ListNode* temp=head;
        int length=1;
        while(temp->next!=NULL){
            length++;
            temp=temp->next;
            
        }
        return length;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int rotation=k%LengthListNode(head);
        int count=0;
        while(count!=rotation){
            count++;
            ListNode* last=secondLastNode(head)->next;
            ListNode* secondLast=secondLastNode(head);
            last->next=head;
            head=last;
            secondLast->next=NULL;
        }
        return head;
    }
};