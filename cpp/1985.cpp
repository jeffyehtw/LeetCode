class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), [](string a, string b) {
            if (a.length() != b.length()) {
                return a.length() > b.length();
            } else if (a == b) {
                return a < b;
            }

            for (int i = 0; i < a.length(); i++) {
                if (a[i] > b[i]) {
                    return a > b;
                }
            }
            return false;
        });

        return nums[k - 1];
    }
};
