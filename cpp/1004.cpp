class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = -1;
        int right = 0;
        int ret = 0;
        int cnt = 0;
        vector<int> flip;

        while (right < nums.size()) {
            if (nums[right] == 1) {
                cnt++;
                if (left == -1) {
                    left = right;
                }
            } else if (k > flip.size()) {
                flip.push_back(right);
                cnt++;
                if (left == -1) {
                    left = right;
                }
            } else {
                if (k == 0) {
                    cnt = 0;
                    left = -1;
                } else {
                    cnt -= flip[0] - left;
                    left = flip[0] + 1;
                    flip.erase(flip.begin());
                    flip.push_back(right);
                }
            }
            if (left > -1) {
                ret = max(ret, right - left + 1);
            }
            right++;
        }

        return ret;
    }
};
