class Solution {
public:
    int findIntegers(int num) {
        if (num <= 2)
            return num + 1;
        
        // var
        int result = 1;
        
        helper(1, num, result);
        
        return result;
    }
    
    void helper(int val, int num, int& r) {
        if (val >= num) {
            r += val == num;
            return;
        }
        else {
            r++;
        }
    
        helper((val << 1), num, r);
        
        if (!(val & 1))
            helper((val << 1) + 1, num, r);
    }
};