class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0)
            return vector<int>();
        
        // var
        vector<int> result(1, 1);
        
        // run
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = result.size() - 1; j > 0; j--)
                result[j] += result[j - 1];
            result.push_back(1);
        }
        return result;
    }
};