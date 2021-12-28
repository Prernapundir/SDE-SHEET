/*
1. Same reverse logic apply in groups */
*/


class Solution {
public:
    ListNode* reverse(ListNode* head,int k,int t){
        if(t>=k-1 or !head or  !head->next) return head;
        t++;
        ListNode* node=reverse(head->next,k,t);
        head->next->next=head;
        head->next=NULL;
        return node;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        
        for(int i=0;i<k;i++){
            if(!temp) return head;
            temp=temp->next;
        }
        ListNode* node=reverse(head,k,0);
        head->next=reverseKGroup(temp,k);
        return node;
    }
};
