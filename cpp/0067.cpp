class Solution {
public:
    string addBinary(string a, string b) {
        // var
        string result;
        int len = max(a.length(), b.length()) + 1;
        
        for (int i = 0; i < len; i++) {
            if (a.length() < len)
                a.insert(0, "0");
            if (b.length() < len)
                b.insert(0, "0");
            result.append("0");
        }
         
        int carry = 0;  
        for (int i = 0; i < len; i++) {
            int temp = a[len - 1 - i] + b[len - 1 - i] + carry - '0' * 2;
            carry = temp / 2;
            result[len - 1 - i] = '0' + (temp % 2); 
        }
        
        if (result[0] == '0')
            result.erase(0, 1);
        return result;
    }
};