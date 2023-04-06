class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> acc(cost.size(), n);

        acc[0] = cost[0];
        acc[1] = cost[1];
        for (int i = 2; i < n; i++) {
            acc[i] = min(acc[i - 1], acc[i - 2]) + cost[i];
        }

        return min(acc[n - 1], acc[n - 2]);
    }
};
