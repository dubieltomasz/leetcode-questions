class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int bottlesDrunk = numBottles;

        while(numBottles >= numExchange) {
            numBottles -= numExchange++ - 1;
            ++bottlesDrunk;
        }

        return bottlesDrunk;
    }
};
