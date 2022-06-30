class Solution {
public:
    string originalDigits(string s) {
        // var
        string result = "";
        vector<int> count(26, 0);
        vector<int> order{ 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 };
        vector<pair<char, string>> pattern {
            pair<char, string>('z', "zero"),
            pair<char, string>('w', "two"),
            pair<char, string>('u', "four"),
            pair<char, string>('x', "six"),
            pair<char, string>('g', "eight"),
            pair<char, string>('o', "one"),
            pair<char, string>('r', "three"),
            pair<char, string>('f', "five"),
            pair<char, string>('v', "seven"),
            pair<char, string>('i', "nine")
        };
        
        for (int i = 0; i < s.length(); i++)
            count[s[i] - 'a']++;
        
        for (int i = 0; i < 10; i++) {
            // var
            int n = count[pattern[i].first - 'a']; 
            for (int j = 0; j < pattern[i].second.length(); j++)
                count[pattern[i].second[j] - 'a'] -= n;
            result += string(n, char(order[i] + '0'));
        }
        
        sort(result.begin(), result.end());
        
        return result;
    }
};