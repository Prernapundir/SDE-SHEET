/*Use elementary math method , use carry and take it forward*/


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode *temp=new ListNode(),*ans=temp;
        
        while(l1||l2||carry){
            int value=carry;
            value+=l1?l1->val:0;
            value+=l2?l2->val:0;
            temp->next=new ListNode(value%10);
            carry=value/10;
            l1=l1?l1->next:NULL;
            l2=l2?l2->next:NULL;
            temp=temp->next;
        }
        
        return ans->next;
    }
};
