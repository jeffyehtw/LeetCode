class Solution {
public:
    string intToRoman(int num) {
        string ret;
        vector<pair<int, string>> map = {
            { 1000, "M" },
            { 900, "CM" },
            { 500, "D" },
            { 400, "CD" },
            { 100, "C" },
            { 90, "XC" },
            { 50, "L" },
            { 40, "XL" },
            { 10, "X" },
            { 9, "IX" },
            { 5, "V" },
            { 4, "IV"},
            { 1, "I" }
        };

        for (int i = 0; i < map.size() && num > 0; i++) {
            if (num >= map[i].first) {
                for (int j = 0; j < num / map[i].first; j++) {
                    ret += map[i].second;
                }
            }
            num %= map[i].first;
        }

        return ret;
    }
};
