/*Approach

==>Brute Force {Start from one linked list and check for evey nodeof linked list 2 , if find anyone is same return taht node}
==> Optimal one { Start from both nodes parelly , and reverse start node once reach end ,next time they will definitely meet at same node}

*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1=headA,*l2=headB,*ans;
        int c1=0,c2=0;
        while(l1 and l2){
            if(c1==1 and c2==1 and l1==l2){
                ans=l2;
                break;
            }
            l1=l1->next;
            l2=l2->next;
            if(l1==NULL and c1==0){
                l1=headB;
                c1=1;
            }
            if(l2==NULL and c2==0){
                l2=headA;
                c2=1;
            }
        }
        return ans?ans:NULL;
    }
};
