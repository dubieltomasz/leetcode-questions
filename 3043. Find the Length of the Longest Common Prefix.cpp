class Solution {
public:
    int longestCommonPrefix(const std::vector<int>& arr1, const std::vector<int>& arr2) {
        node* tree = new node();
        
        for(int i : arr1)
        {
            int tmp = 1;

            while(i)
            {
                tmp = tmp*10 + i%10;
                i /= 10;
            }

            addNode(tree, tmp);
        }

        for(int i : arr2)
        {
            int tmp = 1;

            while(i)
            {
                tmp = tmp*10 + i%10;
                i /= 10;
            }

            countPrefix(tmp, tree, 0);
        }

        return answer;
    }

private:
    int answer = 0;

    struct node{
        node* next[10];

        node()
        {
            for(int i = 0; i < 10; ++i)
                next[i] = nullptr;
        }
    };

    void addNode(node* tree, int x)
    {
        if(x == 1) return;

        if(!tree->next[x%10])
            tree->next[x%10] = new node();

        addNode(tree->next[x%10], x/10);
    }

    void countPrefix(int x, node* tree, int depth)
    {
        answer = std::max(answer, depth);

        if(x>1 && tree->next[x%10])
            countPrefix(x/10, tree->next[x%10], depth+1);
    }
};
