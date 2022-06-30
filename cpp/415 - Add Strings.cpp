class Solution {
public:
    string addStrings(string num1, string num2) {
        // var
        int m = num1.length() - 1;
        int n = num2.length() - 1;
        string result(max(m, n) + 2, 0);
        int index = result.length() - 1;
        
        while (m > -1 || n > -1) {
            // var
            int a = m > -1 ? num1[m] - '0' : 0;
            int b = n > -1 ? num2[n] - '0' : 0;
            result[index] += a + b;
            result[index - 1] = result[index] / 10;
            result[index] %= 10;
            result[index] = char(result[index] + '0');
            
            m--;
            n--;
            index--;
        }
        
        if (result[0] == 0)
            result.erase(result.begin());
        else
            result[0] += '0';
        
        return result;
    }
};