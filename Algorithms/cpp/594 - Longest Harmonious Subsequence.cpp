class Solution {
public:
    int findLHS(vector<int>& nums) {
        // var
        int result = 0;
        map<int, int> m;
    
        // init
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]]++;
        
        for (int i = 0; i < nums.size(); i++) {
            // var
            int less = m[nums[i] - 1];
            int greater = m[nums[i] + 1];
            int equal = m[nums[i]];
            
            if (less == 0 && greater == 0)
                continue;
            
            result = max(result, max(less, greater) + equal);            
        }
        return result;
    }
};