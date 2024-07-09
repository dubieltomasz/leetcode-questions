class Solution {
public:
    double averageWaitingTime(const std::vector<std::vector<int>>& customers) {
        long sum = 0;
        int idleSince = 0;

        for(const std::vector<int>& customer : customers)
        {
            if(customer[0] > idleSince)
            {
                sum += customer[1];
                idleSince = customer[0] + customer[1];
            }
            else
            {
                sum += customer[1] + idleSince - customer[0];
                idleSince += customer[1];
            }
        }

        return (double)sum / customers.size();
    }
};
