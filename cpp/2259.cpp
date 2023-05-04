class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<string> nums;
        int n = number.length();

        for (int i = 0; i < number.length(); i++) {
            if (number[i] == digit) {
                string left = string(number, 0, i);
                string right = string(number, i + 1, n - i + 1);
                nums.push_back(left + right);
            }
        }
        sort(nums.begin(), nums.end(), [](string a, string b) {
            return (a + b) < (b + a);
        });

        return (nums.size() == 0) ? number : nums.back();
    }
};
