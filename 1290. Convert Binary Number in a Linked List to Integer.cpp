class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int decimal = 0;

        while(head)
        {
            decimal <<= 1;
            decimal += head->val;
            head = head->next;
        }

        return decimal;
    }
};
