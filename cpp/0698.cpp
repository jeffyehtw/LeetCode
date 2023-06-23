class Solution {
private:
    int target = 0;
    unsigned int picked = 0;
    unordered_map<unsigned int, bool> umap;
    bool backtrack(vector<int>& nums, int k, int bucket, int idx) {
        bool ret = true;

        if (k == 0) {
            return ret;
        }
        if (bucket == target) {
            ret = backtrack(nums, k - 1, 0, 0);
            umap[picked] = ret;
            return ret;
        }
        if (umap.find(picked) != umap.end()) {
            return umap[picked];
        }
        for (int i = idx; i < nums.size(); i++) {
            if (((picked >> i) & 1) == 1) {
                continue;
            } else if (bucket + nums[i] > target) {
                continue;
            }
            picked |= (1 << i);
            if (backtrack(nums, k, bucket + nums[i], i + 1)) {
                return true;
            }
            picked &= ~(1 << i);
        }

        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        int max = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            max = (nums[i] > max) ? nums[i] : max;
        }
        target = sum / k;
        if ((sum % k > 0) || (max > target)) {
            return false;
        } else {
            return backtrack(nums, k, 0, 0);
        }
    }
};
