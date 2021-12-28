/*Iterative with space*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
      if(!l1) return l2;
      if(!l2) return l1;
        
      ListNode * ans=new ListNode();
      ListNode * temp=ans;
        
        while(l1 and l2){
            if(l1->val>l2->val){
                temp->next=l2;
                l2=l2->next;
            }else{
                temp->next=l1;
                l1=l1->next;
            }
            temp=temp->next;
        }
       if(l1)temp->next=l1;
       if(l2)temp->next=l2;

        return ans->next;
    }
};


/*Recursive (In-place)*/


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1->val>l2->val){
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }else{
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }    
    }
};
