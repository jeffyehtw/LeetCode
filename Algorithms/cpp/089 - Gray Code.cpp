class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0)
            return vector<int>({ 0 });
        
        // var
        int index = 1;
        int m = 1 << n;
        vector<int> result({ 0, 1 });
        
        while (result.size() < m) {
            // var
            int tmp = result[index] << 1;
            
            if (index & 1) {
                result.push_back(tmp + 1);
                result.push_back(tmp);
            }
            else {
                result.push_back(tmp);
                result.push_back(tmp + 1);
            }
            index++;
        }
        return result;
    }
};