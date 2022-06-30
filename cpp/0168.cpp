class Solution {
public:
    string convertToTitle(int n) {
        // var
        string result;
        
        while (n) {
            n -= 1;
            result += 'A' + n % 26;
            n /= 26;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};