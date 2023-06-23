class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> ret;
        queue<int> q;
        unordered_map<int, vector<int>> childs;

        for (int i = 0; i < ppid.size(); i++) {
            if (childs.find(ppid[i]) == childs.end()) {
                childs[ppid[i]] = vector<int>({ pid[i] });
            } else {
                childs[ppid[i]].push_back(pid[i]);
            }
        }

        q.push(kill);
        while (!q.empty()) {
            vector<int> child = childs[q.front()];

            for (int i = 0; i < child.size(); i++) {
                q.push(child[i]);
            }
            ret.push_back(q.front());
            q.pop();
        }

        return ret;
    }
};
