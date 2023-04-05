class Solution {
public:
    string countAndSay(int n) {
        // var
        string result = "1";
        
        for (int i = 1; i < n; i++) {
            // var
            string tmp = "";
            int len = result.length();
            
            for (int j = 0; j < len; ) {
                // var
                int index = j + 1;
                
                // count
                while (index < len && result[j] == result[index])
                    index++;
    
                tmp += to_string(index - j) + result[j];
                j = index;
            }
            result = tmp;
        }
        return result;
    }
};