class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* tmp = new ListNode();
        ListNode* answer = tmp;

        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                tmp->next = list1;
                list1 = list1->next;
                tmp = tmp->next;
            }
            else
            {
                tmp->next = list2;
                list2 = list2->next;
                tmp = tmp->next;
            }
        }

        if(list1) tmp->next = list1;
        if(list2) tmp->next = list2;

        return answer->next;
    }
};
