class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ret = 0;
        int cnt = 1;

        if (tasks.size() <= 1) {
            return -1;
        }
        sort(tasks.begin(), tasks.end());
        for (int i = 1; i < tasks.size(); i++) {
            if (tasks[i - 1] != tasks[i]) {
                if (cnt == 1) {
                    return -1;
                } else {
                    ret += cnt / 3;
                    cnt %= 3;
                    ret += (cnt > 0) ? 1 : 0;
                }
                cnt = 1;
            } else {
                cnt++;
            }
        }
        if (cnt == 1) {
            return -1;
        } else {
            ret += cnt / 3;
            cnt %= 3;
            ret += (cnt > 0) ? 1 : 0;
        }

        return ret;
    }
};
