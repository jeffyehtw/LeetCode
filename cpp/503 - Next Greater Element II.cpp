class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // var
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            // var
            int index = (i + 1) % nums.size();
            
            while (index != i && nums[index] <= nums[i]) 
                index = (index + 1) % nums.size();
            result.push_back(index == i ? -1 : nums[index]);
        }
        return result;
    }
};