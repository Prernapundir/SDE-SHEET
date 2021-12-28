/*Recursive Approach
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if(!head || !head->next) return head;
       ListNode* node=reverseList(head->next);
       head->next->next=head;
       head->next=NULL;
       return node;
    }
};


/*Iterative Approach
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    
      ListNode *curr=head,*next, *prev=NULL;
        
      while(curr){
          next=curr->next;
          curr->next=prev;
          prev=curr;
          curr=next;
      }
      return prev;
    }
};
