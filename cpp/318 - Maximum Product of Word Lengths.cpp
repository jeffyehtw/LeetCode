class Solution {
public:
    int maxProduct(vector<string>& words) {
        // var
        int result = 0;
        int n = words.size();
        vector<int> v(words.size(), 0);
        
        // init
        for (int i = 0; i < n; i++)
        for (int j = 0; j < words[i].length(); j++)
            v[i] |= 1 << (words[i][j] - 'a');

        // run
        for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            if (v[i] & v[j])
                continue;
            
            int tmp = words[i].length() * words[j].length();
            result = max(result, tmp);
        }
        return result;
    }
};