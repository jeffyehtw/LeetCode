class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ret = 0;

        sort(costs.begin(), costs.end());
        for (int i = 0; i < costs.size(); i++) {
            if (coins >= costs[i]) {
                ret++;
                coins -= costs[i];
            } else {
                break;
            }
        }

        return ret;
    }
};
