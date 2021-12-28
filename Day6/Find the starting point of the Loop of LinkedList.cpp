/*
1.Firstly find the meeting point
2. Then start slow from start and fast from meeting point and move them one step ahead simultaneously to get entry point
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head or !head->next) return NULL;
        ListNode *fast=head,*slow=head,*start=head;
        
        while(fast->next and fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                while(start!=fast){
                   start=start->next;
                   fast=fast->next;
                }
                return start;
            }
        }
        return NULL;
    }
};
