class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* tmp1 = head;

        while(tmp1->next)
        {
            ListNode* tmp2 = new ListNode(std::gcd(tmp1->val, tmp1->next->val), tmp1->next);
            tmp1->next = tmp2;
            tmp1 = tmp1->next->next;
        }

        return head;
    }
};
