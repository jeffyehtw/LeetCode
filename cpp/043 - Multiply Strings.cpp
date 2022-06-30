class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
            
        // var
        int m = num1.length();
        int n = num2.length();
        string result(m + n, 0);
        
        // multiply
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                result[i + j] += (num1[m - 1 - j] - '0') * (num2[n - 1 - i] - '0');
            result = carry(result);
        }
        
        // format
        result = format(result);
        while(result.back() == '0')
            result.pop_back();
        reverse(result.begin(), result.end());
        
        return result;
    }
    
    string carry(string num) {
        // var
        int n = num.length();
        
        for (int i = 0; i < n - 1; i++) {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
        return num;
    }
    
    string format(string num) {
        for (int i = 0; i < num.length(); i++)
            num[i] += '0';
        return num;
    }
};