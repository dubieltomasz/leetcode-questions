class Solution {
public:
    int pairSum(ListNode* head) {
        std::array<int, 100001/2> values{};
        int maximum = 0, index = 0;
        ListNode* tail = head;

        while(tail != nullptr) {
            values[index++] = head->val;
            head = head->next;
            tail = tail->next->next;
        }

        while(head != nullptr) {
            maximum = std::max(maximum, values[--index] + head->val);
            head = head->next;
        }

        return maximum;
    }
};
