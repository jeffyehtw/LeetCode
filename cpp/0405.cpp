class Solution {
public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        
        // var
        string result;
        map<int, char> m;
        bool non_zero = false;
        
        // init
        for (int i = 0; i < 10; i++)
            m[i] = '0' + i;
        for (int i = 10; i < 16; i++)
            m[i] = 'a' + i - 10;
            
        // to binary
        vector<int> bin = toBin(num);
        
        for (int i = 0; i < 8; i++) {
            // var
            int sum = 0;
            for (int j = 0; j < 4; j++) {
                sum *= 2;
                sum += bin[i * 4 + j];
            }
            if (sum > 0)
                non_zero = true;
            if (non_zero)
                result += m[sum];
        }
        return result;
    }
    
    vector<int> toBin(long num) {
        // var
        vector<int> result;
        bool non_zero = false;
        bool is_negative = num < 0;
        
        // init
        if (is_negative)
            num *= -1;
        
        while (num) {
            result.push_back(num % 2);
            num /= 2;
        }
        
        // fix
        while (result.size() < 32)
            result.push_back(0);
        
        if (is_negative) {
            for (int i = 0; i < result.size(); i++) {
                if (!non_zero && result[i]) {
                    non_zero = true;
                    continue;
                }
                if (non_zero)
                    result[i] = result[i] != 1;
            }
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
};