class Solution {
public:
    int robotSim(std::vector<int>& commands, const std::vector<std::vector<int>>& obstacles) {
        int direction = 0, x = 0, y = 0, answer = 0;
        std::set<std::pair<int, int>> s;

        for(const std::vector<int>& obstacle : obstacles)
            s.insert({obstacle[0], obstacle[1]});

        for(int& k : commands)
        {
            if(k == -1) direction = (direction+1) & ~4;
            else if(k == -2) direction = (direction+3) & ~4;
            else
            {
                switch(direction)
                {
                    case 0:
                        do ++y;
                        while(k-- && s.find({x,y}) == s.end());
                        
                        --y;
                        break;
                    case 1:
                        do ++x;
                        while(k-- && s.find({x,y}) == s.end());
                        
                        --x;
                        break;
                    case 2:
                        do --y;
                        while(k-- && s.find({x,y}) == s.end());
                        
                        ++y;
                        break;
                    default:
                        do --x;
                        while(k-- && s.find({x,y}) == s.end());
                        
                        ++x;
                        break;
                }

                answer = std::max(answer, x*x+y*y);
            }            
        }

        return answer;
    }
};
