class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int level = 1;
        int idx = 1;
        vector<int> table;
        vector<int> ret;

        table.push_back(0);
        table.push_back(1);
        while (table.size() - 1 < label) {
            int back = (1 << level) - 1;
            int len = (1 << level);

            if (level % 2 == 0) {
                for (int i = 0; i < len; i++) {
                    table.push_back(back + 1 + i);
                    if (table.back() == label) {
                        idx = table.size() - 1;
                    }
                }
            } else {
                for (int i = 0; i < len; i++) {
                    table.push_back(back + len - i);
                    if (table.back() == label) {
                        idx = table.size() - 1;
                    }
                }
            }

            level++;
        }

        while (idx > 0) {
            ret.insert(ret.begin(), table[idx]);
            idx /= 2;
        }

        return ret;
    }
};
