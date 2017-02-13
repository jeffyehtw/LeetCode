class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // var
        map<int, int> m;
        vector<int> result;
        
        for (int i = 0; i < numbers.size(); i++) {
            if (m.find(numbers[i]) != m.end()) {
                result.push_back(m[numbers[i]] + 1);
                result.push_back(i + 1);
                break;
            }
            else {
                m[target - numbers[i]] = i;
            }
        }
        return result;
    }
};