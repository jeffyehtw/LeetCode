class Solution {
private:
    vector<string> ret;
    void _generateParenthesis(int left, int right, string s) {
        if ((left == 0) && (right == 0)) {
            ret.push_back(s);
            return;
        }

        if ((left < 0) || (right < 0) || (right < left)) {
            return;
        }

        _generateParenthesis(left - 1, right, s + "(");
        _generateParenthesis(left, right - 1, s + ")");
    }
public:
    vector<string> generateParenthesis(int n) {
        _generateParenthesis(n, n, "");
        return ret;
    }
};
