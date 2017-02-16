class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // var
        vector<vector<int>> result;
        vector<pair<string, int>> v;
        
        if (n == 0)
            return result;
        
        // init
        v.push_back(pair<string, int>("0", 0));
        v.push_back(pair<string, int>("1", 1));
        
        // generate cases
        for (int i = 2; i <= n; i++) {
            // var
            int size = v.size();
                
            for (int j = 0; j < size; j++)
            if (v[j].second < k)
            v.push_back(pair<string, int>("1" + v[j].first, v[j].second + 1));
                
            for (int j = 0; j < size; j++)
                v[j].first = "0" + v[j].first;
            
            // remove impossible
            for (int j = 0; j < v.size();) {
                if (k - v[j].second > n - i)
                    v.erase(v.begin() + j);
                else
                    j++;
            }
        }
        
        // run
        for (int i = 0; i < v.size(); i++) {
            // var
            vector<int> tmp;
            
            if (v[i].second != k)
                continue;
            
            for (int j = 0; j < v[i].first.length(); j++)
            if (v[i].first[j] == '1')
                tmp.push_back(j + 1);
            
            result.push_back(tmp);
        }
        
        return result;
    }
};