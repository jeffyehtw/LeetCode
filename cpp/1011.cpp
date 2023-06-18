class Solution {
private:
    int day(vector<int>& weights, int val) {
        int ret = 0;

        for (int i = 0; i < weights.size(); ) {
            int cap = val;
            
            while (i < weights.size()) {
                if (cap < weights[i]) {
                    break;
                } else {
                    cap -= weights[i];
                }
                i++;
            }
            ret++;
        }

        return ret;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0;
        int right = 1;
        vector<int> dp;

        for (int i = 0; i < weights.size(); i++) {
            left = max(left, weights[i]);
            right += weights[i];
        }
        dp = vector<int>(right + 1, INT_MAX);

        while (left <= right) {
            int mid = (left + right) / 2;
            
            dp[mid] = day(weights, mid);
            if (dp[mid] == days) {
                right = mid - 1;
            } else if (dp[mid] < days) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (left < right) {
            return (dp[left] <= days) ? left : right;
        } else {
            return (dp[right] <= days) ? right : left;
        }
    }
};
