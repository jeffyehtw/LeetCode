class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ret = "";
        vector<string> s;
        int idx = 0;

        for (int i = 0; i < nums.size(); i++) {
            s.push_back(to_string(nums[i]));
        }
        sort(s.begin(), s.end(), [](string a, string b) {
            return (a + b) > (b + a);
        });
        for (int i = 0; i < s.size(); i++) {
            if ((ret == "") && (s[i] == "0")) {
                continue;
            }
            ret += s[i];
        }

        return (ret == "") ? "0" : ret;
    }
};
