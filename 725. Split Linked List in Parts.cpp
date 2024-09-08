class Solution {
public:
    std::vector<ListNode*> splitListToParts(ListNode* head, int k) {
        std::vector<ListNode*> answer;
        ListNode* tmp = head;
        int countOfNodes = 0;

        while(tmp)
        {
            ++countOfNodes;
            tmp = tmp->next;
        }

        if(countOfNodes > k)
        {
            int r = countOfNodes%k, q = countOfNodes/k;
            k -= r;

            while(r--)
            {
                answer.push_back(head);

                for(int i = 0; i < q; ++i)
                    head = head->next;

                tmp = head->next;
                head->next = nullptr;
                head = tmp;
            }

            while(k--)
            {
                answer.push_back(head);

                for(int i = 1; i < q; ++i)
                    head = head->next;

                tmp = head->next;
                head->next = nullptr;
                head = tmp;
            }
        }
        else
        {
            while(head)
            {
                answer.push_back(head);

                tmp = head->next;
                head->next = nullptr;
                head = tmp;
            }

            k -= countOfNodes;

            while(k--) answer.push_back(nullptr);
        }

        return answer;
    }
};
