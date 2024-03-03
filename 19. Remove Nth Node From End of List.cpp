class Solution {
private:
    void removeNode(ListNode* node, const int& n, int current)
    {
        if(n == current)
        {
            node->next = node->next->next;
        }
        else removeNode(node->next, n, current+1);
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, const int& n) {
        int k = 0;

        ListNode* tmp = head;
        while(tmp)
        {
            ++k;
            tmp = tmp->next;
        }

        k -= n;

        if(k == 0) return head->next;
        else
        {
            removeNode(head, k, 1);
        
            return head;
        }
    }
};
