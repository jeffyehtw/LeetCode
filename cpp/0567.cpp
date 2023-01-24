class Solution {
private:
    bool compare(const int t1[], const int t2[]) {
        for (int i = 0; i < 256; i++) {
            if (t1[i] != t2[i]) {
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int t1[256] = { 0 };
        int t2[256] = { 0 };

        if (s1.length() > s2.length()) {
            return false;
        }

        for (int i = 0; i < s1.length(); i++) {
            t1[s1[i]]++;
            t2[s2[i]]++;
        }

        if (compare(t1, t2)) {
            return true;
        }

        for (int i = s1.length(), j = 0; i < s2.length(); i++, j++) {
            t2[s2[i]]++;
            t2[s2[j]]--;

            if (compare(t1, t2)) {
                return true;
            }
        }

        return false;
    }
};