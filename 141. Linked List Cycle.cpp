class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;

        ListNode* head2 = head;

        while(head2->next != nullptr && head2->next->next != nullptr)
        {
            head2 = head2->next->next;
            head = head->next;

            if(head2 == head) return true;
        }

        return false;
    }
};
