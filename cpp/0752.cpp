class Solution {
private:
    string up(string s, int idx) {
        s[idx] = (s[idx] - '0' + 1) % 10;
        s[idx] += '0';
        return s;
    }
    string down(string s, int idx) {
        s[idx] = (s[idx] - '0' - 1 + 10) % 10;
        s[idx] += '0';
        return s;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        string cur;
        queue<string> q;
        unordered_map<string, bool> visited;
        int step = 0;

        for (int i = 0; i < deadends.size(); i++) {
            visited[deadends[i]] = true;
        }
        if (visited["0000"]) {
            return -1;
        }

        q.push("0000");
        visited["0000"] = true;
        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                cur = q.front();
                if (cur == target) {
                    return step;
                }
                for (int j = 0; j < 4; j++) {
                    string s = up(cur, j);
                    if (visited.find(s) == visited.end()) {
                        q.push(s);
                        visited[s] = true;
                    }
                    s = down(cur, j);
                    if (visited.find(s) == visited.end()) {
                        q.push(s);
                        visited[s] = true;
                    }
                }
                q.pop();
            }
            step++;
        }

        return -1;
    }
};
