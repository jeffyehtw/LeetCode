class Solution {
public:
    vector<int> countBits(int num) {
        // var
        vector<int> result;
        
        for (int i = 0; i <= num; i++) {
            // var
            int temp = i;
            int count = 0;
            
            while (temp) {
                count += temp & 1;
                temp >>= 1;
            }
            result.push_back(count);
        }
        
        return result;
    }
};