class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head)
        {
            ListNode* node = head;

            while(node->next)
            {
                if(node->next->val == node->val)
                {
                    ListNode* tmp = node->next;
                    node->next = node->next->next;
                    delete tmp;
                }
                else node = node->next;
            }
        }

        return head;
    }
};
