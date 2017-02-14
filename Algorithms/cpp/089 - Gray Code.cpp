class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0)
            return vector<int>{ 0 };
            
        // var
        vector<int> result;
        vector<string> grays{ "0", "1" };
        
        // generate gray
        for (int i = 2; i <= n; i++) {
            // var
            int size = grays.size();
                
            for (int j = size - 1; j > -1; j--)
                grays.push_back("1" + grays[j]);
                
            for (int j = 0; j < size; j++)
                grays[j] = "0" + grays[j];
        }
        
        // format
        for (int i = 0; i < grays.size(); i++)
            result.push_back(binary_to_dec(grays[i]));
        
        return result;
    }
    
    int binary_to_dec(string s) {
        // var
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            result *= 2;
            result += s[i] - '0';
        }
        return result;
    }
};