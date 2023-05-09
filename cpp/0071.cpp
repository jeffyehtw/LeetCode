class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        string cur = "";
        string ret = "";
        int start = 1;
        int len = 0;

        for (int i = 1; i < path.length(); i++) {
            if (path[i] == '/') {
                cur = string(path, start, len);
                if (cur == "..") {
                    if (v.size() > 0) {
                        v.pop_back();
                    }
                } else if ((cur.length() > 0) && cur != ".") {
                    v.push_back(cur);
                }
                start = i + 1;
                len = 0;
                cur = "";
            } else {
                len++;
            }
        }
        cur = string(path, start, len);
        if ((cur == "..") && (v.size() > 0)) {
            v.pop_back();
        } else if ((cur != "..") && (cur != ".") && (len > 0)) {
            v.push_back(cur);
        }
        
        for (int i = 0; i < v.size(); i++) {
            ret += "/" + v[i];
        }

        return (ret.length() == 0) ? "/" : ret;
    }
};
