class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (!n)
            result;
            
        recursive("", n, n);
        
        return result;
    }
    
    void recursive(string s, int left, int right) {
        if (!left && !right)
            result.push_back(s);
            
        if (left > 0)
            recursive(s + "(", left - 1, right);
        if (right > 0 && left < right)
            recursive(s + ")", left, right - 1);
    }
    
    // var
    vector<string> result;
};