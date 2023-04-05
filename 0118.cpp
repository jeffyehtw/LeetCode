class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // var
        vector<int> tmp;
        vector<vector<int>> result;
        
        // run
        for (int i = 0; i < numRows; i++) {
            // add
            for (int j = 0; j < i + 1; j++)
                tmp.push_back((j == 0 || j == i) ? 1 : result[i - 1][j - 1] + result[i - 1][j]);
            result.push_back(tmp);
            tmp.clear();
        }
        return result;
    }
};