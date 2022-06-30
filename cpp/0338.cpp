class Solution {
public:
    vector<int> countBits(int num) {            
        // var
        vector<int> result({ 0, 1, 1 });
        
        if (num < 3)
            return vector<int>(result.begin(), result.begin() + num + 1);
        
        for (int i = 3; i <= num; i++)
            result.push_back(result[i >> 1] + (i & 1));
        
        return result;
    }
};