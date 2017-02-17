class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        // var
        map<int, int> m;
        vector<int> tmp(nums);
        vector<string> result;
        
        // pre
        sort(tmp.begin(), tmp.end());
        
        // init
        for (int i = 0; i < tmp.size(); i++)
            m[tmp[i]] = tmp.size() - i;

        // run
        for (int i = 0; i < nums.size(); i++) {
            // var
            int rank = m[nums[i]];
            
            // cases
            switch (rank) {
                case 1:
                    result.push_back("Gold Medal");
                    break;
                case 2:
                    result.push_back("Silver Medal");
                    break;
                case 3:
                    result.push_back("Bronze Medal");
                    break;
                default:
                    result.push_back(int_to_str(rank));
                    break;
            }
        }
        return result;
    }
    
    string int_to_str(int num) {
        // var
        string result;
        while (num) {
            result = char((num % 10) + '0') + result;
            num /= 10;
        }
        return result;
    }
};