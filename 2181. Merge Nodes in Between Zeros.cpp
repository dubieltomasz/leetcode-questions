class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* anchor = head, *node = head->next;

        while(node->next)
        {
            while(node->val)
            {
                anchor->val += node->val;
                node = node->next;
            }

            if(node->next)
            {
                anchor = anchor->next;
                anchor->val = 0;
                node = node->next;
            }
        }
        
        anchor->next = nullptr;
        
        return head;
    }
};
