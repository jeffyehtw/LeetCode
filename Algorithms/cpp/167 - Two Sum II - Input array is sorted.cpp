class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // var
        map<int, int> m;
        
        for (int i = 0; i < numbers.size(); i++) {
            if (m[target - numbers[i]] > 0)
                return vector<int>({ m[target - numbers[i]], i + 1 });
            m[numbers[i]] = i + 1;  
        }
        return vector<int>();
    }
};