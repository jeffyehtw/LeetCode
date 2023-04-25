class Solution {
public:
    string frequencySort(string s) {
        string ret;
        vector<pair<char, int>> freq;

        for (int i = 0; i < 10; i++) {
            freq.push_back(make_pair('0' + i, 0));
        }
        for (int i = 0; i < 26; i++) {
            freq.push_back(make_pair('a' + i, 0));
        }
        for (int i = 0; i < 26; i++) {
            freq.push_back(make_pair('A' + i, 0));
        }
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                freq[s[i] - '0'].second++;
            } else if ((s[i] >= 'a') && (s[i] <= 'z')) {
                freq[s[i] - 'a' + 10].second++;
            } else {
                freq[s[i] - 'A' + 10 + 26].second++;
            }
        }
        sort(freq.begin(), freq.end(), [](pair<char, int> a, pair<char, int> b) {
            return a.second > b.second;
        });
        for (int i = 0; i < freq.size(); i++) {
            ret += string(freq[i].second, freq[i].first);
        }

        return ret;
    }
};
