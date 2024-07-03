class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* answer = nullptr;
        ListNode* tmp;

        while(head)
        {
            tmp = head;
            head = head->next;
            
            tmp->next = answer;
            answer = tmp;
        }

        return answer;
    }
};
