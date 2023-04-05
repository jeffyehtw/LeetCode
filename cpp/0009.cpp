class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> arr;

        if (x < 0) {
            return false;
        }

        while (x > 0) {
            arr.push_back(x % 10);
            x /= 10;
        }

        for (int i = 0; i < arr.size() >> 1; i++) {
            if (arr[i] != arr[arr.size() - 1 - i]) {
                return false;
            }
        }

        return true;
    }
};