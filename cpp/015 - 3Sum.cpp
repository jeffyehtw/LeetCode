class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // var
        int n = nums.size();
        vector<vector<int>> result;
        
        if (n < 3)
            return result;
        
        // init
        sort(nums.begin(), nums.end());
        
        // run
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
                
            // var
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                // var
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({ nums[i], nums[left], nums[right] });
                    left++;
                    right--;
                    
                    // shift
                    while (left < right && nums[left - 1] == nums[left])
                        left++;
                    while (right > left && nums[right] == nums[right + 1])
                        right--;
                }
                else if (sum > 0)
                    right--;
                else
                    left++;
            }
        }
        return result;
    }
};