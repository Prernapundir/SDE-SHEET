/*
-->Brute Force:Take last node nad appen at the front of linked list
, time complexity would be O(k*n)
--> Optimal Approach: Make list circular and iterate list from stat and break the ring at k-len 
*/

class Solution {
public:
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or k==0) return head;
        
        int len=1;
        ListNode *temp=head;
        // compute length of linked list
        while(temp->next){
            temp=temp->next;
            len++;
        }
        
        k=len-k%len;
      // make linked list circular , put head in last node next
        temp->next=head;
        
      // now move temp to k steps 
        while(k--){
            temp=temp->next;
        }
      // break the ring now
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};
