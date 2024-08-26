class Solution {
public:
    std::vector<int> postorder(Node* root) {
        if(root) func(root);

        return g;
    }

private:
    std::vector<int> g;
    
    void func(Node* n)
    {
        if(!n->children.empty())
            for(Node* N : n->children) func(N);

        g.push_back(n->val);
    }
};
