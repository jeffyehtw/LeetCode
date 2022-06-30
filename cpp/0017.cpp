class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // var
        vector<string> result{ "" };
        vector<string> v = { 
            "", "", "abc", "def", "ghi", 
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        if (digits == "")
            return vector<string>();
        
        // run
        for (int i = 0; i < digits.length(); i++) {
            // var
            int n = result.size();
            int index = digits[i] - '0';
            
            // generate
            for (int j = 0; j < n; j++)
            for (int k = 0; k < v[index].length(); k++)
                result.push_back(result[j] + v[index][k]);
             
            // remove old
            result.assign(result.begin() + n, result.end());
        }
        return result;
    }
};