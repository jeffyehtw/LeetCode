class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // var
        int n = nums.size();
        int result = nums[0] + nums[1] + nums[2];
        
        // init
        sort(nums.begin(), nums.end());
        
        // run
        for (int i = 0; i < n - 2; i++) {
            // var
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                // var
                int sum = nums[i] + nums[left] + nums[right];
                
                if(abs(target - sum) < abs(target - result))
                    result = sum;
                    
                if (result == target)
                    return result;
                
                sum > target ? right-- : left++;
            }
        }
        return result;
    }
};