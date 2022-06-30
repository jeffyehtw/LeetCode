class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // var
        int n = nums.size();
        vector<vector<int>> result;
        
        if (n < 4)
            return result;
        
        // init
        sort(nums.begin(), nums.end());
        
        // run
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                    continue;
                    
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                
                // var
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    // var
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        result.push_back({ nums[i], nums[j], nums[left], nums[right] });
                        left++;
                        right--;
                        
                        // shift
                        while (left < right && nums[left - 1] == nums[left])
                            left++;
                        while (right > left && nums[right] == nums[right + 1])
                            right--;
                    }
                    else if (sum > target)
                        right--;
                    else
                        left++;
                }
            }
        }
        return result;
    }
};