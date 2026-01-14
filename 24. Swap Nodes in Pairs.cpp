class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* pointer = new ListNode(0, head);
        ListNode* tmp = pointer;

        while(tmp->next != nullptr && tmp->next->next != nullptr) {
            ListNode* tmp2 = tmp->next->next->next;

            tmp->next->next->next = tmp->next;
            tmp->next = tmp->next->next;
            tmp->next->next->next = tmp2;

            tmp = tmp->next->next;
        }

        tmp = pointer->next;
        delete pointer;

        return tmp;
    }
};
