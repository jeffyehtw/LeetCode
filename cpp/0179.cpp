bool compare(string x, string y) {
    return x + y > y + x;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // var
        vector<string> v;
        int n = nums.size();
        
        // init
        for (int i = 0; i < n; i++)
            v.push_back(to_string(nums[i]));
        
        sort(v.begin(), v.end(), compare);
        
        return format(v);
    }
    
    string format(vector<string> v) {
        // var
        string result;
        for (int i = 0; i < v.size(); i++)
            result += v[i];
        
        // avoid "00"
        while (result[0] == '0' && result.length() > 1)
            result.erase(result.begin());
            
        return result;
    }
};