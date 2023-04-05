class Solution {
public:
    int minTimeToType(string word) {
        int ret = 0;
        char pointer = 'a';

        for (int i = 0; i < word.length(); i++) {
            int go = word[i] - pointer;
            int back = pointer - word[i];

            go = (go < 0) ? go + 26 : go;
            back = (back < 0) ? back + 26 : back;

            ret += min(go, back);
            pointer = word[i];
        }

        ret += word.length();

        return ret;
    }
};
