/*
1. Firstly find the middle of ll (using tortoise method}
2. Then reverse from the mid 
3. Then one pointer will start from start and next from mid ->next and then compare

*/


class Solution {
public:
    ListNode* Middle(ListNode* head){
        ListNode *fast=head,*slow=head;
        while(fast->next and fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        if(!head->next or !head) return head;
        ListNode* node=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return node;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head->next) return head;
        ListNode *p1=head,*p2;
        ListNode *mid=Middle(head);
              
        mid->next=reverse(mid->next);
        p2=mid->next;       
        while(p1 and  p2){
            if(p1->val!=p2->val) return false;
            p1=p1->next;
            p2=p2->next;
        }
        return true;
    }
};
