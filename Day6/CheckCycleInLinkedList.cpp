/*Tortoise method*/



class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head or !head->next) return false;
        ListNode *slow=head,*fast=head->next;
        
        while(fast and fast->next){
            if(fast==slow) return true;
            fast=fast->next->next;
            slow=slow->next;
        }
        return false;
    }
}
