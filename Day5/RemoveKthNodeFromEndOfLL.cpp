/*
1. Move fast to n steps first
2. Move fast and slow simultaneously one step
*/


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode *fast=head,*slow=head;
      
       while(n--){
           fast=fast->next;
       }
        
        if(fast==nullptr) return head->next;
        
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};
