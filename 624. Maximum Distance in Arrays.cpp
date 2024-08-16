class Solution {
public:
    int maxDistance(const std::vector<std::vector<int>>& arrays) {
        int smallest[4] = {0,arrays[0].front(),1,arrays[1].front()}, largest[4] = {0,arrays[0].back(),1,arrays[1].back()}, answer = 0;

        for(int i = 2; i < arrays.size(); ++i)
        {
            if(arrays[i].front() < smallest[1])
            {
                smallest[1] = arrays[i].front();
                smallest[0] = i;
            }
            else if(arrays[i].front() < smallest[3])
            {
                smallest[3] = arrays[i].front();
                smallest[2] = i;
            }

            if(arrays[i].back() > largest[1])
            {
                largest[1] = arrays[i].back();
                largest[0] = i;
            }
            else if(arrays[i].back() > largest[3])
            {
                largest[3] = arrays[i].back();
                largest[2] = i;
            }
        }

        if(smallest[0] != largest[0])
            answer = std::max(answer, largest[1] - smallest[1]);

        if(smallest[0] != largest[2])
            answer = std::max(answer, largest[3] - smallest[1]);

        if(smallest[2] != largest[0])
            answer = std::max(answer, largest[1] - smallest[3]);

        if(smallest[2] != largest[2])
            answer = std::max(answer, largest[3] - smallest[3]);

        return answer;
    }
};
