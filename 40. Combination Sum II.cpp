class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target){
        std::sort(candidates.begin(), candidates.end());

        func(candidates, target, 0);

        return answer;
    }

private:
    std::vector<std::vector<int>> answer;
    std::vector<int> combination;

    void func(std::vector<int>& candidates, int target, int index)
    {
        if(!target)
        {
            answer.push_back(combination);
            return;
        }

        for(int i = index; i < candidates.size() && target >= candidates[i]; ++i)
        {
            if(i == index || candidates[i] != candidates[i-1])
            {
                combination.push_back(candidates[i]);

                func(candidates, target-candidates[i], i+1);

                combination.pop_back();
            }
        }
    }
};
