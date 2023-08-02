class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        priority_queue<pair<int, char>> pq;
        vector<int> cnt(26, 0);
        string ret(n, '0');

        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
        }
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] == 0) {
                continue;
            }
            pq.push({ cnt[i], 'a' + i });
        }
        
        for (int i = 0; (i < n) && (!pq.empty()); i++) {
            pair<int, char> cur = pq.top();
            pair<int, char> tmp;
            
            pq.pop();
            if ((i > 0) && (ret[i - 1] == cur.second)) {
                if (pq.empty()) {
                    return "";
                }
                tmp = cur;
                cur = pq.top();
                pq.pop();
                pq.push(tmp);      
            }
            ret[i] = cur.second;
            cur.first--;
            if (cur.first > 0) {
                pq.push(cur);
            }
        }

        return ret;
    }
};
