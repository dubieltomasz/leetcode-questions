class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* tmp = head;

        while(tmp != nullptr && tmp->next != nullptr)
        {
            head = head->next;
            tmp = tmp->next->next;
        }

        return head;
    }
};
