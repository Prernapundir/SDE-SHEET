/*
1. We can't delete the node.
2. But we can replce the node's data
*/


class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev;
        while(node->next){
            prev=node;
            node->val=node->next->val;
            node=node->next;
        }
        prev->next=NULL;
        delete(node);
        return;
    }
};
