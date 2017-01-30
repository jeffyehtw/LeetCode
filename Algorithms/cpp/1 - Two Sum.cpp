class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // var
        map<int, int> m;
        vector<int> temp;
        
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end()) {
        		temp.push_back(m[nums[i]]);
        		temp.push_back(i);
        		break;
        	}
        	m[target - nums[i]] = i;
        }
        return temp;
    }
};